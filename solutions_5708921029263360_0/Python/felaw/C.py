#!/usr/bin/env python3

from collections import defaultdict


def gen(j, p, s):
    for jj in range(j):
        for pp in range(p):
            ppp = (pp + jj) % p
            for ss in range(s):
                sss = (ss + ppp) % s
                yield (jj+1, ppp+1, sss+1)


def solve(j, p, s, k):
    seen = set()
    combs = defaultdict(int)
    can_continue = True
    while can_continue:
        can_continue = False
        best = None
        best_v = 1000
        for jj, pp, ss in gen(j, p, s):
            if (jj, pp, ss) in seen:
                continue
            c0 = combs[(jj, pp, None)]
            c1 = combs[(jj, None, ss)]
            c2 = combs[(None, pp, ss)]
            v = max(c0, c1, c2)
            if v >= k:
                continue
            can_continue = True
            if v < best_v:
                best_v = v
                best = (jj, pp, ss)
        if best:
            jj, pp, ss = best
            # found something to wear!
            can_continue = True
            seen.add((jj, pp, ss))

            combs[(jj, pp, None)] += 1
            combs[(jj, None, ss)] += 1
            combs[(None, pp, ss)] += 1
    rows = [' '.join(str(i) for i in r) for r in seen]
    return "%s\n%s" % (len(rows), '\n'.join(rows))


def main():
    for i in range(int(input())):
        j, p, s, k = [int(s) for s in input().split()]
        print("Case #%s: %s" % (i+1, solve(j, p, s, k)))
main()