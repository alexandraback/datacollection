import sys
import math
from decimal import Decimal

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


def read_input():
    r, t = int_input()
    return r, t


def solve1(r, t):
    kmax = int(math.floor(math.sqrt((2 * r - 1)**2 + 8 * t)))
    kmax -= 2 * r - 1
    return kmax // 4

def solve(r, t):
    approx = solve1(r, t)
    maxi = 0
    for i in range(max(approx - 100, 0), approx + 100):
        if 2 * i * i + (2*r - 1) * i < t:
            maxi = i
    return maxi

#######################################################


for n_test_case in range(1, int(raw_input()) + 1):
    debug("Solving case ", n_test_case)

    printf("Case #", n_test_case, ": ", str(solve(*read_input())))

