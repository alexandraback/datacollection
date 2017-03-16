title='b'

with open('%s.txt'%title) as fi, open('%s_o.txt'%title,'w') as fo:
    def readint():
        return int(fi.readline().strip())
    def readints():
        return list(map(int,fi.readline().split()))
    t=readint()
    for icase in range(1,t+1):
        def print_case(*args):
            print('Case #%d:'%icase,*args,file=fo)
        n=readint()
        d={}
        for _ in range(2*n-1):
            ls=readints()
            for h in ls:
                if d.get(h) is None:
                    d[h]=0
                else:
                    d[h]+=1
        ans=[]
        for h,cnt in d.items():
            if cnt%2==0:
                ans.append(h)
        print_case(*sorted(ans))
