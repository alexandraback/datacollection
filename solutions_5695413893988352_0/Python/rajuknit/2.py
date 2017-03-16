import copy
def abc(a,b,c,d):
    z=[]
    if b==0:
        return [int(''.join(a))]
    if b==1:
        for i in (d):
            a[c[0]]=i
            z.append(int(''.join(a)))
    if b==2:
        for i in (d):
            x=copy.copy(a)
            x[c[0]]=i
            for j in (d):
                x[c[1]]=j
                z.append(int(''.join(x)))
    if b==3:
            for i in d:
                a[c[0]]=i
                for j in d:
                    a[c[1]]=j
                    for k in d:
                        a[c[2]]=k
                        z.append(int(''.join(a)))
    return z
            
        


t=int(raw_input())
iii=1
while t>0:
    c,j=raw_input().split()
    cl=c
    jl=j
    c=list(c)
    j=list(j)
    d=["0","1","2","3","4","5","6","7","8","9"]
    c1=c.count("?")
    c2=[]
    p=0
    while 1:
        x=cl[p:].find("?")
        if x==-1:
            break
        else:
            c2.append(x+p)
            p=p+x+1
    c3=abc(c,c1,c2,d)
    j1=j.count("?")
    j2=[]
    p=0
    while 1:
        x=jl[p:].find("?")
        if x==-1:
            break
        else:
            j2.append(x+p)
            p=p+x+1
    j3=abc(j,j1,j2,d)
    mn=102328346823
    ii=0
    jj=0
    #print(c3)
    #print(j3)
    for i in range(len(c3)):
        for j in range(len(j3)):
            if abs(c3[i]-j3[j])<mn:
                mn=abs(c3[i]-j3[j])
                ii=i
                jj=j
    x="0"*(len(cl)-len(str(c3[ii])))+str(c3[ii])
    y="0"*(len(jl)-len(str(j3[jj])))+str(j3[jj]) 
           
    print("Case #"+str(iii)+": "+x+" "+y)
    iii+=1
    t-=1
