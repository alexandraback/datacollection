
##The libraries below are standard python
##The distribution of python I am using is pyzo, with intro message:
#####Python 3.4.1 |Continuum Analytics, Inc.| (default, May 19 2014, 13:02:30) on Windows (64 bits).

#Code was run using this interpreter, but final outputs were 
#generated using the command-line version of the same distribution:
#####This is the IEP interpreter with integrated event loop for PYSIDE.
#####Using IPython 2.1.0 -- An enhanced Interactive Python.
import numpy as np
import pylab as pl
import re 
import scipy as sc
import sys 
f = "foo" 


##When do we get insomnia?  (Avoid infinite loop)
##The only case is zero.
## Proof:
##   If integer N>0 has K digits, then for each symbol s
##   There are 10**K consecutive numbers with K+1 digits and symbol s as the first digit
##   At least one of these must be a multiple of N, since 10**K > N and multiples are spaced by N
## So we can simply set aside 0, the rest have answers
## Also, all K+1 digit numbers are < 100 * N, so we can use 100 as a maximum multiplier

## I don't notice a firm indication that N is always positive...
## Easy to handle negative N anyway


####SWAP TWO LINES TO SWITCH FROM STDIN TO FILE INPUT
#in_trimmed = lambda f: f.readline()[:-1]
in_trimmed = lambda f: input()
if(True):
#with open('c:/Users/Fini/Documents/Career/Google/Code Jam/Sheep/test.in', 'r') as f:
    Ncases = int(in_trimmed(f))
    CaseIn = [ [] for ncase in range(Ncases)]
    for ncase in range(Ncases):
        Nstr = in_trimmed(f)
        CaseIn[ncase] = Nstr


for ncase in range(Ncases):
  Nstr = CaseIn[ncase] 
  NN   = int(Nstr)
  if(NN==0):
      result = "INSOMNIA"
  else:
      remainder = set('0123456789')
      mult = 0
    ##Once you get past ??... multiplying won't help
      while((mult <= 100) and (len(remainder)>0)):
          mult += 1
          remainder = remainder.difference(set("{}".format(mult * NN)))
          if(len(remainder) != 0):
              result = "ERROR"
          else:
              result = "{}".format(mult * NN)
  print("Case #{}: {}".format(ncase+1, result))


##We can double-check ...actually 100 is reasonably tight with 125 being one of the outliers
#nvec = [NN for NN in range(10**5)]
#mulvec = [-1 for NN in nvec]
#for NN in nvec:
#  if(NN==0):
#      mulvec[NN] = 0
#  else:
#      remainder = set('0123456789')
#      mult = 0
#    ##Once you get past ??... multiplying won't help
#      while((mult <= 100) and (len(remainder)>0)):
#          mult += 1
#          remainder = remainder.difference(set("{}".format(mult * NN)))
#          if(len(remainder) != 0):
#              result = "ERROR"
#              mulvec[NN] = -2
#          else:
#              result = "{}".format(mult * NN)
#              mulvec[NN] = mult
#  
#pl.plot( np.array(nvec), np.array(mulvec))
