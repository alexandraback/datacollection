# -*- coding: utf-8 -*-
"""
Created on Sat Feb 15 18:33:33 2014

@author: Caasar
"""

from sys import stdin
import numpy as np
from scipy.signal import convolve2d

charmap = np.array(['.','*','c'])
mask = np.ones((3,3),np.int)

T = int(stdin.next())
for t,line in enumerate(stdin,1):
    R,C,M = np.fromstring(line,sep=" ",dtype=np.int)
    
    conf = np.ones((R,C),dtype=np.int)
    conect = np.zeros((R,C),dtype=np.bool)
    cost = 9*np.ones((R,C),dtype=np.int)
    if R > 1 and C > 1:
        cost[0,:] = 6
        cost[-1,:] = 6
        cost[:,0] = 6
        cost[:,-1] = 6
        cost[0,0] = cost[0,-1] = cost[-1,0] = cost[-1,-1] = 4
    elif R==1 and C > 1:
        cost[0,:] = 3
        cost[0,0] = cost[0,-1] = 2
    elif R>1 and C==1:
        cost[:,0] = 3
        cost[0,0] = cost[-1,0] = 2
    elif R==1 and C==1:
        cost[0,0] = 1
    
    free = R*C-M

    if free == 1:
        free = 0
        
    mincost, row, col = cost[0,0], 0, 0
    while mincost <= free:
        rs = np.maximum(0,row-1)
        cs = np.maximum(0,col-1)
        
        change = np.zeros((R,C),np.int)
        change[rs:row+2,cs:col+2] = conf[rs:row+2,cs:col+2]
        change = convolve2d(change,mask,mode='same')
        
        conect[rs:row+2,cs:col+2] = True
        conf[rs:row+2,cs:col+2] = 0
        cost -= change
        cost[row,col] = 10
        free -= mincost
        
        # first check a if field matches exactly
        if free < 5:
            rows,cols = np.nonzero((cost==free)&conect)
            if rows.size > 0:
                row = rows[0]
                col = cols[0]
            else:
                ind = np.argmin(cost)
                row, col = int(ind/C), ind%C
        else:
            ind = np.argmin(cost)
            row, col = int(ind/C), ind%C
        mincost = cost[row,col]
        

    conf[0,0] = 2
    print 'Case #%d:' % (t,)
    if free > 0:
        print 'Impossible'
    else:
        for row in charmap[conf]:
            print ''.join(row)
