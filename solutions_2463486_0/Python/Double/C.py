#!/usr/bin/env python
import math
T=int(raw_input().strip())


def ispalindrome(i):
    s=str(i)
    l, h=0, len(s)-1
    while l<h:
        if s[l]!=s[h]:
            return False
        l+=1
        h-=1
    return True

for i in range(1, T+1):
    N, M = raw_input().strip().split()
    N, M = int(N), int(M)
    total=0
    for j in xrange(N, M+1):
        if ispalindrome(j):
            k=int(math.pow(j, 0.5))
            if k*k==j and ispalindrome(k):
                #print k,j
                total+=1
    print 'Case #%d: %d' % (i, total)

