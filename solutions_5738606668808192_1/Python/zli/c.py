# https://pypi.python.org/pypi/pyprimes/
import pyprimes
import random
import sys

# Taken from
# https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Primality_Testing
def is_probable_prime(n, k = 7):
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

def xl(l):
    return xrange(len(l))

#for case in range(1, input()+1):
for case in range(1, 2):
    print "Case #%s:" % (case)
    N, J = 32, 500
    #N, J = 16, 50
    #N, J = 6, 3
    count = 0
    #primes = list(pyprimes.primes_below(10 ** (N/2) + 2))
    #print len(primes)
    for i in xrange(1 << (N-2)):
        s = "1%s1" % bin(i)[2:].zfill(N-2)
        divisors = []
        for base in xrange(2, 11):
            number = int(s, base)
            if is_probable_prime(number):
                break
            #else:
            #    divisors.append(1)
            sqrt_number = number ** 0.5
            for prime in pyprimes.primes_below(10 ** (N/5) + 2):
                if number % prime == 0:
                    divisors.append(prime)
                    break
                if prime > sqrt_number:
                    break
            #print divisors, base
            if len(divisors) < base-1:
                #print "%s is prime in base %s" % (s, base)
                break
        else:
            print s, " ".join(map(str, divisors))
            count += 1
            if count == J:
                break
    else:
        print "Error! Not enough jamcoins."
