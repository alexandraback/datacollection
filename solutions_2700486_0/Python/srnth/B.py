
from decimal import Decimal as D

def prob(N,t):
    dp=[D(1),]+[D(0),]*N
    for i in range(t):
        new=[D(0),]*(N+1)
        for j in range(max(0,i-N+1)):
            new[j+1]+=dp[j]
        for j in range(max(0,i-N+1),N):
            new[j]  +=D('0.5')*dp[j]
            new[j+1]+=D('0.5')*dp[j]
        new[N]+=dp[N]
        dp=new
    for i in range(N-1,-1,-1):
        dp[i]+=dp[i+1]
    return dp

T=int(input())
for t in range(T):
    N,X,Y=map(int,input().split())
    m=(abs(X)+Y)//2
    k=Y
    
    if N>=(2*m+1)*(m+1):
        s='1.0'
    elif k==2*m:
        if N==(2*m+1)*(m+1):
            s='1.0'
        else:
            s='0.0'
    elif N<=(2*m-1)*m:
        s='0.0'
    else:
        #TODO
        N-=(2*m-1)*m
        s=prob(2*m,N)[k+1].quantize(D('1e-7'))
    
    print("Case #{}: {}".format(t+1,s))


