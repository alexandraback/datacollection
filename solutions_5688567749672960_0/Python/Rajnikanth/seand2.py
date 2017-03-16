dp=[-1]*((10**6) + 1)
dp[0]=0
for i in xrange(1,10):
    dp[i]=i
def find(n):
    if(dp[n]!=-1):
        return dp[n]
    if(dp[n-1]!=-1):
        a = dp[n-1]+1
    else:
        a = find(n-1)+1
    z = str(n)
    z = z[-1::-1]
    N=int(z)
    x = str(N)
    x = x[-1::-1]
    x = int(x)
    if(N>=n or x!=n):
        dp[n]=a
    else:
        if(dp[N]!=-1):
            b = dp[N]+1
        else:
            b = find(N)+1
        dp[n]=min(a,b)
    return dp[n]
for i in xrange(1,10**6+1):
    dp[i]=find(i)
t = input()
for i in xrange(1,t+1):
    n = input()
    print "Case #"+str(i)+":",dp[n]
