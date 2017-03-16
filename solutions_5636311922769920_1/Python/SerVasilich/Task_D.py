fi=open("D-large.in"); fo=open("D-large.out","w")
#fi=open("D-small-attempt0.in"); fo=open("D-small-attempt0.out","w")

def fnd(k,c,s):
    ans=[]
    t=cc=d=1
    while t<=k: 
        if cc==c: 
            ans+=[str(d)]
            if t==k: break
        if t<k: t+=1 
        if cc==c: d=t; cc=1
        else: d=d*k-k+t; cc+=1
    return "IMPOSSIBLE" if len(ans)>s else ' '.join(ans)

for T in range(int(fi.readline())):
    k,c,s=map(int,fi.readline().split())
    print("Case #"+str(T+1)+":",fnd(k,c,s),file=fo)

fi.close()
fo.close()
print("OK")