import copy
from collections import defaultdict
t=int(raw_input())
ii=1
while t>0:
    d=defaultdict(lambda:[])
    n=int(raw_input())
    b=[]
    for i in range(n+1):
        b.append(i)
    f=[0]
    f.extend([int(x) for x in raw_input().split()])
    for i in range(1,len(f)):
        d[f[i]].append(i)
    mx=0
    
    for i in range(1,len(b)):
        tmp=[i]
        while 1:
            if f[i] in tmp:
                break
            else:
                tmp.append(f[i])
                i=f[i]
        k=tmp[-1]        
        while 1:
            pp=0
            for j in d[k]:
                if j in tmp:
                    qq=0
                else:
                    tmp.append(j)
                    k=j
                    pp=1
                    break
            if pp==0:
                break
        m=len(tmp)
        for i in range(len(tmp)):
            if f[tmp[i]]!=tmp[(i+1)%m] and f[tmp[i]]!=tmp[i-1]:
                tmp=[]
                break
        if len(tmp)>mx:
            mx=len(tmp)
            o=copy.copy(tmp)
    #print(o)        

    r=mx    
    print("Case #"+str(ii)+": "+str(r))
    ii+=1
    t-=1
