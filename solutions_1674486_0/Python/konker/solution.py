#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author: Konrad Markus <konker@gmail.com>
# URL: http://code.google.com/codejam/contest/1781488/dashboard#s=p0
#
# pylint: disable=C0103
# pylint: disable=C0111

import sys
import itertools

def main():
    prepare()

    T = int(sys.stdin.readline().rstrip())

    t = 1
    while (t <= T):
        N = int(sys.stdin.readline().rstrip())
        n = 1

        classes = [None]
        while (n <= N):
            dat = map(int, sys.stdin.readline().rstrip().split(" "))
            dat = dat[1:]
            classes.append(dat)
            n = n + 1

        solve(t, N, classes)
        t = t + 1


def prepare():
    pass


def solve(t, N, classes):
    sys.stdout.write("Case #")
    sys.stdout.write(str(t))
    sys.stdout.write(": ")

    pairs = itertools.permutations(map(str, range(1, N+1)), 2)
    diamonds = []
    for p in pairs:
        if not p in diamonds:
            hits = search(classes, int(p[0]), int(p[1]))
            if hits > 1:
                diamonds.append(tuple(reversed(p)))

    result = 'Yes' if len(diamonds) > 0 else 'No'

    sys.stdout.write(result)
    sys.stdout.write("\n")


def search(classes, X, Y):
    ret = 0
    
    for parent in classes[X]:
        if parent == Y:
            ret = ret + 1
        else:
            ret = ret + search(classes, parent, Y)
    return ret


if __name__ == '__main__':
    main()

