#fi=open("C-large.in"); fo=open("C-large.out","w")
fi=open("C-small-attempt4.in"); fo=open("C-small-attempt4.out","w")

from collections import *
        
def fnd():
    J,P,S,K=map(int,fi.readline().split())
    c=Counter()
    d=Counter()
    
    while True:
      a=(K,K,K)
      jj=pp=ss=0
      for j in range(1,J+1):
        for p in range(1,P+1):
            for s in range(1,S+1):
                if max(c[(1,j,2,p)],c[(1,j,3,s)],c[(2,p,3,s)])==K or d[j,p,s]>0: continue
                if min(c[(1,j,2,p)],c[(1,j,3,s)],c[(2,p,3,s)])<min(a):
                    a=(c[(1,j,2,p)],c[(1,j,3,s)],c[(2,p,3,s)]); jj=j; pp=p; ss=s
      if (jj==0): break
      c[(1,jj,2,pp)]+=1; c[(1,jj,3,ss)]+=1; c[(2,pp,3,ss)]+=1
      d[jj,pp,ss]=1
                
    ans=[str(len(d))]
    for k in d: ans+=[' '.join(map(str,k))]
    return '\n'.join(ans)
    
for T in range(int(fi.readline())):     
    print("Case #"+str(T+1)+":",fnd(),file=fo)
    
fi.close()
fo.close()
print("OK")