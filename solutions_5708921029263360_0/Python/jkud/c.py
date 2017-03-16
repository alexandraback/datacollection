#!/usr/bin/env python


def check(array, j, p, s):
    cnt = 0
    for e in array:
        if j is None and e[1] == p and e[2] == s:
            cnt += 1
        if e[0] == j and p is None and e[2] == s:
            cnt += 1
        if e[0] == j and e[1] == p and s is None:
            cnt += 1
    return cnt


def solve(t, J, P, S, K):
    outfits = []
    s_index = 0
    for j in range(J):
        for p in range(P):
            for s in range(S):
                if check(outfits, j, p, None) >= K:
                    continue
                if check(outfits, j, None, s) >= K:
                    continue
                if check(outfits, None, p, s) >= K:
                    continue
                outfits.append((j, p, s))
    print "Case #%d: %d" % (t, len(outfits))
    for outfit in outfits:
        print "%d %d %d" % (outfit[0]+1, outfit[1]+1, outfit[2]+1)

T = int(raw_input().strip())
for t in range(T):
    J, P, S, K = [int(i) for i in raw_input().strip().split()]
    solve(t+1, J, P, S, K)
