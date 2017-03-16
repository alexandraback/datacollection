import itertools
import sys
import math

N = 32
J = 500
ct = 0

sieve = [0] * 2**16
sieve[2] = 1
primes = []
for i in range(3,2**16,2):
    if sieve[i] == 1: continue
    primes.append(i)
    for j in range(i, 2**16, i): sieve[i] = 1

floor = 2**(N-1) + 1
ceil = 2**N -1

def composite_in_base(num,base):
    num = int(bin(num)[2:],base)
    for p in primes:
        if p > math.sqrt(num): return 0
        if num%p == 0: 
            return p
    return 0

print "Case #1:"
for i in itertools.count(floor):
    if i > ceil: break
    if i % 2 == 0: continue
    flag = True
    factors = [] 
    for j in range(2,11):
        f = composite_in_base(i,j) 
        if f == 0: 
            flag = False
            break
        else:
            factors.append(f)
    if flag:
        sys.stdout.write(bin(i)[2:])
        print " " + " ".join(map(str, factors))
        ct+=1
    if ct == J: break


