'''
Created on Apr 11, 2015

@author: Incognito
'''
import math
T=int(raw_input())
for j in range(T):
    numberOfplate=raw_input()
    data=raw_input().split(" ")
    data=map(int,data)
    data=sorted(data)
    data=data[::-1]
    max=data[0]
    res=data[0]
    bigestInLastRound=2
    while bigestInLastRound<data[0]:
        sum=0
        for x in data:
            sum+=(x-1)/bigestInLastRound
        sum+=bigestInLastRound
        if sum<res:
            res=sum
        bigestInLastRound+=1
    print "Case #"+`j+1`+":",res