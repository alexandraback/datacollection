#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author: Konrad Markus <konker@gmail.com>
# Url: http://code.google.com/codejam/contest/1460488/dashboard#s=p2

import sys
import itertools

def main():
    prepare()

    T = int(sys.stdin.readline().rstrip())

    t = 1
    while (t <= T):
        AB = sys.stdin.readline().rstrip().split(" ")
        assert len(AB) == 2
        assert len(AB[0]) == len(AB[1])

        solve(t, int(AB[0]), int(AB[1]))
        t = t + 1


def prepare():
    pass


def solve(t, A, B):
    sys.stdout.write("Case #")
    sys.stdout.write(str(t))
    sys.stdout.write(": ")

    tot = 0
    for n in xrange(A, B):
        rs = get_recycles(n, A, B)
        tot = tot + len(rs)

    sys.stdout.write(str(tot))
    sys.stdout.write("\n")


def get_recycles(n, A, B):
    n = str(n)
    ret = []
    for i in xrange(1, len(n)):
        r = n[i:] + n[:i]
        if A <= int(r) and int(n) < int(r) and int(r) <= B:
            if not r in ret and not is_repetition(r):
                ret.append(r)

    return ret


"""Determine if the chars of the input string are all the same"""
def is_repetition(r):
    cc = r[0]
    for c in r:
        if c != cc:
            return False
    return True


if __name__ == '__main__':
    main()

