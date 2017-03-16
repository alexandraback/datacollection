#!/usr/bin/env python

TEST="""4
1 2 3
1 2
1 3 6
1 2 5
2 1 3
3
1 6 100
1 5 10 25 50 100"""
#raw_input = iter(TEST.splitlines()).next

def make(coins, D, C):
    Vs = set()
    for combo in range(1, (C+1)**D):
        v = 0
        ix = 0
        while combo:
            combo, unit = divmod(combo, (C+1))
            v += unit*coins[ix]
            ix+=1
        Vs.add(v)
    return Vs

def solve(C,D,V,coins):
    # brute the small?
    r = 0
    need = set(range(1,V+1))
    poss = make(coins,D, C)
    new = []
    missing = need - poss
    while missing:
        r += 1
        new.append(min(missing))
        poss = make(coins+new, D+r, C)
        missing = need - poss
    return r



T = int(raw_input())
for case in range(1,T+1):
    C,D,V = map(int, raw_input().strip().split())
    coins = map(int, raw_input().strip().split())
    assert(len(coins) == D)
    print("Case #%s: %s" % (case, solve(C,D,V,coins)))
