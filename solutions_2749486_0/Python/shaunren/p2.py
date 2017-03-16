#!/usr/bin/python -SOO
from collections import deque
dirs = ((0,1),(0,-1),(1,0),(-1,0))
dir_names = 'NSEW'
for case in range(1,int(input())+1):
    x,y = map(int,input().strip().split())
    visited = {(0,0)}
    q = deque([(0,0,'')])
    ans = ''
    while len(q):
        u,v,w = q.popleft()
        if (u,v)==(x,y):
            ans=w
            break
        l = len(w)
        for s,d in zip(dir_names,dirs):
            dx,dy = d[0]*(l+1),d[1]*(l+1)
            if -100<=u+dx<=100 and -100<=v+dy<=100 and (u+dx,v+dy) not in visited:
                if (u+dx,v+dy)==(x,y):
                    ans=w+s
                    break
                visited.add((u+dx,v+dy))
                q.append((u+dx,v+dy,w+s))
    print('Case #{}: {}'.format(case,ans))
