#!/usr/bin/python -SOO
from functools import reduce
def gcd(a,b):
    return a|b if a==0 or b==0 else gcd(b,a%b)
int(input())
r,n,m,k = map(int,input().strip().split())
print('Case #1:')
for _ in range(r):
    xs = list(map(int,input().strip().split()))
    def dfs(l):
        if len(l)>=n:
            for i in xs:
                x = i
                if x<2: pass
                for j in l:
                    if x%j==0: x=x//j
                if x>1: break
            else:
                print(''.join(map(str,l)))
                return True
            return False
        else:
            for i in range(max(3,l[-1]) if len(l) else 3,m+1):
                if any(x%i==0 for x in xs) and dfs(l+[i]): return True
            else:
                if (len(l)==0 or l[-1]==2) and dfs(l+[2]): return True
        return False
    if not dfs([]):
        print('2'*n)
