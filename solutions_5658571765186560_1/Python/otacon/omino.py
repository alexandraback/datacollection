#!/usr/bin/python3.4

import sys
import math


# Return True if Richard wins
def solve(x, r, c):
    min_dim = min(r, c)
    n = r * c
    if n % x != 0:
        return True

    if x == 1:
        return False

    if x == 2:
        return False

    if x == 3:
        if min_dim == 1:
            return True

    if x == 4:
        if min_dim <= 2:
            return True

    if x == 5:
        if min_dim <= 3:
            return True

    if x == 6:
        if min_dim <= 3:
            return True

    if x >= 7:
        return True

    return False

def main():
    nb = int(get_line())
    for case_id in range(1, nb + 1):
        l = get_line().split()
        x, r, c = [int(i) for i in l]

        rwin = solve(x, r, c)
        if rwin:
            ret = 'RICHARD'
        else:
            ret = 'GABRIEL'

        print('Case #%d: %s' % (case_id, ret), file = o)

###

def get_line():
    return f.readline().strip()

def open_files():
    if len(sys.argv) == 1:
        f = sys.stdin
        o = sys.stdout

    if len(sys.argv) == 2:
        f = open(sys.argv[1], 'r')
        o = sys.stdout

    if len(sys.argv) == 3:
        f = open(sys.argv[1], 'r')
        o = open(sys.argv[2], 'w')

    return (f, o)

if __name__ == "__main__":
    (f, o) = open_files()
    main()

