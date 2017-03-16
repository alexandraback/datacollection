
## K   Length of original sequence
## C   Complexity 

## Original sequence is  R = r0 r1 ... rK
## Encode position of final sequence in base K as 
##   P = p1 p2 ... pC
## Then the value at position P is
## IsGold(P) = Any(IsGold(R[p1], R[p2], ..., R[pC])
## So we can test C separate values of R at once, as long as we use 
## p1, p2, ... all different

##Input 
##T            -->Ncases
##K, C, S      

##Solution: 
## if C*S<K --> Impossible
## else  -->  Generate sequence of P numbers according to 
## {pj} = [0, 1,... K] (or any non-repeating sequence)
## No need to fill in extra values...minimal set is OK if <=S

## 1 < K < 100
## 1 < C < 100
## K**C < 1e+18

import numpy as np
import pylab as pl
import re 
import scipy as sc
import sys 
f = "foo" 



####SWAP TWO LINES TO SWITCH FROM STDIN TO FILE INPUT
#in_trimmed = lambda f: f.readline()[:-1]
in_trimmed = lambda f: input()
if(True):
#with open('c:/Users/Fini/Documents/Career/Google/Code Jam/Frac/test.in', 'r') as f:
    Ncases = int(in_trimmed(f))
    CaseIn = [ [] for ncase in range(Ncases)]
    for ncase in range(Ncases):
        KK, CC, SS = [int(s) for s in in_trimmed(f).split(' ')]
        CaseIn[ncase] = [KK, CC, SS]

##print(CaseIn)


for ncase in range(Ncases):
#for ncase in range(1):
    KK  = np.uint64(CaseIn[ncase][0])
    CC  = np.uint64(CaseIn[ncase][1])
    SS  = np.uint64(CaseIn[ncase][2])
    if(CC * SS < KK):
        print("Case #{}: IMPOSSIBLE".format(ncase+1))
    else:
        remaining = np.array([ np.uint64(jj) for jj in range(KK)])
        place = np.arange(min(KK,CC)-1, -1, -1, dtype = np.uint64)
        #place = np.arange(0, CC, dtype = np.uint64)
        Kpow  = np.array([KK**cj for cj in place])
        ##With limits at 1e+18, should be no problem with int64
        sample_pos = []
        if(len(Kpow)>1):
            if(pl.any(np.diff(np.double(Kpow)) >=0)):
                #           if(pl.any(np.diff(np.double(Kpow)) <=0)):
                print('unexpected overflow')
                sys.exit(1)
        while(len(remaining) >= CC):
            ##Break off the next word and convert to position
            pos_baseK = remaining[:CC]
            remaining = remaining[CC:]
            ##Generate a position
            ## (Kpow * (0*pos_baseK)).sum() + np.uint64(1)
            posj = (Kpow * pos_baseK).sum() + np.uint64(1)
            sample_pos.append(posj)
        if(len(remaining) > 0):
            pos_baseK = remaining
            posj = (Kpow[:len(pos_baseK)] * pos_baseK).sum() + np.uint64(1)
            sample_pos.append(posj)
        linej = ''.join(( "{} ".format(lj) for lj in sample_pos))
        linej = linej[:-1] ##Trim final space?!
        print("Case #{}: {}".format(ncase+1, linej))
        
        
