#!/usr/bin/python

import sys

minabs = 1 << 20
minc = 1 << 20
minj = 1 << 20
ans = ''

def dfs(S, k):
    global minabs
    global minc
    global minj
    global ans

    n = len(S)

    if k == n:
        S = ''.join(S)
        myc, myj = S.split()
        myabs = abs(int(myc) - int(myj))
        if myabs < minabs or (myabs == minabs and myc < minc) or (myabs == minabs and myc == minc and myj < minj):
            minabs = myabs
            minc = myc
            minj = myj
            ans = minc + ' ' + minj
        return

    S = list(S)
    if S[k] == '?':
        oldc = S[k]
        for digit in range(10):
            S[k] = str(digit)
            dfs(S, k + 1)
        S[k] = oldc
    else:
        dfs(S, k + 1)


T = int(input())
for t in range(T):
    global minabs
    global ans
    minabs = 1 << 20
    S = input()
    dfs(S, 0)
    print('Case #{}: {}'.format(t + 1,  ans))

