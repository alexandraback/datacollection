#!/usr/bin/env python3

################################################################################

def read_int():
    return int(input())


def read_words():
    return input().split()


def parse(f):
    return [f(x) for x in read_words()]


def read_ints():
    return parse(int)


def read_floats():
    return parse(float)


################################################################################


def list_powerset(lst):
    result = [[]]
    for x in range(lst):
        result.extend([subset + [x] for subset in result])
    return result

def correct(g, lines):
    original = [ lines[i] for i in g ];
    d0 = { l[0] for l in original }
    d1 = { l[1] for l in original }

    return all([ i in g or (lines[i][0] in d0 and lines[i][1] in d1) for i in range(len(lines))])

def solve(lines):
    n = len(lines)
    return [ n - len(orig) for orig in list_powerset(n) if correct(orig,lines) ][0]


for C in range(read_int()):
    N = read_int()
    R = solve([ read_words() for i in range(N) ])
    print("Case #{}: {}".format(C + 1, R))
