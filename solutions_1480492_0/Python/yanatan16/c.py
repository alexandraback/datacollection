'''
Created on Apr 14, 2012

@title: Code Jam 2012 Round 1A: Problem C
@author: jon eisen
'''
from multiprocessing import Pool

def io_parallelize(filebase, inext='.in'):
    fi = open(filebase+inext,'r')
    fo = open(filebase+'.out','w')
    n = int(fi.next().strip())
    print n, 'Test Cases'
    cases = []
    for unused in range(n):
        N = int(fi.next().strip())
        cars = [[int(x) for x in fi.next().split()[1:]] for unused in range(N)]
        cases.append(cars)
        
    answers = parallelize(cases)
    for i,a in enumerate(answers):
        output = 'Case #{0}: {1}'.format(i+1,a)
        print output
        fo.write(output+'\n')

def parallelize(cases):
    p = Pool(8)
#    answers = p.map(solve, cases)
    answers = map(solve, cases)
    return answers

import numpy as np
def solve(cars):
    N = len(cars)
    itms = np.empty((N,N),dtype=list)
    for i in range(N):
        for j in range(i+1,N):
            t = itime(cars[i],cars[j],5)
            itms[i,j] = t
            itms[j,i] = t
    if cars[0] == [20,5334]:
        pass
    
    collision = np.inf;
    for i in range(N):
        for j in range(i+1,N):
            if itms[i,j][1] >= 0:
                for k in range(N):
                    if k != i and k != j:
                        if ((itms[i,k][0] >= max(0,itms[i,j][0]) and itms[i,k][0] <= itms[i,j][1]) \
                        or (itms[i,k][1] >= max(0,itms[i,j][0]) and itms[i,k][1] <= itms[i,j][1])) and \
                        ((itms[j,k][0] >= max(0,itms[i,j][0]) and itms[j,k][0] <= itms[i,j][1]) \
                        or (itms[j,k][1] >= max(0,itms[i,j][0]) and itms[j,k][1] <= itms[i,j][1])):
                            collision = min(collision, getcoltime(itms[i,j],itms[i,k],itms[j,k]))
    if collision == np.inf:
        return 'Possible'
    else:
        return collision

def getcoltime(c12it,c13it,c23it):
    s = max([c12it[0],c13it[0],c23it[0],0])
    return s
        

def itime(c1,c2,rz=0):
    if c1[0] == c2[0]:
        if abs(c1[1] - c2[1]) < rz:
            return [-np.inf,np.inf]
        else:
            return [-np.inf,-np.inf]
    else:
        return sorted([float(c1[1]-c2[1]+z) / (c2[0]-c1[0]) for z in (rz,-rz)])

# Main
import sys
if len(sys.argv) < 2:
    filebase = '/home/jon/Downloads/C-small-attempt1'
else:
    filebase = sys.argv[1]
io_parallelize(filebase)