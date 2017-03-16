#!/usr/bin/python3.4

import sys
import math

def solve(levels):
    missings = 0

    nb_people = 0
    for l, si in enumerate(levels):
        adding = 0
        if nb_people < l:
            adding = l - nb_people
            missings += adding

        nb_people += adding + si

    return missings

def main():
    nb = int(get_line())
    for case_id in range(1, nb + 1):
        l = get_line().split()
        smax, str_levels = l

        smax = int(smax)
        levels = [int(i) for i in str_levels]

        ret = solve(levels)

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

