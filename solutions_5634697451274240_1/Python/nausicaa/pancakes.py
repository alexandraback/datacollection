# -*- coding: utf-8 -*-
"""

@author: Robo
"""

import os
import numpy as np

folder = "D:/CODE/googlecodejam/revenge_pancakes"
infile = "B-large.in"
outfile = "B-large.out"


def read_gcj_input():
    cases = []
    with open(os.path.join(folder,infile), 'r') as f:
        for each in xrange(int(f.readline())):
            Araw = f.readline().strip()
            S = [1 if i=='+' else -1 for i in Araw]
#            print S
            cases.append(S)
    return cases
    

def iterflip(S,sign, count):
    if len(S)==1:
        if S[0]==sign:
            return count
        else:
            return count+1
    elif S[-1] == sign:
        count = iterflip(S[:-1],sign,count)
        return count
    else:
        count = iterflip(S[:-1],-sign,count)
        return count+1
        
    
cases = read_gcj_input()

with open(os.path.join(folder,outfile), 'w') as f:
    for index,case in enumerate(cases):
        S = case
        count = iterflip(S,1,0)        
        f.write('Case #{0}: {1}\n'.format(index+1,count))
