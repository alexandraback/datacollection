#!/usr/bin/env python
# -*- coding: utf-8 -*-

def Check(Coins,c,V):
    _Coins = Coins + [c]
    dp = [False for i in range(V+1)]
    dp[1] = True

    for c in _Coins:
        for i in range(V+1)[::-1]:
            if i+c <= V and dp[i] is True:
                dp[i+c] = True
    return (len([x for x in range(V+1) if dp[x] == False])-1)

T = int(input())
for case in range(T):
    C,D,V = map(int,input().split())
    Coins = list(map(int,input().split()))
    count = 0
    tmp = Check(Coins,0,V)

    while tmp != 0:
        max_coin = 0
        max_count = 10**8
        for i in range(1,V+1):
            tmp = Check(Coins,i,V)
            if tmp == 0:
                count += 1
                break
            if max_count > tmp:
                max_count = tmp
                max_coin = i
        if tmp != 0:
            Coins += [max_coin]
            count += 1

    print("Case #{0}: {1}".format(case+1, count))
