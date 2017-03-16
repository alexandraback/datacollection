#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: solve.py
# $Date: Sat Apr 09 23:14:48 2016 +0800
# $Author: jiakai <jia.kai66@gmail.com>

import sys
import collections

class cached:
    """cache for pure functions"""
    _func = None
    _cache = None

    def __init__(self, func):
        self._func = func
        self._cache = {}

    def __call__(self, *args):
        val = self._cache.get(args)
        if val is not None:
            return val
        val = self._func(*args)
        assert val is not None
        self._cache[args] = val
        return val


@cached
def first_G(K, C, pad, nseq):
    """nseq sequences, where i'th sequence has only (i+pad)'th element as G.
    There exists a postion that all elements on this position of these nseq
    sequences are G; return first of that position (starting from 0)
    """
    if nseq == 0:
        return 0
    offset = pad * K**(C-1)
    remain = first_G(K, C - 1, pad + 1, nseq - 1)
    return offset + remain

def solve(K, C):
    """return a shortest feasible sequence given K and C (returned pos starting
    from 0)"""
    pos = 0
    ret = []
    while pos < K:
        end = min(pos + C, K)
        ret.append(first_G(K, C, pos, end - pos))
        pos = end
    check(K, C, ret)
    return ret

def check(K, C, plan):
    assert len(plan) == (K - 1)//C + 1
    if K * K**C >= 10**6:
        print('skip check for {}'.format((K, C)), file=sys.stderr)
        return

    def expand(s0):
        """expand original sequence *s0*; 1 for 'G', 0 for 'L'"""
        prev = s0
        gseq = [1] * K
        for i in range(1, C):
            cur = []
            for ele in prev:
                if ele:
                    cur.extend(gseq)
                else:
                    cur.extend(s0)
            prev = cur
        return prev

    pos2mask = collections.defaultdict(list)
    for i in range(K):
        cur = [0] * K
        cur[i] = 1
        for pos, ele in enumerate(expand(cur)):
            if ele:
                pos2mask[pos].append(i)

    start = 0
    for i in plan:
        end = min(start + C, K)
        covered = set(pos2mask[i])
        expect = set(range(start, end))
        assert not expect.difference(covered), (
            K, C, (plan, i), covered, expect)
        start = end
    assert start == K

def main():
    nr_case = int(input())
    for i in range(nr_case):
        K, C, S = map(int, input().split())
        seq = solve(K, C)
        if len(seq) > S:
            ans = 'IMPOSSIBLE'
        else:
            ans = ' '.join(str(i + 1) for i in seq)
        print('Case #{}: {}'.format(i + 1, ans))

if __name__ == '__main__':
    main()
