#!/usr/bin/python -SOO
from functools import reduce
from concurrent.futures import ProcessPoolExecutor
int(input())
r,n,m,k = map(int,input().strip().split())
print('Case #1:')
def worker(xs):
    global r,n,m,k
    def dfs(l):
        if len(l)>=n:
            for i in xs:
                x = i
                if x<2: continue
                for j in l:
                    if x%j==0: x=x//j
                if x>1: break
            else:
                res = ''.join(map(str,l))
                return res
            return False
        else:
            for i in range(max(3,l[-1]) if len(l) else 3,m+1):
                if any(x%i==0 for x in xs):
                    y = dfs(l+[i])
                    if y: return y
            else:
                if (len(l)==0 or l[-1]==2):
                    y = dfs(l+[2])
                    if y: return y
        return False
    res = dfs([])
    if not res:
        return '2'*n
    else:
        return res
with ProcessPoolExecutor() as executor:
    for x in executor.map(worker,(list(map(int,input().strip().split())) for _ in range(r))):
        print(x)
