#!/usr/bin/env python

import sys

def solve(S):
    add = 0
    cur = 0
    for s in sorted(S.keys()):
        if S[s] != 0: 
            add_now = max(s - cur, 0)
            add += add_now
            cur += S[s] + add_now
    return add

case = 0
for ln in open(sys.argv[1], 'r'):
    ln = ln.strip().split()
    if len(ln) != 2: continue
    case += 1
    smax, ss = ln
    s = {i:int(a) for i,a in enumerate(ss)}
    print "Case #%d: %d" % (case, solve(s))
