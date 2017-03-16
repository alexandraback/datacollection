#!/usr/bin/env python

import itertools 

TEST="""7
1? 2?
?2? ??3
? ?
?5 ?0
1?5? 5?05
?0? ?5?
?0? ?51"""
#raw_input = iter(TEST.splitlines()).next



def md(n):
    if n < 0:
        return 10+n
    if n > 9:
        return n-10
    return n

def toint(x):
    r = 0
    u = 1
    for d in reversed(x):
        r += u*d
        u *= 10
    return r

def solve(L,R):
    L, R = list(L), list(R)
    for ix,(l,r) in enumerate(zip(L,R)):
        if l == '?' and r == '?':
            if ix == 0:
                L[ix] = [0,1]
                R[ix] = [0,1]
            else:
                L[ix] = [0,1,9]
                R[ix] = [0,1,9]
        elif l == '?':
            r = int(r)
            L[ix] = [0, 1, md(r-1), r, md(r+1), 9]        
            R[ix] = [r]
        elif r == '?':
            l = int(l)
            R[ix] = [0, 1, md(l-1), l, md(l+1), 9]
            L[ix] = [l]
        else:
            L[ix] = [int(l)]
            R[ix] = [int(r)]

    all_L = [toint(x) for x in list(itertools.product(*L))]
    #print all_L
    all_R = [toint(x) for x in list(itertools.product(*R))]
    #print all_R
    best = 10**30
    bl = 10**30
    br = 10**30
    for l, r in itertools.product(all_L, all_R):
        diff = abs(l-r)
        if ((diff < best) or
            (diff == best and l < bl) or
            (diff == best and l == bl and r < br)):
            best = diff
            bl, br = l, r

    return "%s %s" % (str(bl).zfill(len(L)), str(br).zfill(len(L)))


T = int(raw_input())
for case in range(1,T+1):
    L,R = raw_input().strip().split()
    L = L.strip()
    R = R.strip()
    print("Case #%s: %s" % (case, solve(L,R)))
