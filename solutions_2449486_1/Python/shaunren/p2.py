#!/usr/bin/python -SOO
for case in range(1,int(input())+1):
    n,m = map(int,input().strip().split())
    lawn = [list(map(int,input().strip().split()))for _ in range(n)]
    lawnv,p = list(zip(*lawn)),True
    for i in range(n):
        for j in range(m):
            p = all(map(lambda x:x<=lawn[i][j],lawn[i])) or all(map(lambda x:x<=lawn[i][j],lawnv[j]))
            if not p: break
        if not p: break
    print('Case #{}: {}'.format(case,'YES' if p else 'NO'))
