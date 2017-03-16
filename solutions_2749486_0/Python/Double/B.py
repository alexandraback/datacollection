#!/usr/bin/env python
import math
T=int(raw_input().strip())

for i in range(1, T+1):
    x, y = raw_input().strip().split()
    x, y=int(x), int(y)
    nx, ny=0, 0
    steps=''
    j=0
    while nx!=x or ny!=y:
        j+=1
        if abs(nx-x) >= j:
            if nx < x:
                nx = nx+j
                steps=steps+'E'
            elif nx >x:
                nx = nx-j
                steps=steps+'W'
        elif abs(ny-y) >=j:
            if ny < y:
                ny = ny+j
                steps=steps+'N'
            elif ny > y:
                ny = ny -j
                steps=steps+'S'
        elif abs(nx-x) < j and nx!=x:
            if nx < x:
                steps=steps+('WE'*(x-nx))
            else:
                steps=steps+('EW'*(nx-x))
            j+=abs(x-nx)*2-1
            nx=x
        elif abs(ny-y) < j and ny!=y:
            if ny < y:
                steps=steps+('SN'*(y-ny))
            else:
                steps=steps+('NS'*(ny-y))
            j+=abs(x-nx)*2-1
            ny=y

    print 'Case #%d: %s' % (i, steps)

