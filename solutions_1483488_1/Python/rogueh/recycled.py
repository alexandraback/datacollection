cases=int(input())
for case in range(1,cases+1):
    a=input().split()
    s=int(a[0])
    e=int(a[1])
    d={}
    c=0
    for i in range(s,e+1):
        no=str(i)
        for j in range(1,len(no)):
            nno=int(no[j:]+no[:j])
            if nno>=s and nno<=e:
                if nno==i:
                    continue
                if i<nno:
                    if i not in d:
                        d[i]=[nno]
                        c+=1
                    elif nno not in d[i]:
                        d[i]+=[nno]
                        c+=1
                else:
                    if nno not in d:
                        d[nno]=[i]
                        c+=1
                    elif i not in d[nno]:
                        d[nno]+=[i]
                        c+=1
    print("Case #",case,": ",c,sep='')
    
