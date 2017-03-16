#!/usr/bin/python3.4

import sys
import math

def solve(r, c, w):
    cnt = c // w
    cnt *= r
    if c % w != 0:
        cnt += 1
    cnt += w - 1

    return cnt

def main():
    nb = int(get_line())
    for case_id in range(1, nb + 1):
        r, c, w = [int(a) for a in get_line().split()]

        ret = solve(r, c, w)

        print('Case #%d: %s' % (case_id, ret), file = o)

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

