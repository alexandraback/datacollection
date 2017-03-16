from math import sqrt, floor
from decimal import Decimal

T = int(input())

def intsqrt(n):
    m = 1
    M = n
    while (m<M-1):
        mid = (m+M)//2
        if mid**2>n:
            M = mid
        else:
            m = mid
    return m

for case in range(1,T+1):
    r,t = [int(x) for x in input().split()]
    # print(((2*r-Decimal(1))**2+8*t).sqrt()) #-2*r+Decimal(1))
    ans = (intsqrt((2*r-1)**2+8*t)-2*r+1)//4
    print('Case #',case,': ',ans,sep='')
