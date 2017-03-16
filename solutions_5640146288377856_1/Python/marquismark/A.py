#!/usr/bin/env python

TEST="""5
1 4 2
1 7 7
2 5 1
1 20 10
5 20 10"""
#raw_input = iter(TEST.splitlines()).next

def solve(R,C,W):
    gh = (C/W)*R        # Guarantee a hit.
    miss = 1
    if C%W == 0:
        miss = 0
    rem = W-1
    
    return (gh+miss+rem)


T = int(raw_input())
for case in range(1,T+1):
    R,C,W = map(int, raw_input().strip().split())
    print("Case #%s: %s" % (case, solve(R, C,W)))
