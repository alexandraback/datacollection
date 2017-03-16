#!/usr/bin/env python

TEST="""3
1 4 2
1 7 7
2 5 1"""
raw_input = iter(TEST.splitlines()).next

def solve(C,W):
    gh = C/W
    miss = 1
    if C%W == 0:
        miss = 0
    rem = W-1
    
    return (gh+miss+rem)


T = int(raw_input())
for case in range(1,T+1):
    R,C,W = map(int, raw_input().strip().split())
    assert(R==1)
    print("Case #%s: %s" % (case, solve(C,W)))
