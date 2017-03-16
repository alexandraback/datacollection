#!/usr/bin/python

read_int = lambda: int(raw_input())
read_lint = lambda: map(int, raw_input().split())

RICHARD = 'RICHARD'
GABRIEL = 'GABRIEL'

def solver(x, r, c):
    if r * c % x or (r * c == x and x > 2):
        return RICHARD
    if x > max(r, c):
        return RICHARD
    if min(r, c) == 1 and x > 2:
        return RICHARD
    if min(r, c) == 2:
        if x > 3:
            return RICHARD
    if min(r, c) >= 3:
        if x >= max(r, c) + 3 or x >= (r + c - 1):
            return RICHARD
    return GABRIEL

def solve_case(numc):
    print "Case #{}:".format(numc), solver(*read_lint())


def main():
    for i in xrange(1, read_int() + 1):
        solve_case(i)


if __name__ == '__main__':
    main()