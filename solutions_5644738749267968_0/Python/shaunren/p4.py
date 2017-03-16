#!/usr/bin/python3 -SOO   
from bisect import bisect 
for cas in range(1,int(input())+1):
    n = int(input())
    naomi = sorted(map(float,input().strip().split()))
    ken = sorted(map(float,input().strip().split()))
    a,b = 0,0
    ls = [k for k in range(n) if naomi[k]>ken[n-1-k]]
    for i in range(n):
        ks = ken[:n-i]
        c = 0
        for x in naomi[i:][::-1]:
            if x>ks[-1]:
                ks.pop()
                c += 1
            else:
                ks.pop(bisect(ks,x))
        a = max(a,c)
        
    for x in naomi[::-1]:
        k = bisect(ken,x)
        y = ken.pop(0 if k>=len(ken) else k)
        b += (x>y)
    print('Case #%d:'%cas, a, b)
        
