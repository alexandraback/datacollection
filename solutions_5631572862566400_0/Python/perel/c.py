import time
##import sys
##sys.setrecursionlimit(10002)

def solve(n,m):
    m=[0]+m
    mm=[[] for i in range(n+1)]
    used=[0]*(n+1)
    couple=[]
    for i in range(1,n+1):
        if m[m[i]]==i and i<m[i]:
            couple.append((i,m[i]))
        mm[m[i]].append(i)
    ans=0

    for i,j in couple:
        tans=0
        mm[i].remove(j);mm[j].remove(i)
        step=0
        ltask=[i]
        while ltask:
            step+=1
            lnew=[]
            for k in ltask:
                used[k]=1
                lnew.extend(mm[k])
            ltask=lnew
        tans+=step
        step=0
        ltask=[j]
        while ltask:
            step+=1
            lnew=[]
            for k in ltask:
                used[k]=1
                lnew.extend(mm[k])
            ltask=lnew
        tans+=step
        if tans>ans:
##            print i,j,tans,ans
            ans=tans
##    return ans
    ans+=len(couple)*2-2
    tans=0
    while 1:
        l=[i for i in range(1,n+1) if not used[i] and mm[i]]
        if len(l)<=tans:
##            print ans,tans,couple
            return max(ans,tans+len(couple)*2)
        step=1
        order=[0]*1001
        las=l[0]
        used[las]=1
        order[las]=step
        while 1:
            nex=m[las]
            step+=1
            if order[nex]:
                tans=max(tans,step-order[nex])
                break
            elif used[nex]:
                break
            else:
                order[nex]=step
                used[nex]=1
                las=nex

    return m

def main():
    fi=file('cs.in')
    fo=file('c.out','w')
    time0=time.time()
    t=int(fi.readline())
    for ti in range(t):
        time1=time.time()
        n=int(fi.readline())
        m=map(int,fi.readline().split())
        ans="Case #%d: %s"%(ti+1,solve(n,m))
        print ans,"%.3f"%(time.time()-time1)
        fo.write(ans+'\n')
    print "%.3f"%(time.time()-time0)
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
