##import sys
##sys.setrecursionlimit(10002)

def solve(a,b,k):
    c=0
    for i in range(a):
        for j in range(b):
            #print i,j,i&j
            if (i&j)<k:
                c+=1
    return c

def main():
    fi=file('bs.in')
    fo=file('b.out','w')
    t=int(fi.readline())
    for ti in range(t):
        a,b,k=map(int,fi.readline().split())
        ans="Case #%d: %s"%(ti+1,solve(a,b,k))
        print ans
        fo.write(ans+'\n')
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
