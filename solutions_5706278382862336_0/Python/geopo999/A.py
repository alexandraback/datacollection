from math import *
from fractions import gcd

T=int(input())
for caseNum in range(1,T+1):
    (P,Q)=map(int,input().split('/'))
    gc=gcd(P,Q)
    P//=gc
    Q//=gc
    if (Q & (Q-1) != 0):
        print("Case #"+str(caseNum)+": impossible")
        continue
    res=int(log(Q,2))-int(log(P,2))
    print("Case #"+str(caseNum)+": "+str(res))
        
    