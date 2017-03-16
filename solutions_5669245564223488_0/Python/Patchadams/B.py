memo={}
def ans(array,current,string,count,n,used,m,memo):
    if memo.has_key((used,current)):
        return memo[used,current]
    #print current,used,string
    if count==n and check(string,"")==1:
        #print string
        return 1
    s=0
    for i in xrange(n):
        if used[i]==1:
            continue
        if array[current][i]==1 and check(string,m[i])==1:
            u=list(used)[:]
            u[i]=1
            u=tuple(u)
            s+=ans(array,i,string+m[i],count+1,n,u,m,memo)
    memo[used,current]=s
    return s
    
def check(s1,s2):
    s=s1+s2
    l=len(s)
    used={}
    used[s[0]]=1
    for i in xrange(1,l):
        if used.has_key(s[i]) and s[i-1]!=s[i]:
            return 0
        used[s[i]]=1
    return 1
    
t=int(raw_input())
for i in xrange(1,t+1):
    n=int(raw_input())
    s=map(str,raw_input().split())
    #print s
    array={}
    memo={}
    for j in xrange(n):
        array[j]={}
    for j in xrange(n):
        for k in xrange(j+1,n):
            array[j][k]=check(s[j],s[k])
            array[k][j]=check(s[k],s[j])
    #print array
    m=0
    for j in xrange(n):
        used=[0]*n
        used[j]=1
        m+=ans(array,j,s[j],1,n,tuple(used),s,memo)
    print "Case #%d: %d"%(i,m)
