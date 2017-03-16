# coding: UTF-8

import sys
import numpy as np


def solve(m):
    ords = map(lambda i: get_ord(i, m), range(1, len(m) + 1))
    r = {}
    for z in [i+1 for i, o in enumerate(ords) if o == 0]:
        bff = m[z-1]
        if bff not in r:
            r[bff] = []
        r[bff].append(z)
    sinkords = {0: 0}
    for t in [i+1 for i, o in enumerate(ords) if o == 2]:
        p = tuple(sorted([t, m[t-1]]))
        if p not in sinkords:
            sinkords[p] = get_sinkord(p, r, 2)
    return max([max(ords), sum(sinkords.values())])


def get_ord(id, m):
    mem = set()
    s = m[id-1]
    mem.add(s)
    while True:
        if m[s-1] == id:
            return len(mem) + 1
        if m[s-1] in mem:
            return 0
        mem.add(m[s-1])
        s = m[s-1]


def get_sinkord(p, r, d, flg=True):
    if flg:
        if p[0] not in r:
            return get_sinkord(p, r, d, False)
        best = d
        for n in r[p[0]]:
            cand = get_sinkord((n, p[1]), r, d+1, True)
            if best < cand:
                best = cand
        return best
    else:
        if p[1] not in r:
            return d
        best = d
        for n in r[p[1]]:
            cand = get_sinkord((p[0], n), r, d+1, False)
            if best < cand:
                best = cand
        return best


if __name__ == '__main__':
    problemCounts = int(sys.stdin.readline())
    for cn in range(problemCounts):
        problemSize = int(sys.stdin.readline())
        prob = map(int, sys.stdin.readline().strip().split(' '))
        sys.stdout.write('Case #%d: %s\n' % ((cn+1), str(solve(prob))))
