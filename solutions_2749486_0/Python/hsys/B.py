#!/usr/bin/python

T = int(raw_input())

for t in xrange(1, T + 1) :
    y, x = [ int(i) for i in raw_input().split() ]
    s = ''
    if x > 0 :
        s += 'SN' * x
    else :
        s += 'NS' * (-x)
    if y > 0 :
        s += 'WE' * y
    else :
        s += 'EW' * (-y)

    print 'Case #%d: %s' % (t, s)
