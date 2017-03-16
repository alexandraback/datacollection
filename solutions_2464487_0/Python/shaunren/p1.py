#!/usr/bin/python -SOO
for case in range(1,int(input())+1):
    r,t = map(int,input().strip().split())
    print('Case #{}: {}'.format(case,int(((4*r*r-4*r+8*t+1)**0.5-2*r+1)/4)))
