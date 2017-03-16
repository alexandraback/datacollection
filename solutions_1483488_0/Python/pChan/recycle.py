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

def pairfind(n,maxm):
    strn = str(n)
    #print "strn is %s" % strn
    pcount = 0

    tl = []
    seen = set()
    for i in xrange(len(strn)-1):
        m = int(strn[i+1:] + strn[0:i+1])
        #print "%d Gen %d " % (int(strn),m),
        if(m > n and m <= maxm):
            if m not in seen:
                pcount += 1
                seen.add(m)
            #else:
                #print "Duplicate %d" % m

    return pcount

for nt in range(1,ntc+1):
    inlist = list(map(int,sys.stdin.readline().strip().split(" ")))
    a = inlist[0]
    b = inlist[1]

    mpcount = 0
    for pn in xrange(a,b):
        mpcount += pairfind(pn,b)
        

    print "Case #%d: %d" % (nt,mpcount)
