##import sys
##sys.setrecursionlimit(10002)

def solve(n,m,city,flight):
    city=['0']+city
    c=sorted([(city[i],i) for i in range(n+1)])
    f=[[] for i in range(n+1)]
    for fi in flight:
        f[fi[0]].append(fi[1])
        f[fi[1]].append(fi[0])
    #f[0]=range(1,n+1)
##    print f,c
    f=[[]]+[sorted(li,key=lambda x:city[x]) for li in f if li]
    used=[0]*(n+1)
    lc=[];stack=[]
    for ci in c[1:]:
##        if used[ci]:
##            continue
        if dfs(ci[1],n,m,c,city,f,lc,stack,used):
            break
    ans=[city[li] for li in lc]
    return ''.join(ans)

def dfs(cin,n,m,c,city,f,lc,stack,used):
    lc.append(cin);used[cin]=1;st=stack+[cin]
    if len(lc)==n:
        return True
##    print st
    tmp=sum([[(li,si) for li in f[si]] for si in st],[])
    for ci in sorted(tmp,key=lambda x:(city[x[0]],-st.index(x[1])) ):
        if used[ci[0]]:
            continue
        st1=st[:]
        while ci[1]<>st1[-1]:
            del st1[-1]
        if dfs(ci[0],n,m,c,city,f,lc,st1,used):
            return True
    del lc[-1];used[cin]=0
    return False


def main():
    fi=file('cs.in')
    fo=file('c.out','w')
    t=int(fi.readline())
    for ti in range(t):
        n,m=map(int,fi.readline().split())
        city=[];flight=[]
        for i in range(n):
            city.append(fi.readline()[:-1])
        for i in range(m):
            flight.append(map(int,fi.readline().split()))
        ans="Case #%d: %s"%(ti+1,solve(n,m,city,flight))
        print ans
        fo.write(ans+'\n')
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
