import sys
from collections import deque
sys.stdin=open("k.in",'r')
sys.stdout=open("OUT.txt",'w')
for t in xrange(int(raw_input())):
    a=int(raw_input())
    dp=[1e999 for i in xrange(a+1)]
    dp[1]=1
    queue=deque()
    queue.append(1)
    while queue:
        u=queue.popleft()
        if u+1<=a and dp[u]+1<dp[u+1]:
            dp[u+1]=dp[u]+1
            queue.append(u+1)
        v=int(str(u)[::-1])
        if v<=a and dp[u]+1<dp[v]:
            dp[v]=dp[u]+1
            queue.append(v)
    print 'Case #%i: %i'%(t+1,dp[-1])
sys.stdout.close()
