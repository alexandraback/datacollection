from math import log
memo={}
def gcd(x,y):
    while (x>0):
        y,x=x,y%x
    return y
def ans(p,q):
    x=gcd(p,q)
    p/=x
    q/=x
    if 2**int(log(q,2))!=q:
        return -1
    else:
        if memo.has_key((p,q)):
            return memo[p,q]
        else:
            if p>=(q/2)+1:
                return 1
            if p==1:
                return int(log(q,2))
            a=1+ans(2*p+1,q)
            memo[p,q]=a
            return a
t=int(raw_input())
for i in xrange(1,t+1):
    s=map(int,raw_input().split("/"))
    a=ans(s[0],s[1])
    if (a==-1):
        print "Case #%d: impossible"%(i)
    else:
        print "Case #%d: %d"%(i,ans(s[0],s[1]))
        
        
    
                                
            
        
    
