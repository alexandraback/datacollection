import fileinput
import random
import sys
from math import sqrt

def is_probable_prime(n, k = 30):
   """use Rabin-Miller algorithm to return True (n is probably prime)
      or False (n is definitely composite)"""
   if n < 6:  # assuming n >= 0 in all cases... shortcut small cases here
      return [False, False, True, True, False, True][n]
   elif n & 1 == 0:  # should be faster than n % 2
      return False
   else:
      s, d = 0, n - 1
      while d & 1 == 0:
         s, d = s + 1, d >> 1
      # Use random.randint(2, n-2) for very large numbers
      for a in random.sample(xrange(2, min(n - 2, sys.maxint)), min(n - 4, k)):
         x = pow(a, d, n)
         if x != 1 and x + 1 != n:
            for r in xrange(1, s):
               x = pow(x, 2, n)
               if x == 1:
                  return False  # composite for sure
               elif x == n - 1:
                  a = 0  # so we know loop didn't continue to end
                  break  # could be strong liar, try another a
            if a:
               return False  # composite if we reached end of this loop
      return True  # probably prime if reached end of outer loop

def primes_sieve2(limit):
    a = [True] * limit  # Initialize the primality list
    a[0] = a[1] = False

    for (i, isprime) in enumerate(a):
        if isprime:
            yield i
            for n in xrange(i*i, limit, i): # Mark factors non-prime
                a[n] = False

def factor(n,maxprime):
  for x in primes_sieve2(min(maxprime,int(sqrt(n))) + 1):
    if n % x == 0:
      return x
  return 0

def increment(bits):
    idx = len(bits)-2
    while bits[idx] and idx > 0:
        bits[idx] = 0
        idx -= 1
    if idx > 0:
        bits[idx] = 1
    return idx > 0

def jamcoin(bits,maxprime):
    proofs = [0 for _ in range(9)]
    vals = [0 for _ in range(9)]
    divs = [0 for _ in range(9)]
    for i in range(2,11):
        val = sum([y*(i**x) for x,y in enumerate(bits)])
        vals[i-2] = val
        if is_probable_prime(val):
            return (proofs,vals,divs)
        proofs[i-2] = factor(val,maxprime)
        if proofs[i-2] > 0:
            divs[i-2] = vals[i-2]/proofs[i-2]
    return (proofs,vals,divs)

data = fileinput.input()
T = int(data[0])
N,J = (int(s) for s in data[1].split())
print("Case #1:")

bs = [0 for _ in range(N)]
bs[0] = bs[-1] = 1

jamcoins = [[] for _ in range(J)]
proofs = [[] for _ in range(J)]

num_jamcoins = 0
maxprime = 2**8

while num_jamcoins < J:
    tmp,vals,divs = jamcoin(bs,maxprime)
    if all(tmp):
        jamcoins[num_jamcoins] = "".join(str(x) for x in bs)
        jamcoins[num_jamcoins] = jamcoins[num_jamcoins][::-1]
        proofs[num_jamcoins] = tmp
        print jamcoins[num_jamcoins]+" "+" ".join(str(x) for x in proofs[num_jamcoins])
        #print jamcoins[num_jamcoins]+" "+" ".join("("+str(x)+"/"+str(y)+")" for x,y in zip(proofs[num_jamcoins],vals))
        #print jamcoins[num_jamcoins]+" "+" ".join(str(x) for x in divs)
        #print jamcoins[num_jamcoins]+" "+" ".join(str(x*y) for x,y in zip(divs,proofs[num_jamcoins]))
        #print jamcoins[num_jamcoins]+" "+" ".join(str(x) for x in vals)
        num_jamcoins += 1
    increment(bs)


