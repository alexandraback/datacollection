from itertools import permutations

title='c'

with open('%s.txt'%title) as fi, open('%s_os.txt'%title,'w') as fo:
    def readint():
        return int(fi.readline().strip())
    def readints():
        return list(map(int,fi.readline().split()))
    t=readint()
    for icase in range(1,t+1):
        def print_case(*args):
            print('Case #%d:'%icase,*args,file=fo)
        n=readint()
        bff=readints()
        bff=[0]+bff
        ans=0
        for r in range(2,n+1):
            for p in permutations(range(1,n+1),r):
                ok=[False]*r
                ok[0]=p[1]==bff[p[0]] or p[-1]==bff[p[0]]
                ok[r-1]=p[r-2]==bff[p[r-1]] or p[0]==bff[p[r-1]]
                for i in range(1,r-1):
                    ok[i]=p[i-1]==bff[p[i]] or p[i+1]==bff[p[i]]
                if sum(ok)==r:
                    ans=r
                    break
        print_case(ans)
        fo.flush()
