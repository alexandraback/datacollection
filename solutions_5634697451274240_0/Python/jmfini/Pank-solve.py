
##For each flip, 
## Number of sign changes 
##   remains the same within each set...
##   there is only one interface 
##   interface sign change can stay the same, go up 1, go down one
## 
## Number of sign changes never goes down more than 1 per turn
## Number of sign changes must reach zero 
## Simple left-to right algorithm can remove 1 sign change per turn
## It never introduces a new sign change, since the flipped group 
## are all the same
## What about the last element?

## Equivalent problem: fictitious N+1 + sign

##Input 
##T            -->Ncases
## s0 s1 s2 



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
#with open('c:/Users/Fini/Documents/Career/Google/Code Jam/Pank/test.in', 'r') as f:
    Ncases = int(in_trimmed(f))
    CaseIn = [ [] for ncase in range(Ncases)]
    for ncase in range(Ncases):
        CaseIn[ncase] = in_trimmed(f)

#print(CaseIn)


for ncase in range(Ncases):
    seq  = CaseIn[ncase] + '+'
    sign_changes = 0
    for jj in range(len(seq)-1):
      if(seq[jj] != seq[jj+1]):
          sign_changes = sign_changes + 1 
    print("Case #{}: {}".format(ncase+1, sign_changes))
        
        
