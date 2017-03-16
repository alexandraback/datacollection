# -*- coding: UTF-8 -*-
"""
Problem Statement:


   


   Analysis: Essentially a ....


   1: 
   2: 
   3: 
   

"""

import sys

ntc = int(sys.stdin.readline().strip())

spread_make = {
        0 : lambda tp: [ tp/3 for _ in range(3) ], 
        1 : lambda tp: [ tp/3, tp/3, tp/3+1 ],
        2 : lambda tp: [ tp/3, tp/3+1, tp/3+1 ]
        }

def possmp(spread, p, d3):
    #print spread
    #print p
    if d3 is 0:
        if(spread[0] == 0 or spread[0] == 10):
            #noo adjustments possible
            return False
        elif(spread[2] + 1 == p):
            return True
    elif d3 is 1:
            return False
    else: #d3 is 2
        if(spread[1] == 0 or spread[1] == 10):
            #noo adjustments possible
            return False
        elif(spread[2] + 1 == p):
            return True

            

#best result
def maxp(tpl, s, p):
    maxp = 0
    for tp in tpl:
        d3 = tp % 3
        spread = spread_make[d3](tp)
        midmaxp = spread[2]
        if(midmaxp >= p):
            maxp += 1
        elif(midmaxp == p-1 and s != 0):
            if(possmp(spread,p,d3) is True):
                #print "possmp called"
                maxp += 1
                s -= 1
    return maxp


for nt in range(1,ntc+1):
    inlist = list(map(int,sys.stdin.readline().strip().split(" ")))
    n = inlist[0]
    s = inlist[1]
    p = inlist[2]
    tpl = []
    for i in xrange(3,3+n):
        tpl.append(inlist[i])
    print "Case #%d: %d" % (nt, maxp(tpl,s,p))

    #print n,s,p
    #print tpl

