'''
Created on Apr 14, 2012

@title: Code Jam 2012 Round 1A: Problem B
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
        stars = [[int(x) for x in fi.next().split()] for unused in range(N)]
        cases.append(stars)
        
    answers = parallelize(cases)
    for i,a in enumerate(answers):
        output = 'Case #{0}: {1}'.format(i+1,a)
        print output
        fo.write(output+'\n')

def parallelize(cases):
    p = Pool(8)
    answers = p.map(solve, cases)
#    answers = map(solve, cases)
    return answers

from heapq import *
from copy import deepcopy
def solve(case):
    stars = 0
    games = 0
    unavailable = case
    onestars = []
    
    while len(unavailable) > 0:
        # Do all 2's
        changed = True
        while changed:
            changed = False
            cua = unavailable
            unavailable = []
            for c in cua:
                if c[1] <= stars:
                    stars += 2
                    games += 1
                    changed = True
                else:
                    unavailable.append(c)
                    
            c1s = onestars
            onestars = []
            for c in c1s:
                if c[1] <= stars:
                    stars += 1
                    games += 1
                    changed = True
                else:
                    onestars.append(c)
        
        if len(unavailable) == 0:
            break
        
        # Do best 1
        best = None
        besti = -1
        for i, c in enumerate(unavailable):
            if c[0] <= stars:
                if best is None:
                    best = c
                    besti = i
                elif best[1] < c[1]:
                    best = c
                    besti = i
        if best is None:
            return "Too Bad"
        
        stars += 1
        games += 1
        onestars.append(best)
        del unavailable[besti]
            
    # do rest of onestars           
    changed = True
    while changed:
        changed = False
        c1s = onestars
        onestars = []
        for c in c1s:
            if c[1] <= stars:
                stars += 1
                games += 1
                changed = True
            else:
                onestars.append(c)
    
    if len(onestars) > 0:
        return 'Too Bad'
    return games

# Main
import sys
if len(sys.argv) < 2:
    filebase = '/home/jon/Downloads/B-large'
else:
    filebase = sys.argv[1]
io_parallelize(filebase)