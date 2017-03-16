import math
import random
from sets import Set
T=int(raw_input())
N,J=map(int,raw_input().split())

upperBound=1000000
isPrime=[True for i in xrange((upperBound-3)/2+1)]
for i in xrange((int(math.sqrt(upperBound-3))-3)/2+1): # k*k = (2i+3)^2 <= upperBound-3 
   if isPrime[i]:
      k = i+i+3 # this is prime number
      # false out non_prime number from k*k
      # k*k = 4i^2+12i+9 = 2*(2i^2+6i+3)+3
      # k*(k+1) = 2*(2i^2+6i+3)+3 + 2i+3 ... even number. skip
      # k*(k+2) = 2*(2i^2+6i+3+k)+3 
      non_prime = k*(i+1)+i
      for j in xrange(non_prime,(upperBound-3)/2+1,k):
         isPrime[j]=False
primes = [2] + [i+i+3 for i in range((upperBound-3)/2+1) if isPrime[i]==True]
#for p in primes:
#    print p,

def change(num,base):
    ret=0
    dig=1
    while num!= 0 :
        if num%2==1 :
            ret+=dig
        num/=2
        dig*=base
    return ret

S=set([])
#print candidates
print "Case #1:"
cur= (1L<<(N-1))+1
while len(S) < J:
    div = [-1 for i in range(11)]
    if cur in S:
        cur+=2
        continue
    ok=True
    for base in range (2,11):
        n = change(cur,base)
        for p in primes:
            if p >= n:
                break
            if n%p==0:
                div[base]=p
                break;
        if div[base]==-1:
            ok=False
            break
    if ok:
        S.add(cur)
        print format(cur,'b'),
        for i in range(2,11):
            print div[i],
        print
    cur+=2
