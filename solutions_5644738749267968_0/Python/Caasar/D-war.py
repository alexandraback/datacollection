# -*- coding: utf-8 -*-
"""
Created on Sat Feb 15 18:33:33 2014

@author: Caasar
"""

from sys import stdin
import numpy as np

T = int(stdin.next())
for t in xrange(1,T+1):
    N = int(stdin.next())
    weights0 = np.fromstring(stdin.next(),sep=" ")
    weights1 = np.fromstring(stdin.next(),sep=" ")
    
    ind = np.argsort(np.r_[weights0,weights1])

    # fair war
    bricks = 1+(ind>=N)
    order1 = np.flatnonzero(bricks==1).tolist()
    fair_wins = 0
    for n in xrange(N):
        naomi = order1.pop()
        sel = np.flatnonzero(bricks[naomi:]==2)
        if sel.size > 0:
            ken = naomi+sel[0]
        else:
            ken = np.flatnonzero(bricks[:naomi]==2)[0]
            fair_wins += 1
        bricks[ken] = bricks[naomi] = 0
        
    # dece. war
    bricks = 1+(ind>=N)
    order2 = np.flatnonzero(bricks==2).tolist()
    dece_wins = 0
    for n in xrange(N):
        ken = order2.pop()
        sel = np.flatnonzero(bricks[ken:]==1)
        if sel.size > 0:
            dece_wins += 1
            naomi = ken+sel[0]
        else:
            naomi= np.flatnonzero(bricks[:ken]==1)[0]
        bricks[ken] = bricks[naomi] = 0

    print 'Case #%d: %d %d' % (t,dece_wins,fair_wins)

    
