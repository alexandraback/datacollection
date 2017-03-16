
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



#BB = 10
#NN = 32
#LL = BB**(NN-1) + 1 
###We can't check the full range for large NN
###The density of primes is ~1/ln(LL) ~ 1/ ((NN-1)ln(BB)) ...
###The probability that a number has no primes for any BB is 
### (Are they independent ?!)
#Density = np.prod([ (1- 1/((NN-1) * np.log(float(bj)))) 
#                    for bj in range(2,11)])
##Assuming high anti-correlation
#Density = 1 - np.sum([ ( 1/((NN-1) * np.log(float(bj)))) 
#                       for bj in range(2,11)])
###The densities of non-primes should be quite high...
###The real limiter then is the density of numbers matching a 
### jamcoin code ...only a small fraction have 0,1 representations 
### in the larger bases
### If we use bincodes with K active digits, 
### then there are 2^K of them
### These span 10^K numbers in the base-10 part
### We can set up a sieve with range RR
### Then we need RR ~ 10^K to achieve J ~ 2^K, or roughly 
### RR ~ JJ^5
### For JJ ~ 50, that's about 300M
### For JJ ~ 500, that's 31T...not looking good
### The more obvious approach is better, I guess...
### Simply generate each eligible bincode, check for primes 
### individually for each basis

### A simple factor-finder tries all possible factors 
###    F in 1 to sqrt(L), L ~ BB**NN
### For each, do one mod operation
### The cost of a mod operation is ~ NN ? 
### So the cost is something like 10**(NN/2) for each of JJ
### for N=16, 10^(16/2) ~100M is reasonable 
### for N=32, 10^(32/2) ~10000 T 

###We don't have to check all factors...
###  1. Primes-only would give complete solutions
###  2. We don't need complete solutions if J << number of possible 
###     solutions
###

###We could iterate the problem in two ways
###  Trial locality L
###  Factors up to Fmax 
###     Half of all numbers have a factor 2...
###We could use a modified sieve method, where we split the digits
###N-2 into locality digits and bincode digits. 
###  If there are Ml localities, we need solutions J/Ml per locality
###     This makes the cost Ml * (J/Ml)^5, so we can substantially 
###     reduce the effective Jeff=J/Ml as NN gets large
###     Available Ml = 2**(N-2-K), where 2**K is the number of codes
###  For each locality, we can run the sieve partially, 
###  check the number of solutions, and keep running it
###  



def code_value(val_in, code, BB):
    if(len(code)==0):
        return(val_in)
    else:
        return(code_value(val_in * BB + code[0], code[1:], BB))

##code_value(0, [1,0,1,1,1,1,1,1,1,1,1,1,1], 10)

def bincodes(code_in, KK, BB, RR):
    if((len(code_in[0]) >= KK) or (BB**(len(code_in[0])) > RR)):
        return(code_in)
    else:
        return bincodes([ [0]+cj for cj in code_in] + 
                        [ [1]+cj for cj in code_in], KK, BB, RR)


def small_primes(RR):
    Table = [ [rj, True] for rj in range(2,RR)]
    for FF in range(2, int(np.sqrt(RR))):
        for ind in range(2*FF-Table[0][0], RR-Table[0][0], FF):
            Table[ind][1] = False
    return [ pair[0] for pair in Table if pair[1]]

some_primes = small_primes(200)




####SWAP TWO LINES TO SWITCH FROM STDIN TO FILE INPUT
#in_trimmed = lambda f: f.readline()[:-1]
in_trimmed = lambda f: input()
if(True):
##with open('c:/Users/Fini/Documents/Career/Google/Code Jam/Coin/test.in', 'r') as f:
##with open('c:/Users/Fini/Documents/Career/Google/Code Jam/Coin/small.in', 'r') as f:
##with open('c:/Users/Fini/Documents/Career/Google/Code Jam/Coin/large.in', 'r') as f:
    Ncases = int(in_trimmed(f))
    CaseIn = [ [] for ncase in range(Ncases)]
    for ncase in range(Ncases):
        NN, JJ = [int(s) for s in in_trimmed(f).split(' ')]
        CaseIn[ncase] = [NN, JJ]

