#!/usr/bin/env python3
# coding=utf-8

"""
    Solve Round 1A 2016 p.C

    Author: killerrex
"""

import sys


def fashion(jackets, pants, shirts, k):

    jp = dict()
    js = dict()
    ps = dict()
    fits = []

    for j in range(1, jackets+1):
        for p in range(1, pants+1):
            for s in range(1, shirts + 1):

                pair_jp = (j, p)
                v_jp = jp.get(pair_jp, 0)
                if v_jp >= k:
                    continue

                pair_js = (j, s)
                v_js = js.get(pair_js, 0)
                if v_js >= k:
                    continue

                pair_ps = (p, s)
                v_ps = ps.get(pair_ps, 0)
                if v_ps >= k:
                    continue

                # Ok, is valid
                jp[pair_jp] = v_jp + 1
                js[pair_js] = v_js + 1
                ps[pair_ps] = v_ps + 1
                fits.append((j, p, s))

    return fits


def check(fits, k):

    jp = dict()
    js = dict()
    ps = dict()

    for j, p, s in fits:
        if fits.count((j, p, s)) > 1:
            raise ValueError('Go to jail Repeat {}'.format((j, p, s)))
        pair = (j, p)
        v = jp.get(pair, 0) + 1
        if v > k:
            raise ValueError('Go to jail J+P {}'.format(pair))
        jp[pair] = v

        pair = (j, s)
        v = js.get(pair, 0) + 1
        if v > k:
            raise ValueError('Go to jail J+S {}'.format(pair))
        js[pair] = v

        pair = (p, s)
        v = ps.get(pair, 0) + 1
        if v > k:
            raise ValueError('Go to jail P+S {}'.format(pair))
        ps[pair] = v


def solve(fd):
    """

    Args:
        fd: File unit
    """
    # First line is the number of cases
    total = int(fd.readline().strip())

    for i in range(total):
        values = fd.readline().strip().split()
        jackets = int(values[0])
        pants = int(values[1])
        shirts = int(values[2])
        k = int(values[3])

        outfits = fashion(jackets, pants, shirts, k)
        check(outfits, k)
        print("Case #{}: {}".format(i+1, len(outfits)))
        for j, p, s in outfits:
            print('{} {} {}'.format(j, p, s))


def start():
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as fd:
            solve(fd)
    else:
        solve(sys.stdin)

if __name__ == '__main__':
    start()
