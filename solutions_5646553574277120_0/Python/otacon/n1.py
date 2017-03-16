#!/usr/bin/python3.4

import sys
import math

# not more than c coins of d
# v maximum value
def solve(c, d, v, l):
    cnt = 0

    # small case


    for to_add in range(30):
        vv = [False] * 30

        new_add = 1

        for comb in range(4096):
            value = 0
            for di in range(10):
                if 2<<di & comb == 0:
                    continue

                if di < d:
                    value += l[di]

            if value <= v and value != 0:
                vv[value-1] = True

            try:
                pos = vv[:v].index(False)
            except:
                return to_add

            new_add = max(pos +1, new_add)


        l.append(new_add)
        d += 1

    return -1

def main():
    nb = int(get_line())
    for case_id in range(1, nb + 1):
        c, d, v = [int(a) for a in get_line().split()]
        l = [int(a) for a in get_line().split()]

        ret = solve(c, d, v, l)

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

