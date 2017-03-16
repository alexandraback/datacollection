# -*- coding: utf-8 -*-
"""

@author: Robo
"""

import os
import numpy as np

folder = "D:/CODE/googlecodejam/fractiles"
infile = "D-small-attempt0.in"
outfile = "D-small-attempt0.out"


def read_gcj_input():
    cases = []
    with open(os.path.join(folder,infile), 'r') as f:
        for each in xrange(int(f.readline())):
            Araw = f.readline().strip()
            K,C,S = [int(i) for i in Araw.split(' ')]
            cases.append({'K': K, 'C': C, 'S':S})
    return cases
     
    
cases = read_gcj_input()


with open(os.path.join(folder,outfile), 'w') as f:
    for index,case in enumerate(cases):
        K = case['K']
        C = case['C']
        S = case['S']
#        totalTiles = K**C
        minTiles = K/C + (1 if K%C else 0)
        solu = list(range(minTiles))

        if S<minTiles:
            result = 'IMPOSSIBLE'
        else: 
            count=1
            for i in xrange(minTiles):
                thispos=0
                for Clevels in xrange(C-1):
                    thispos=thispos+(K**(C-(Clevels+1)))*(count-1)
                    count=(count+1) % K if (count+1) % K else K
                thispos+=count
                count=(count+1) % K if (count+1) % K else K
                solu[i]=thispos
            result = ' '.join([str(int(item)) for item in solu])
        f.write('Case #{0}: {1}\n'.format(index+1,result))
