import time
def solve(n,m):
    a=[int(m[i]) for i in range(n+1)]
    t=0
    ans=0
    b=[0]*(n+1)
    for i in range(1,n+1):
        b[i]=b[i-1]+a[i-1]
        if b[i]<i:
            ans+=i-b[i]
            b[i]=i
    return ans

def main():
    fi=file('as.in')
    fo=file('a.out','w')
    time0=time.time()
    t=int(fi.readline())
    for ti in range(t):
        time1=time.time()
        n,m=fi.readline().split()
        n=int(n)
        ans="Case #%d: %s"%(ti+1,solve(n,m))
        print ans,"%.3f"%(time.time()-time1)
        fo.write(ans+'\n')
    print "%.3f"%(time.time()-time0)
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
