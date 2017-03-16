#!/usr/bin/python2.7

import sys

T = int(sys.stdin.readline())

for i in xrange(T):
    line  = sys.stdin.readline()
    words = line.strip().split()
    K     = int(words[0])
    C     = int(words[1])
    S     = int(words[2])
    ans   = []

    if C*S < K:
        print "Case #{0}: IMPOSSIBLE".format((i+1))
        continue

    for j in xrange(0, K, C):
        idx  = j
        pos  = 1
        base = K**(C-1)
        for k in xrange(C):
            if idx >= K:
                break
            pos  += idx * base
            base /= K
            idx  += 1
        ans.append(pos)
    print "Case #{0}: ".format((i+1)),
    for i in xrange(len(ans)):
        print ans[i],
    print
    


