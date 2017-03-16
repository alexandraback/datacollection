# 2013A1 A

from math import pi,floor
from gmpy import sqrt

T = int(input())

def areaOfDisk(r):
    return (2*r+1)

for a in range(T):
    rt=input()
    rt=rt.split(' ')
    r=int(rt[0])
    t=int(rt[1])

    ans = floor((sqrt(4*pow(r,2)-4*r+8*t+1)-2*r+1)/4)
    
    print('Case #'+str(a+1)+': '+str(ans))
