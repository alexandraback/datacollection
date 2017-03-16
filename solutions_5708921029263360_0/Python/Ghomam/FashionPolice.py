# -*- coding: utf-8 -*-
"""
Created on Sun May 08 11:11:35 2016

@author: Ghomam
"""

import sys

print sys.argv[1]
inp = open(sys.argv[1]).readlines()

#inp = ['4', '1 1 1 10', '1 2 3 2', '1 1 3 2', '1 2 3 1']

def raw_input():
    return inp.pop(0).strip()

# Read input data
T = int(raw_input())
tests = []
for i in xrange(T):
    S = [int(n) for n in raw_input().strip().split(' ')]
    tests.append(S)

O = ['' for s in tests]
for i,(J,P,S,K) in enumerate(tests):
    #print "------------------------------------------"
    #print i, "{} {} {} ({})".format(J,P,S,K)
    #print "------------------------------------------"
    j,p,s = [1,1,1]
    outfits = []
    T = J*P*S
    #print min(T,J*P*K)
    #while len(outfits) < min(T,J*P*K):
    for l in xrange(J*P*S):
        outfit = [j,p,s]
        #print outfit
        if max(sum([ 1 for j0,p0,s0 in outfits if [j0,p0] == [j,p] ]), sum([ 1 for j0,p0,s0 in outfits if [j0,s0] == [j,s] ]), sum([ 1 for j0,p0,s0 in outfits if [p0,s0] == [p,s] ])) < K:
            outfits.append(outfit)
        
        s += 1
        if s > S:
            s = 1
            p += 1
            if p > P:
                p = 1
                j = min(j+1, J)
        
        #if len(outfits) == min(T,J*P*K): break
    
    O[i] = [ " ".join([str(o) for o in outfit]) for outfit in outfits ]

# output
output = open('output.out', 'w')
for i,o in enumerate(O):
    out = 'Case #{}: {}'.format(i+1, len(o) )
    out += "\n"+"\n".join(o)
    #print "input>", tests[i]
    print out
    if i > 0 : out = '\n'+out
    output.write(out)
output.close()