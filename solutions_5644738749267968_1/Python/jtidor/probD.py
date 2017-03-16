import re
import copy
import math

inp=open("D-large.in","r")
outp=open("Dl_oupt.txt","w")
lines = inp.readlines()
inp.close()

def solve(a,b,n,f):
    x=copy.copy(a)
    y=copy.copy(b)
    if len(x)!=n or len(y)!=n:
        print "len ERROR"
    x.append("inf")
    y.append("inf")
    m=0
    s=0
    while x[0]!=y[0]:
        if x[0]<y[0]:
            x.pop(0)
            s-=1
            m=f(m,s)
        elif x[0]>y[0]:
            y.pop(0)
            s+=1
            m=f(m,s)
    if not x[0]=="inf":
        print "ERROR"
    if f==min:
        return n+m
    elif f==max:
        return m
    else:
        print "function ERROR"

k=int(lines.pop(0))

for i in range(k):
    n=int(lines[3*i])
    a=re.sub("\n","",lines[3*i+1])
    b=re.sub("\n","",lines[3*i+2])
    a2=re.split(" ",a)
    b2=re.split(" ",b)
    a3=[float(num) for num in a2]
    b3=[float(num) for num in b2]
    a3.sort()
    b3.sort()
    outp.write("Case #"+str(i+1)+": "+str(solve(a3,b3,n,min))+" "+str(solve(a3,b3,n,max))+"\n")
outp.close()
