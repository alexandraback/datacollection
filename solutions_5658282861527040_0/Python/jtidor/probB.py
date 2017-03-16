import re
import math

NUM_DIGITS=30
inp=open("B-small-attempt0.in","r")
outp=open("Bs_oupt.txt","w")
lines = inp.readlines()
lines=[re.sub('\n','',line) for line in lines]

d={}

def ans(a,b,k,i):
    if (a,b,k,i) in d:
        return d[(a,b,k,i)]
    else:
        x=real_ans(a,b,k,i)
        d[(a,b,k,i)]=x
        return x

def real_ans(a,b,k,i):
    if min(a,b,k)<=0:
        return 0
    if i==0:
        return 1
    return ans(a,b,k,i-1)+ans(a-2**(i-1),b,k,i-1)+ans(a,b-2**(i-1),k,i-1)+ans(a-2**(i-1),b-2**(i-1),k-2**(i-1),i-1)

k=int(lines.pop(0))
for i in range(k):
    l=re.split(' ',lines[i])
    outp.write("Case #"+str(i+1)+": "+str(ans(int(l[0]),int(l[1]),int(l[2]),NUM_DIGITS))+"\n")
outp.close()