##print(CaseIn)

#NN = 16
#JJ = 50

#NN = 6
#JJ = 6

## CaseIn[ncase][0] = 29

for ncase in range(Ncases):
  NN, JJ = CaseIn[ncase] 
  MonitorLargestNprime = 0
  if(NN < 8):
      Kl = 0
      NSolsPerLoc = JJ
  else:
      Kl = int(np.ceil(1.5 * np.log(JJ) / np.log(2)))
      NSolsPerLoc = 1
  Kr = NN - 2 - Kl
  if(Kr > 3):
      Kr = 3
  Kfill = NN - 2 - Kl - Kr
  Fillcode = [0 for jj in range(Kfill)]
  ##2**Kl location codes cover JJ
  ##Each needs to contribute one solution
  LocCodes  = bincodes([[]], Kl, 2,  2**Kl)
  RangeCodes = bincodes([[]], Kr, 2, 2**Kr)
  CollectSolutions = []
  nloc = 0
  while ((nloc<len(LocCodes)) and (len(CollectSolutions) < JJ)):
      Lcode = LocCodes[nloc]
      start_fullcode = [1] + Fillcode + Lcode + RangeCodes[0] +  [1]
      TableList = [ [] for BB in range(11)]
      for BB in range(2,11):
          ##Starting with a large number...
          LL = code_value(0, start_fullcode, BB)
          RR = BB**(Kr+1)
          TableList[BB] = [ [LL + rj, 0, 0, ""] for rj in range(RR)]
          ##Mark jambits, codes, and BinaryValue in the table
          for code in RangeCodes:
              fullcode = [1] + Fillcode + Lcode + code + [1]
              ##Relative to the starting code...
              ind = code_value(0, fullcode, BB) - LL
              if(ind < len(TableList[BB])):
                  TableList[BB][ind][2] = code_value(0,fullcode, 2)
                  TableList[BB][ind][3] = "".join(["{}".format(cj) 
                                                   for cj in fullcode])
      nprime = 0
      Merged = []
      while((nprime < len(some_primes)) and 
            (len(Merged) < NSolsPerLoc)):
      ##for nprime in [1]:
          FF = some_primes[nprime]
          ##Mark primes and factors in the table
          ToMerge = [[] for BB in range(11)]
          for BB in range(2,11):
              LL = TableList[BB][0][0]
              MM = ((LL-1) % FF) + 1
              for ind in range(FF-MM, len(TableList[BB]), FF):
                  if(TableList[BB][ind][1] == 0):
                      TableList[BB][ind][1] = FF
              partial = [ row for row in TableList[BB]
                          if (row[1]!=0) and (row[2] != 0)]
              ToMerge[BB] = partial
          BB = 2
          Merged = [[row[2], row[3], [row[1]], [row[0]]] 
                    for row in ToMerge[BB]]
          for BB in range(3,11):
              Merged = [ [Mrow[0], Mrow[1], 
                          Mrow[2] + [row[1]], Mrow[3] + [row[0]]]
                         for Mrow in Merged
                         for row in ToMerge[BB] 
                         if (row[2] == Mrow[0])]
          ##print(nprime)
          if(nprime > MonitorLargestNprime):
              MonitorLargestNprime = nprime
          nprime = nprime + 1
      if(len(Merged) > 0):
        CollectSolutions = CollectSolutions + Merged
      #print("Location {} contributed {} sols, {} total, nprime={}".format(
      #        nloc, len(Merged), len(CollectSolutions), nprime))
      nloc = nloc + 1
  if(len(CollectSolutions) >= JJ):
      print("Case #{}:".format(ncase+1))
      for nline in range(JJ):
          print(CollectSolutions[nline][1] + " " + 
                "".join([ "{} ".format(fj) 
                          for fj in CollectSolutions[nline][2]]))
  
  ##encouraging...for NN=10, the range loop essentially ran in no time
