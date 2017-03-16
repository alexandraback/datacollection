import time
##import sys
##sys.setrecursionlimit(10002)
from collections import Counter
def solve(n,m):
    c1=Counter([i[0] for i in m])
    c2=Counter([i[1] for i in m])
    sm=set(tuple(i) for i in m)
    ans=0
    s1=set()
    s2=set()
    for mi in list(sm):
        if c1[mi[0]]==1 or c2[mi[1]]==1:
            sm.remove(mi)
            s1.add(mi[0])
            s2.add(mi[1])
    for mi in list(sm):
        if mi[0] in s1 and mi[1] in s2:
            sm.remove(mi)
            ans+=1
    while sm:
        mi=sm.pop()
        s2.add(mi[1])
        s1.add(mi[0])
        for mj in list(sm):
            if mj[0] in s1 and mj[1] in s2:
                sm.remove(mj)
                ans+=1

    return ans

def main():
    fi=file('cs.in')
    fo=file('c.out','w')
    time0=time.time()
    t=int(fi.readline())
    for ti in range(t):
        time1=time.time()
        n=int(fi.readline())
        m=[]
        for i in range(n):
            m.append(fi.readline().split())
        ans="Case #%d: %s"%(ti+1,solve(n,m))
        print ans,"%.3f"%(time.time()-time1)
        fo.write(ans+'\n')
    print "%.3f"%(time.time()-time0)
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
##    import random
##    s=list('abcdefghij'*100)
##    random.shuffle(s)
##    time0=time.time()
##    print solve(s),time.time()-time0
