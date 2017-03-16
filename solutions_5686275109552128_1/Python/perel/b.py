import time
def solve2(n,m):
    a=[0]*(max(m)+1)
    for i in m:
        a[i]+=1
    ans=1001
    ma=len(a)-1
    for i in range(1,ma+1):
        t=0
        for j in range(i+1,ma+1):
            t+=((j+i-1)/i-1)*a[j]
        if ans>t+i:
            ans=t+i
##        print i,t
    return ans

def solve(n,m):
    global maxans,ca
    a=[0]*(max(m)+1)
    for i in m:
        a[i]+=1
    maxans=len(a)-1
    ca={}
    return solve1(a,0)

def solve1(a,t):
    global maxans,ca
    if t>=maxans:
        return 1002
    ma=len(a)-1
    ans=t+ma
    if ma<=3:
        return ans
    if tuple(a) in ca:
        return ca[tuple(a)]
    for i in range(1,ma/2+1):
        b=a[:-1]
        b[i]+=a[-1]
        b[ma-i]+=a[-1]
        while b[-1]==0: b.pop()
        ans=min(ans,solve1(b,t+a[-1]))
    if ans<=maxans:
        maxans=ans
    else:
        ans=1001
    ca[tuple(a)]=ans
    return ans

def main():
    fi=file('bl.in')
    fo=file('b.out','w')
    time0=time.time()
    t=int(fi.readline())
    for ti in range(t):
        time1=time.time()
        n=int(fi.readline())
        m=map(int,fi.readline().split())
        ans="Case #%d: %s"%(ti+1,solve2(n,m))
        print ans,"%.3f"%(time.time()-time1)
        fo.write(ans+'\n')
    print "%.3f"%(time.time()-time0)
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
