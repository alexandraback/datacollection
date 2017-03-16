fin=open("A-small-attempt0.in","r")
fout=open("A.out","w")
cas=int(fin.readline())
for caseno in xrange(1,cas+1):
    #print caseno
    dat=map(int,fin.readline().split())
    n=dat[0]
    j=dat[1:]
    x=sum(j)
    ans=[100*(2.0/n-i/((float)(x))) for i in j]
    #print ans
    good=True
    bestsofar=n
    while(good):
        good=False
        extra=0.0
        stillin=n
        for i in xrange(n):
            if ans[i]<=0:
                extra-=ans[i]
                ans[i]=0
                good=True
                stillin-=1
        for i in xrange(n):
            if(ans[i]>0):
                ans[i]-=extra/stillin
        if(bestsofar==stillin):
            good=False
        bestsofar=stillin
    #print ans
    fout.write("Case #"+str(caseno)+": "+" ".join(map(str,ans))+"\n")

fin.close()
fout.close()
