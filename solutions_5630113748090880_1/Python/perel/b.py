import time
##import sys
##sys.setrecursionlimit(10002)

def solve(n,m):
    cou=[0]*2501
    for mi in m:
        for i in mi:
            cou[i]^=1
    ans=[str(i) for i,j in enumerate(cou) if j]
    return ' '.join(ans)

def main():
    fi=file('bs.in')
    fo=file('b.out','w')
    time0=time.time()
    t=int(fi.readline())
    for ti in range(t):
        time1=time.time()
        n=int(fi.readline())
        m=[]
        for i in range(n*2-1):
            m.append(map(int,fi.readline().split()))
        ans="Case #%d: %s"%(ti+1,solve(n,m))
        print ans,"%.3f"%(time.time()-time1)
        fo.write(ans+'\n')
    print "%.3f"%(time.time()-time0)
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
