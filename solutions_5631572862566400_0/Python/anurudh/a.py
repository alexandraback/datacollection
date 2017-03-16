t=input()
fin=[]
v=[]
def trav(i,at,v):
    try:
        lol=at.index(v[i])
        at.append(i)
        return at
    except:
        at.append(i)
        return trav(v[i],at,v)
for i in range(t):
    n=input()
    ma=[]
    v= [(int(s)-1) for s in raw_input().split(" ")] 
    for j in range(len(v)):
        at=[]
        fin.append(trav(j,at,v))
    maxi=0
    tra=[]
    for j in fin:
        if len(j)>maxi: 
            maxi=len(j)
            tra=j        
    while True:
        li=len(tra)
        l=tra[len(tra)-1]
        fin2=[]
        for j in fin:
            if not(j==tra):
                try:
                    lol=j.index(l)
                    ro=list(reversed(j[:j.index(l)]))
                    if set(tra).intersection(ro)==NULL:
                        fin2.append(ro)
                except:
                    continue
        maxi=0
        tra2=[]
        for k in fin2:
            if len(k)>maxi: 
                maxi=len(k)
                tra2=k
        tra=tra+tra2
        if(li==len(tra)): 
            break 
    print "Case #"+str((i+1))+":",tra
  
    print ""
