#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: solve.py
# $Date: Sun May 10 18:17:15 2015 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>


import sys


def solve(fin):
    R, C, W = map(int, fin.readline().rstrip().split())

    remain = C % W
    if remain == 0:
        ret = C / W - 1 + W
    else:
        ret = C / W + W
    return ret + C / W * (R - 1)

def main():
    fin = sys.stdin

    T = int(fin.readline().rstrip())
    for case_id in xrange(1, T + 1):
#         print >> sys.stderr, 'processing {}'.format(case_id)
        print 'Case #{}: {}'.format(case_id, solve(fin))


if __name__ == '__main__':
    main()

# vim: foldmethod=marker
