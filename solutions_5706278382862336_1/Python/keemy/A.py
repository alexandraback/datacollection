from math import *
from fractions import gcd
import numpy as np
from collections import OrderedDict

#prob=(open('A-small-attempt0.in','r'))
prob=(open('A-large.in','r'))
out=[]

T=int(prob.readline())

    
def solution():
    n,d=(int(i) for i in prob.readline().split("/"))

    g=gcd(n,d)
    n/=g
    d/=g

    if not ( d  and (not (d & (d - 1)))):
        return "impossible"

    return str(int(log(d,2) - (int(log(n,2)))))

    

for t in xrange(1,T+1):
    


    out.append("Case #%d: "%(t)+ solution())
    #print solution()


#f=open('A-small.out','w')
f=open('A-large.out','w')
f.write("\n".join(out))
f.close()
