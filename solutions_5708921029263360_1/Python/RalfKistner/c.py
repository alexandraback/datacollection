#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys
from collections import defaultdict

def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    J, P, S, K = map(int, fin.readline().split())


    pairs_jp = defaultdict(int)
    pairs_js = defaultdict(int)
    pairs_ps = defaultdict(int)
    result = []
    s = 0
    MAX = J * P * min(S, K) # Theoretical maximum. We hope to achieve this.
    for j in range(1, J+1):
        s = j

        for p in range(1, P+1):

            for i in range(S):

                if pairs_jp[(j, p)] >= K:
                    break
                s = (s % S) + 1

                if pairs_js[(j, s)] >= K:
                    continue
                if pairs_ps[(p, s)] >= K:
                    continue
                pairs_jp[(j, p)] += 1
                pairs_js[(j, s)] += 1
                pairs_ps[(p, s)] += 1

                result.append("%d %d %d" % (j, p, s))



    debug(MAX == len(result), MAX, len(result))
    print("Case #%d: %s" % (case, len(result)))
    # for row in result:
    #     print(row)


