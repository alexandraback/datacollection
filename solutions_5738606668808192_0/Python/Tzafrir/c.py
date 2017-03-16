from sys import stdin
import itertools
import math
from math import sqrt; from itertools import count, islice

def rwh_primes1(n):
    # http://stackoverflow.com/questions/2068372/fastest-way-to-list-all-primes-below-n-in-python/3035188#3035188
    """ Returns  a list of primes < n """
    sieve = [True] * (n/2)
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i/2]:
            sieve[i*i/2::i] = [False] * ((n-i*i-1)/(2*i)+1)
    return [2] + [2*i+1 for i in xrange(1,n/2) if sieve[i]]  
def binary_jam(N):
  for num in itertools.product('01', repeat=N-2):
    yield '1'+''.join(num)+'1'
    
def isPrime(n):
    for number in islice(count(2), int(sqrt(n)-1)):
        if not n%number:
            return (False,number)
    return (True,0)
    
def solve(N,J):
  count = 0
  for num in binary_jam(N):
    if count==J:
      break
    proof=[]
    for base in range(2,11):
      value = int(num,base)
      (stat,number) = isPrime(value)
      if stat:
        break
      else:
        proof.append(str(number)) 
    else:
      print "%s %s" % (num,' '.join(proof)) 
      count +=1
      
#primes=rwh_primes1(2**16)

for case in xrange(1,1+int(stdin.readline())):
    (N,J) = tuple(int(x) for x in stdin.readline().split())
    print "Case #%d: " % case
    solve(N,J)