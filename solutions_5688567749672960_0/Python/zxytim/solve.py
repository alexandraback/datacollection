#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: solve.py
# $Date: Sun May 03 00:13:10 2015 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>


import sys
from collections import defaultdict, deque


dist = defaultdict(lambda: sys.maxint)
dist[1] = 1

queue = deque()
queue.append(1)
while len(queue) > 0:
    cur = queue.popleft()
    dcur = dist[cur]
    for nxt in [cur + 1, int(str(cur)[::-1])]:
        if nxt > 1000000:
            continue
        if nxt not in dist:
            dist[nxt] = dcur + 1
            queue.append(nxt)

def solve(fin):
    N = int(fin.readline().rstrip())
    return dist[N]



def main():
    fin = sys.stdin

    T = int(fin.readline().rstrip())
    for case_id in xrange(1, T + 1):
        print 'Case #{}: {}'.format(case_id, solve(fin))


if __name__ == '__main__':
    main()

# vim: foldmethod=marker
