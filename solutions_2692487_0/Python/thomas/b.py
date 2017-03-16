import math
import copy

def demo():
    a=open("A.in")
    b=a.readlines()
    outf=open("out.txt","w")
    
    
    for i in range(int(b[0])):
        A,N=b[i*2+1].split(" ")
        motes=b[i*2+2][:-1].split(" ")
        
        res=check(A,motes)
                
        print "Case #"+str(i+1)+": "+str(res)
        outf.write("Case #"+str(i+1)+": "+str(res)+"\n")
    outf.close()

A=0

def f(x): return x<A


def check(B,motes):
    print "\n"
    global A
    A=int(B)
    for k in range(len(motes)):
        motes[k]=int(motes[k])
    motes.sort()
    print A,motes

    while len(filter(f,motes))>0:
        q=filter(f,motes)
        A+=sum(q)
        motes=motes[len(q):]

    print A,motes
    best = len(motes)

    if best<=1: return best

    hypb=0

    while hypb<best and len(motes)>0:
        hypb+=1
        motes=motes+[A-1]
        motes.sort()
        print A, motes
        while len(filter(f,motes))>0:
            q=filter(f,motes)
            A+=sum(q)
            motes=motes[len(q):]
        if hypb+len(motes)<best:
            best=hypb+len(motes)

    if best<hypb:
        hypb=best

    return hypb


raw_input("Got data?")
demo()