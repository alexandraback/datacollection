with open('a.txt') as f:
    fo=open('ao.txt','w')
    f.readline()
    for i,ln in enumerate(f.readlines()):
        s=set()
        n=int(ln)
        if n==0:
            print('Case #%d: INSOMNIA'%(i+1),file=fo)
            continue
        cnt=0
        while len(s)<10:
            cnt+=n
            for c in str(cnt):
                s.add(c)
        print('Case #%d: %d'%(i+1,cnt),file=fo)
fo.close()

        
