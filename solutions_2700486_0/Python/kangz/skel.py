import sys
import math

def concat_str(args):
    s = ""
    for arg in args:
        s += str(arg)
    return s

def debug(*args):
    sys.stderr.write(concat_str(args) + "\n")

def printf(*args):
    debug(*args)
    print concat_str(args)

def int_input():
    return map(int, raw_input().split(' '))


#######################################################
def nCr(n,r):
    return math.factorial(n) / math.factorial(r) / math.factorial(n-r)

def read_input(        ):
    N, X, Y = int_input()
    return N, X, Y

def solve(N, X, Y):
    X = abs(X)
    dist = (X + Y) / 2

    for i in range(dist):
        N -= 1 + 4*i

    if N <= Y:
        return 0.0
    if N >= dist * 2 + Y + 1:
        return 1.0

    if X == 0:
        return solve_for_vertical(Y, N)

    return solve_filled(dist, Y, N)

def solve_for_vertical(Y, N):
    if Y * 2 + 1 <= N:
        return 1.0
    else:
        return 0.0

def solve_filled(dist, Y, N):
    s = 0
    for i in range(Y + 1, N + 1):
        s += nCr(N, i)
    return (s * 1.0) / (2**N * 1.0)

    



#######################################################


for n_test_case in range(1, int(raw_input()) + 1):
    debug("Solving case ", n_test_case)

    printf("Case #", n_test_case, ": ", str(solve(*read_input())))

