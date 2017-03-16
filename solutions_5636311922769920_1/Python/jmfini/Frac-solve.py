
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

##Oops...python's default int class would actually be more robust to large numbers
##But the limit 1e+18 means this should not make a difference


import numpy as np
import pylab as pl
import re 
import scipy as sc
import sys 
f = "foo" 

###Adding some test inputs to more_test.in
#100 9 11
#100 9 12
#3 36 1
###########
##For 100 9 11 got "IMPOSSIBLE"
##   We get to test 9 symbols per sample, or 99 maximum, which is <100
## Check for offset (C-1) misinterp:
##   C=1 is the original sequence
##   S=1 tests one cell
##   S=2 tests two cells
##  C=2 is complexity 2
##   S=1 tests two cells
##  Base cases look OK
## This looks right
###########
##For 3 36 1 got Case #8: 6
##  For any 3 LargeC 1
##  The sixth position follows branch sequence 0 --> 1 --> 2 
##  This looks correct, but 3 was the original test case...
##  better to test one more with 2 or 4 or something
###########
##For 4 20 1 got Case #9: 28
##  For any 4 LargeC 1
##  Position 28 follows branch sequence 0, ... , 0, 1,2,3
##  Looks good
###########
##For 100 9 12 got Case #7: 102030405060709 91011121314151618 181920212223242527 272829303132333436 363738394041424345 454647484950515254 545556575859606163 636465666768697072 727374757677787981 818283848586878890 909192939495969799 990000000000000001
##  We can simply read off the sequences by parsing the decimal pairs 102030405060709 --> {01,02,03,04,05,06,07,09} (NOT QUITE)
##  There seems to be a little problem...No actually, no problem with the solver, I just have to remember to subtract 1 in the manual solution
##  We can simply read off the sequences by parsing the decimal pairs 102030405060709 - 1 --> 102030405060708 --> {00,01,02,03,04,05,06,07,08} 
##  With this, the solutions look just like what I asked for, {00,01,02,03,04,05,06,07,08} and then {09,10,...,17} and then {18,..., 26}
##  After zero through 99 are covered, there is a fill sequence 990000000000000001 - 1 --> 990000000000000000 --> {99,00,00, 00,00,00, 00,00,00}
##  The last entry has the correct number of digits


####SWAP TWO LINES TO SWITCH FROM STDIN TO FILE INPUT
#in_trimmed = lambda f: f.readline()[:-1]
in_trimmed = lambda f: input()
if(True):
#with open('c:/Users/Fini/Documents/Career/Google/Code Jam/Frac/test.in', 'r') as f:
#with open('c:/Users/Fini/Documents/Career/Google/Code Jam/Frac/more_test.in', 'r') as f:
    Ncases = int(in_trimmed(f))
    CaseIn = [ [] for ncase in range(Ncases)]
    for ncase in range(Ncases):
        KK, CC, SS = [int(s) for s in in_trimmed(f).split(' ')]
        CaseIn[ncase] = [KK, CC, SS]

##print(CaseIn)


for ncase in range(Ncases):
#for ncase in range(1):
#for ncase in [6]:
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
        
        
