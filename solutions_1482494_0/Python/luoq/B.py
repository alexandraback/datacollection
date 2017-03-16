#!/usr/bin/env python
import sys
def minStep(a,b):
    star=0
    n=len(a)
    L0=range(n)
    L1=[]
    step=0
    while len(L0)!=0 or len(L1)!=0:
        #print 1,star,L0
        index=[]
        for i in range(len(L0)):
            if(b[L0[i]]<=star):
                index.append(i)
                star+=2
                step+=1
        if len(index)>0:
            index.reverse()
            for i in index:
                del L0[i]
            continue
        
        #print 2,star,L1
        index=[]
        for i in range(len(L1)):
            if(b[L1[i]]<=star):
                index.append(i)
                star+=1
                step+=1
        if len(index)>0:
            index.reverse()
            for i in index:
                del L1[i]
            continue

        #print 3,star,L0
        i=0
        while i<len(L0):
            if(a[L0[i]]<=star):
                break
            i+=1
        if i<len(L0):
            star+=1
            step+=1
            L1.append(L0[i])
            del L0[i]
        else:
            return "Too Bad"
    return step
        
if __name__=="__main__":
    fname1=sys.argv[1]
    fname2=fname1+".out"
    f1=open(fname1)
    f2=open(fname2,"w")

    T=int(f1.readline().split()[0])
    for i in range(1,T+1):
        N=int(f1.readline().split()[0])
        a=range(N)
        b=range(N)
        for j in range(N):
            line=f1.readline()
            input=[int(x) for x in line.split()]
            a[j]=input[0]
            b[j]=input[1]
        output=minStep(a,b)
        f2.write("Case #"+str(i)+": "+
                 str(output)+"\n")
    f1.close()
    f2.close()
