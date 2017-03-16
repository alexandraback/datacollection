#!/usr/bin/env python3

import sys
from collections import defaultdict
from heapq import heappush, heappop

def read_ints():
    return [int(s) for s in input().split()]

def main():
    no_cases, = read_ints()
    for case in range(1, no_cases+1):
        N,M = read_ints()
        toys = read_ints()
        boxes = read_ints()
        assert(len(toys) == 2*N)
        assert(len(boxes) == 2*M)
        print('Case #%d: %s' % (case, solve(pairs(toys), pairs(boxes))))

def pairs(longlist):
    return list(zip(*([iter(longlist)]*2)))

def cnt(pairs):
    return sum(x for _, x in pairs)

def pqitem(v, t, b):
    heur = -v - min(cnt(t), cnt(b))
    return (heur, v, t, b)

def children(item):
    _, v, tall, ball = item
    if tall and ball:
        [(tc, t), *ts] = tall
        [(bc, b), *bs] = ball
        if t == b:
            if tc < bc:
                yield pqitem(v + tc, ts, [(bc-tc, b)] + bs)
            else:
                yield pqitem(v + bc, [(tc-bc, t)] + ts, bs)
        yield pqitem(v, tall, bs)
        yield pqitem(v, ts, ball)
    else:
        yield pqitem(v, [], [])

def solve(toys, boxes):
    init = pqitem(0, toys, boxes)
    q = [init]
    while q:
        item = _, v, ts, bs = heappop(q)
        if (ts, bs) == ([], []):
            return v
        for child in children(item):
            heappush(q, child)
    raise(Exception('no solution'))


if __name__ == '__main__':
    main()
