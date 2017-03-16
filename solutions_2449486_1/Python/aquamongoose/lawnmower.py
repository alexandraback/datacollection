#!/usr/bin/env python3
# Bill Cooperman (aquamongoose)
# Google Code Jam Qualification Round
# Problem 
T = int(input())

for i in range(T):
    print("Case #{}:".format(i+1),end=' ')
    N, M = [int(x) for x in input().split()]
    a = []
    for i in range(N):
        a.append([int(x) for x in input().split()])
    bad = False
    for i in range(N):
        for j in range(M):
            yes = 2
            for k in range(N):
                if a[k][j] > a[i][j]:
                    yes -= 1
                    break
            for k in range(M):
                if a[i][k] > a[i][j]:
                    yes -= 1
                    break
            if yes == 0:
                bad = True
    if bad:
        print("NO")
    else:
        print("YES")
