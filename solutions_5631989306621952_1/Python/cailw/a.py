title='a'

with open('%s.txt'%title) as fi, open('%s_o.txt'%title,'w') as fo:
    def readint():
        return int(fi.readline().strip())
    def readints():
        return list(map(int,fi.readline().split()))
    t=readint()
    for icase in range(1,t+1):
        def print_case(*args):
            print('Case #%d:'%icase,*args,file=fo)
        s=fi.readline().strip()
        ans=""
        maxc=chr(0)
        for cs in s:
            maxc=max(maxc,cs)
            if maxc==cs:
                ans=cs+ans
            else:
                ans+=cs
        print_case(ans)
