#!/usr/bin/env python
import math
T=int(raw_input().strip())

def getN(A, arr):
    ret=0
    j=1
    for m in arr:
        if A>m:
            A+=m
        elif A+A-1>m:
            ret+=1
            A=A+A-1+m
        else:
            if len(arr) == j:
                return ret+1
            giveup=len(arr)-j+1
            if A==1:
                return ret+giveup
            else:
                add=0
                while A<=m:
                    A=A+A-1
                    add+=1
                A+=m
                if add>=giveup:
                    return ret+giveup
                return ret+min(add+getN(A,  arr[j:]), giveup)
        j+=1
    return ret
for i in range(1, T+1):
    A, N = raw_input().strip().split()
    A, N = int(A), int(N)
    arr = [int(x) for x in raw_input().strip().split()]
    assert len(arr)==N
    arr = sorted(arr)
    ans = getN(A, arr)

    print 'Case #%d: %d' % (i, ans)

