import time
##import sys
##sys.setrecursionlimit(10002)

fmax=lambda x:x.replace('?','9')  #['9' if i=='?' else i for i in x]
fmin=lambda x:x.replace('?','0')  #['0' if i=='?' else i for i in x]
##fcal=lambda x:int(''.join(x))
def solve(c,j):
    return ' '.join(solve1(c,j))

def solve1(lc,lj):
    if len(lc)==1:
        if lc==lj=='?':
            return '0','0'
        elif lc=='?':
            return lj,lj
        elif lj=='?':
            return lc,lc
        else:
            return lc,lj
    i=0
    if lc[i]==lj[i]=='?':
        t=solve1(lc[i+1:],lj[i+1:])
        r0=['0'+t[0],'0'+t[1]]
        r1=['0'+fmax(lc[i+1:]),'1'+fmin(lj[i+1:])]
        r2=['1'+fmin(lc[i+1:]),'0'+fmax(lj[i+1:])]
        _,lc,lj=min([[abs(int(a)-int(b)),a,b] for a,b in (r0,r1,r2)])
    elif lc[i]=='?':
        t=solve1(lc[i+1:],lj[i+1:])
        r0=[lj[i]+t[0],lj[i]+t[1]]
        if lj[i]=='0':
            r1=r0
        else:
            r1=[str(int(lj[i])-1)+fmax(lc[i+1:]),lj[i]+fmin(lj[i+1:])]
        if lj[i]=='9':
            r2=r0
        else:
            r2=[str(int(lj[i])+1)+fmin(lc[i+1:]),lj[i]+fmax(lj[i+1:])]
        _,lc,lj=min([[abs(int(a)-int(b)),a,b] for a,b in (r0,r1,r2)])
    elif lj[i]=='?':
        t=solve1(lc[i+1:],lj[i+1:])
        r0=[lc[i]+t[0],lc[i]+t[1]]
        if lc[i]=='0':
            r1=r0
        else:
            r1=[lc[i]+fmin(lc[i+1:]),str(int(lc[i])-1)+fmax(lj[i+1:])]
        if lc[i]=='9':
            r2=r0
        else:
            r2=[lc[i]+fmax(lc[i+1:]),str(int(lc[i])+1)+fmin(lj[i+1:])]
##        print r0,r1,r2
        _,lc,lj=min([[abs(int(a)-int(b)),a,b] for a,b in (r0,r1,r2)])
    elif lc[i]<lj[i]:
        lc=lc[i]+fmax(lc[i+1:])
        lj=lj[i]+fmin(lj[i+1:])
    elif lc[i]>lj[i]:
        lc=lc[i]+fmin(lc[i+1:])
        lj=lj[i]+fmax(lj[i+1:])
    else:
        t=solve1(lc[i+1:],lj[i+1:])
        lc,lj=lc[i]+t[0],lj[i]+t[1]
    return lc,lj

def main():
    fi=file('bs.in')
    fo=file('b.out','w')
    time0=time.time()
    t=int(fi.readline())
    for ti in range(t):
        time1=time.time()
        c,j=fi.readline().split()
        ans="Case #%d: %s"%(ti+1,solve(c,j))
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
