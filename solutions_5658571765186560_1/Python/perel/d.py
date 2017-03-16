import time
def solve(x,r,c):
    if r<c:
        r,c=c,r
    if r*c%x or x>r or (x+1)/2>c or x>=7:
        return 'RICHARD'
    if x in (1,2,3):
        return 'GABRIEL'
    elif x==4:
        if c>2:
            return 'GABRIEL'
        else:
            return 'RICHARD'
    else:
        if c>3:
            return 'GABRIEL'
        else:
            return 'RICHARD'

def main():
    fi=file('dl.in')
    fo=file('d.out','w')
    time0=time.time()
    t=int(fi.readline())
    for ti in range(t):
        time1=time.time()
        x,r,c=map(int,fi.readline().split())
        ans="Case #%d: %s"%(ti+1,solve(x,r,c))
        print x,r,c,ans,"%.3f"%(time.time()-time1)
        fo.write(ans+'\n')
    print "%.3f"%(time.time()-time0)
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
