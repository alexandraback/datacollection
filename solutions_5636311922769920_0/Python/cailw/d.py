with open('d.txt') as f:
    fo=open('do.txt','w')
    f.readline()
    for t,ln in enumerate(f.readlines()):
        k,c,s=list(map(int,ln.split()))
        if (k-1)//c+1>s:
            print('Case #%d: IMPOSSIBLE'%(t+1),file=fo)
            continue
        ans=[]
        for i in range((k-1)//c+1):
            ds=(x%k for x in range(i*c,(i+1)*c))
            ret=1
            for j,d in enumerate(ds):
                ret+=d*k**j
            ans.append(ret)
        print('Case #%d:'%(t+1),*ans,file=fo)
fo.close()
