import sys

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

NTestCases = int(raw_input())

def solve(N, parents):
    found = False
    for i in range(N):
        if sub_solve(i, N, parents):
            return "Yes"

    return "No"

def sub_solve(i, N, parents):
    seen = [False for j in range(N)]

    def see(k):
        if seen[k]:
            return True
        seen[k] = True

        for parent in parents[k]:
            if see(parent-1):
                return True

        return False

    return see(i)

for n_test_case in range(NTestCases):
    N = int_input()[0]

    parents = [int_input()[1:] for i in range(N)]

    debug("Solving case ", n_test_case + 1)

    printf("Case #", n_test_case + 1, ": ", str(solve(N, parents)))

