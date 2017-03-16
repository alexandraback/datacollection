# -*- coding: utf-8 -*-

from itertools import product
from bisect import bisect_left as bleft


def f(a, b):
    for e in a:
        if e in b:
            return True
    return False


def solve():
    n = int(raw_input())
    ss = []
    for i in xrange(n):
        ss.append(raw_input().split())

    fsts = {}
    snds = {}
    for i, (a, b) in enumerate(ss):
        if a not in fsts:
            fsts[a] = set()
        fsts[a].add(i)
        if b not in snds:
            snds[b] = set()
        snds[b].add(i)

    fst_reqs = []
    snd_reqs = []
    for a, b in ss:
        fst_reqs.append(fsts[a])
        snd_reqs.append(snds[b])

    memo = {tuple():0}
    for i in xrange(n):
        nmemo = {}
        for k in memo.keys():
            for j in xrange(n):
                if j in k:
                    continue
                key = list(k)
                key.insert(bleft(key, j), j)
                tk = tuple(key)
                if tk in nmemo:
                    nmemo[tk] = max(nmemo[tk], memo[k])
                else:
                    nmemo[tk] = memo[k]
                sk = set(k)
                if f(fst_reqs[j], sk) and f(snd_reqs[j], sk):
                    nmemo[tk] += 1
        memo = nmemo

    best = 0
    for v in memo.values():
        best = max(v, best)

    print best


def main():
    t = int(raw_input())
    for i in xrange(1, t + 1):
        print 'Case #%d:' % i,
        solve()


if __name__ == '__main__':
    main()
