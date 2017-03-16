#!/usr/bin/python -SOO
from decimal import *
for case in range(1,int(input())+1):
    r,t = map(int,input().strip().split())
    x = int(((4*r*r-4*r+8*t+1)**0.5-2*r+1)/4)
    while x>=0 and (2*x*(x-1)+2*x*r+x)>t:
        x-=1
    print('Case #{}: {}'.format(case,x))
