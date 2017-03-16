#!/usr/bin/env python2.6

import sys
from copy import copy

"""
1000.000000 2 3
0.000000 20.500000
25.000000 1000.000000
1.00 5.00 9.81
"""


def checkCase(D, ocar, acc):
    "Checks one case"
    
    # init result
    T = 0
    
    # init our position
    wD = 0
    wV = 0
    
    # init current other car position
    ocurrent = ocar[0]
    del ocar[0]
    
    # iterate by other car positions
    dT = 0
    dD = 0
    for onext in ocar:
        # calculate delta T and delta D
        dT = onext[0] - ocurrent[0]
        dD = onext[1] - ocurrent[1]
    
        # calculate velocity of other car
        oV = dD / dT
        
        # check if other car gone below home
        if onext[1] > D:
            _t = (D - ocurrent[1]) / oV
            onext = [ocurrent[0] + _t, D]
            
            # calculate delta T and delta D
            dT = onext[0] - ocurrent[0]
            dD = onext[1] - ocurrent[1]
        
        # calculte our way during this period of time
        dwD = wV*dT + 0.5 * acc * dT**2
        
        # if we behind other - ok
        if (wD+dwD) <= onext[1]:
            wD += dwD
            wV += acc * dT
            T += dT
            
        # if we in front - impossible - shift us back
        else:
            wD = onext[1]
            wV = oV
            T += dT
    
        # substitute
        ocurrent = onext
        
    # if w haven't reached home yet
    if wD < D:
        leftD = D - wD
        #print "LEFT %.4fm, V = %.4f, ACC = %.4f, SPENT = %.4f" % (leftD, wV, acc, T)
        _d = (wV**2 + 2 * acc * leftD)
        _t = (-wV + _d**0.5) / acc
        T += _t
    
    return T


# get number of cases
num = int(sys.stdin.readline())

# iterate over cases
for t in xrange(num):
    # read case info
    (D, N, A) = sys.stdin.readline().split(' ')
    D = float(D)
    N = int(N)
    A = int(A)
    
    # read other car info
    ocar = []
    for row in xrange(N):
        row = [float(i) for i in sys.stdin.readline().split(' ')]
        ocar.append(row)
        
    # read accelerations
    acc = [float(i) for i in sys.stdin.readline().split(' ')]
    
    print "Case #%d:" % (t+1)
    for a in acc:
        print "%.8f" % checkCase(D, copy(ocar), a)

    