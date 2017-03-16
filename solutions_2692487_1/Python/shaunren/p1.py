#!/usr/bin/python -SOO
for case in range(1,int(input())+1):
    a,n = map(int,input().strip().split())
    motes = sorted(list(map(int,input().strip().split())))
    ops = 0
    best = [0]+[float('inf')for _ in range(n)]
    for i,x in enumerate(motes):
        if a<=x:
            b,o = a,0
            while b>1 and b<=x:
                b = b*2-1
                o+=1
            if b>1 and o<n-i: a,ops=b+x,ops+o
        else: a+=x
        if a<=motes[i]: break
        best[i+1] = ops
    print('Case #{}: {}'.format(case,min(best[i]+(n-i)for i in range(n+1))))
