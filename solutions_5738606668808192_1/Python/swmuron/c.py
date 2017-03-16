
import sys

import math

import random


storedDivisors = dict()

#
# Miller-Rabin implementation
#
# Borrowed from https://jeremykun.com/2013/06/16/miller-rabin-primality-test/
# thanks to the license magic of https://creativecommons.org/licenses/by-nc/3.0/deed.en_US
#
# Code Jam is non-commerical as an individual participant, right? Job search aside. :)
#

#
# Probabilistic fast prime finding
# https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Algorithm_and_running_time
#
# Since we test divisors for actual correctness later on, we can afford false results
#

def decompose(n):
   exponentOfTwo = 0
 
   while n % 2 == 0:
      n = n/2
      exponentOfTwo += 1
 
   return exponentOfTwo, n
 
def isWitness(possibleWitness, p, exponent, remainder):
   possibleWitness = pow(possibleWitness, remainder, p)
 
   if possibleWitness == 1 or possibleWitness == p - 1:
      return False
 
   for _ in range(exponent):
      possibleWitness = pow(possibleWitness, 2, p)
 
      if possibleWitness == p - 1:
         return False
 
   return True
 
def probablyPrime(p, accuracy=100):
   if p == 2 or p == 3: return True
   if p < 2: return False
 
   numTries = 0
   exponent, remainder = decompose(p - 1)
 
   for _ in range(accuracy):
      possibleWitness = random.randint(2, p - 2)
      if isWitness(possibleWitness, p, exponent, remainder):
         return False
 
   return True


#
# Nothing fancy here.
#
# If p is probably prime, then assume it is and Fail - there are millions of coins in the sea.
# 
# Sequentially try divisors until we find one. Implement a magic number limit to avoid issues when hitting a hard semiprime-looking number
#
# If we failed the limit, then too hard to answer with a divisor and just fail instead
#
# Otherwise, report the result for collection
#

def findDivisorNaive(p):
  #if (p in storedDivisors):
  #  return storedDivisors[p]
  if (probablyPrime(p)):
    return None

  # dont work too hard, we just need 500 examples collected
  maxI = min(1000,math.sqrt(p))
  
  print('gonna loop with maxI'+str(maxI)+'\n')

  i = 2
  while (p % i <> 0 and i <= maxI):
    i += 1

  if (i > maxI):
    i = None
  #storedDivisors[p] = i
  return i

# Start from base 2 -> 10 and find a divisor for each one
# 
# if we have a divisor for all of them, then it's a coin and reported as a success with ans having each field of the result row
# otherwise report None as a failure

def checkIt(s):
  ans = [s]
  for i in range(2,11):
    n = int(s,i)
    d = findDivisorNaive(n)
    ans.append(str(d))
    if (d == None or d == 0):
      print(s+'('+str(n)+') failed @ base '+str(i)+' d returned was '+str(d))
      return None
    print str(i)+'base found divisor for '+str(n)+' = '+str(d)
  print(s+' success '+str(len(ans)))
  return ans



# actually process the solution file

with open(sys.argv[1]) as f:
  fLines = f.read().splitlines()

  vals = fLines[1].split(' ')

  # the file just provides these numbers
  n = int(vals[0]) 
  maxJ = int(vals[1])
  with open("ans_"+sys.argv[1],'w') as outFile:
    #for n in range(2,16):
    outFile.write('Case #1:\n')
    jFound = 0

    # look for up to maxJ
    nPow = int(math.pow(2,n-2))

    # we associate each coin with a number representing its "inner" representation
    # we then sequentially check these coins by converting the number to a binary string
    # once we find J coins, abort the processing
    i = 0
    while (i < nPow):
      if (n == 2):
        s = '11'
      else:
        s = '1'+bin(i)[2:].zfill(n-2)+'1'
      print 'checking s='+s
      r = checkIt(s)
      if (r <> None):
        joinS = ' '.join(r)
        outFile.write(joinS+'\n')
        jFound += 1
        if (jFound >= maxJ):
          break
      i += 1

    outFile.close()
