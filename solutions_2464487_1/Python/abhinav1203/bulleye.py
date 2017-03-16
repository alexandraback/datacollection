import math
from decimal import *
t=int(raw_input(""))
for i in range(1,t+1):
    stri=raw_input("")
    r,t=(str(j) for j in stri.split(' '))
    r=int(r)
    t=int(t)
    lo=1
    hi=1000000000
    ans=1
    while lo<=hi:
        mid=(lo+hi)>>1
        val=2*mid*mid+mid*(2*r-1)-t
        if val<=0:
            ans=mid
            lo=mid+1
        else:
            hi=mid-1
    stri="Case #"+str(i)+": "+str(ans)
    print stri


