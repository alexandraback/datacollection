def get(n,c,dep):
    if dep==n:
        return 0
    if c==1:
        return dep
    return dep*(n**(c-1))+get(n,c-1,dep+1)

def solve(n,c,s):
    if c*s<n:
        return " IMPOSSIBLE"
    else:
        now = 0
        ans = ""
        while now<n:
            ans+=" "+str(1+now*(n**(c-1))+get(n,c,0))
            now+=c
        return ans
cas = int(raw_input())
for T in range(1, cas+1):
    n,c,s = map(int, raw_input().split())
    print "Case #%d:%s"%(T,solve(n,c,s))
