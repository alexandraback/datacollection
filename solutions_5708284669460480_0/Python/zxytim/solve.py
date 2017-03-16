#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: solve.py
# $Date: Sun May 10 19:00:31 2015 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>


import sys
from itertools import product


def bananas_to_bring(target, S):
    assert len(target) <= S
    ret = 0
    s = ''
    for i in range(S - len(target) + 1):
        if i < len(s):
            if s[i:] == target[:len(s) - i]:
                s = s[:i] + target
                ret += 1
        else:
            s += target
            ret += 1
    return ret

def number_of_appearance(a, s):
    ret = 0
    pos = 0
    while True:
        pos = s.find(a, pos)
        if pos == -1:
            return ret
        ret += 1
        pos += 1


def solve(fin):
    K, L, S = map(int, fin.readline().rstrip().split())
    keyboard = fin.readline().rstrip()
    target = fin.readline().rstrip()

    if set(keyboard) & set(target) != set(target):
        return 0

    b = bananas_to_bring(target, S)
    count = 0
    for perm in product(keyboard, repeat=S):
        c = number_of_appearance(target, ''.join(perm))
#         print target, c, perm
        count += b - c

    return count / float(len(keyboard) ** S)


def main():
    fin = sys.stdin

    T = int(fin.readline().rstrip())
    for case_id in xrange(1, T + 1):
        print >> sys.stderr, 'processing {}'.format(case_id)
        print 'Case #{}: {}'.format(case_id, solve(fin))


if __name__ == '__main__':
    main()

# vim: foldmethod=marker
