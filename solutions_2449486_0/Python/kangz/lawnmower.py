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


#######################################################


def read_input(        ):
    Y, X = int_input()
    grid = [int_input() for i in range(Y)]
    return X, Y, grid


def solve(X, Y, grid):
    l = [max(line) for line in grid]
    c = [max([line[x] for line in grid]) for x in range(X)]
    res = [[min(x, y) for x in c] for y in l] == grid
    if res:
        return 'YES'
    else:
        return 'NO'




#######################################################


for n_test_case in range(1, int(raw_input()) + 1):
    debug("Solving case ", n_test_case)

    printf("Case #", n_test_case, ": ", str(solve(*read_input())))

