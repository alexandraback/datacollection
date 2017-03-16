#!/usr/bin/env python
from sets import Set
import sys
# Say n~m if (n,m) is recycled.Obviously ~ is an equivalent relation
# So we just partition a set of numbers S by ~.
# The number of pairs is \sum{i\in I}C_{|P_i|}^2,
# if P={P_i|i\in I} is the partition
def Class(x):
    C=Set()
    C.add(x)
    sx=str(x)
    for i in range(1,len(sx)):
        if sx[i]!="0":
            b=sx[i:]+sx[0:i]
            C.add(int(b))
    return C
def Partition(X):
    P=[]
    while X:
        x=X.pop()
        C=Class(x)
        C &= X
        X -= C
        C.add(x)
        P.append(C)
    return P
def CountPair(P):
    if not(P):
        return 0
    n=0
    for C in P:
        l=len(C)
        n+=l*(l-1)/2
    return n
if __name__=="__main__":
    fname1=sys.argv[1]
    fname2=fname1+".out"
    f1=open(fname1)
    f2=open(fname2,"w")
    f1=open(fname1)
    f2=open(fname2,"w")

    f1.readline()
    i=1
    for line in f1:
        input=[int(x) for x in line.split()]
        A=input[0]
        B=input[1]
        output=CountPair(Partition(Set(range(A,B+1))))
        f2.write("Case #"+str(i)+": "+
                 str(output)+"\n")
        i+=1
    f1.close()
    f2.close()
