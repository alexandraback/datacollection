from itertools import *
from math import *

def bt(e,r,n,v,en=None,sc=0,l=[]):
    
    if en==None:
        en=e
    if len(l)==n:
        # print sc,l
        return sc,l
    maxx=0,[0]*len(l)
    for i in range(en+1):
        sc2,l2=bt(e,r,n,v,min(max(0,en-i+r),e),sc+i*v[len(l)],l+[i])
        if sc2>=maxx[0]:
            maxx=sc2,l2
    return maxx
        

for i in range(int(raw_input())):
    print"Case #"+str(i+1)+":",
    e,r,n=map(int,raw_input().split())
    v=map(int,raw_input().split())
    print bt(e,r,n,v)[0]
