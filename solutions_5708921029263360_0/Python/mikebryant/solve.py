#!/usr/bin/env python

from collections import defaultdict

DEBUG = False

T = int(raw_input().strip())

def solve(J, P, S, K):
    jp_combos = defaultdict(int)
    js_combos = defaultdict(int)
    ps_combos = defaultdict(int)
    for j in range(1, J+1):
        for p in range(1, P+1):
            if jp_combos[(j, p)] >= K:
                continue
            ss = range(1, S+1)
            ss.sort(key=lambda s: ps_combos[(p, s)] + js_combos[(j, s)])
            for s in ss:
                if jp_combos[(j, p)] >= K:
                    break
                if js_combos[(j, s)] >= K:
                    continue
                if ps_combos[(p, s)] >= K:
                    continue
                if DEBUG:
                    print (p, j, s)
                yield (j, p, s)
                jp_combos[(j, p)] += 1
                js_combos[(j, s)] += 1
                ps_combos[(p, s)] += 1


for i in range(1, T+1):
    print ("Case #%d:" % i),
    J, P, S, K = map(int, raw_input().strip().split())
    answers = list(solve(J, P, S, K))
    print len(answers)
    for ans in answers:
        print ' '.join(map(str, ans))
