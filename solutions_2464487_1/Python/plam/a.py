#!/usr/bin/python

import sys

data = file( sys.argv[1] ).read().splitlines()

l = data.pop( 0 )
N = int(l)

def calc( r, t ):
    amt = 0
    rings = 0
    while amt < t and r >= 1:
#        print amt, r
        amt += (2*r) + 1
        if amt > t:
            break
        r += 2
        ans = amt
        rings += 1
    return rings

def paint( r ):
    if r < 0:
        return 0
    if r == 0:
        return 1
    if r == 1:
        return 3
    if r == 2:
        return 6
    t = int((r+2)/2)
#    print 't', t
    area = (2*r*t) + t - (4*(((t-1)*t)/ 2))
    return area

def calc2( r, t ):
    amt = 0
    rings = 0
    minarea = paint(r-2)
    while amt < t and r >= 1:
#        print amt, r
        amt = paint(r) - minarea
        if amt > t:
            break
        r += 2
        rings += 1
    return rings

#for i in range(0,10):
#    print i, paint(i)
#exit(0)
#print paint(1000000000000000000)
#exit(0)
def calc3( r, t ):
    maxr = 1000000000000000000
    minr = 0
    minpaint = paint(r-2)
    curr = maxr
    lastr = 0
    while True:
        curr = int((maxr + minr) / 2)
        amt = paint(curr) - minpaint
        
        if amt > t:
            maxr = curr
            if lastr == curr:
                break
            lastr = curr
            continue
        if amt < t:
            minr = curr
            if lastr == curr:
                break
            lastr = curr
        if amt == t:
            break
    # check parity
    curr -= 10
    if (r % 2) != (curr %2):
        curr += 1
    amt = paint(curr) - minpaint
    while amt < t:
        amt = paint(curr) - minpaint
        if amt > t:
            break
        curr += 2
        
    ring = ( curr - r ) / 2
    return ring

for CASE in range(1,N+1):
    print 'Case #%d:' % CASE,
    l = data.pop( 0 )
    r, t = l.split(' ')
    r=int(r)
    t=int(t)
#    print r, t
#    a = calc(r,t)
#    b = calc2(r,t)
    c = calc3(r,t)
#    if a != c:
#        print r, t
#        print a, c
#        assert a == c
    print c





