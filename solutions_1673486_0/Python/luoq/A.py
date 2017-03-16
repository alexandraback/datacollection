#!/usr/bin/env python
import sys
def minEL(A,B,P):
    L0=B+2
    L=range(A+1)
    Q=range(A+1)
    Q[0]=1.0
    L[0]=A+B+1
    for i in range(1,A+1):
        Q[i]=Q[i-1]*P[i-1]
        L[i]=(A+B+1-2*i)+(B+1)*(1-Q[i])
    return min(min(L),L0)
        
if __name__=="__main__":
    fname1=sys.argv[1]
    fname2=fname1+".out"
    f1=open(fname1)
    f2=open(fname2,"w")

    f1.readline()
    i=1
    step=0
    for line in f1:
        if step==0:
            input=[int(x) for x in line.split()]
            A=input[0]
            B=input[1]
            step=1
        elif step==1:
            P=[float(x) for x in line.split()]
            output=minEL(A,B,P)
            f2.write("Case #"+str(i)+": "+
                     str(output)+"\n")
            i+=1
            step=0
    f1.close()
    f2.close()
