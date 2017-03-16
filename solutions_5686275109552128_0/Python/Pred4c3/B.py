import sys
import time
sys.setrecursionlimit(10000)

def memoize(func):
    pool = {}
    def wrapper(*arg):
        if arg not in pool:
            pool[arg] = func(*arg)
        return pool[arg]
    return wrapper

dic = {}
for i in range(1,1001):
    r = [(i,0)] #minutes,stops
    for p in range(2,33):
        if i>=p*p:
            r.append(((i+p-1)//p,p-1))
    dic[i] = r

T=int(input())
for case_id in range(1,T+1):
    D = int(input())
    arr = list(map(int,input().split()))
    arr.sort(key=lambda x:-x)

    def rec(idx,c):
        if (idx==len(arr)): return c
        ct,cs = c
        r = []
        for t,s in dic[arr[idx]]:
            r.append(rec(idx+1,(max(ct,t),cs+s)))

        return min(r,key=lambda x:x[0]+x[1]) if len(r)>0 else (10**9,0)

    def solve():
        r = []
        for c in dic[arr[0]]:
            r.append(rec(1,c))
        rr = min(r,key=lambda x:x[0]+x[1])
        return rr[0]+rr[1]
            
    start = time.clock()
    ans = solve()
        
    print('Case #%d: %d' % (case_id, ans))
    print('Case #%d: %d' % (case_id, ans), time.clock()-start, file=sys.stderr)
