from itertools import *

from math import *

def size(n,r):
    return sum((R+1)**2-R**2 for R in range(r,r+2*n,2))

for i in range(int(raw_input())):
    print "Case #"+str(i+1)+":",
    r,t=map(int,raw_input().split())
    s=0
    # print size(s,r),s,r
    while size(s,r)<=t:
        s+=1
    print max(1,s-1)
