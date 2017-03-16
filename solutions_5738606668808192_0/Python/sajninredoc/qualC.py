import sys
from random import randint

N = 16
J = 50

def is_prime(p):
    if p<=1: return False
    i = 2
    while i*i<=p:
        if p%i==0:
            return False
        i+=1
    return True

primes = [p for p in xrange(1000) if is_prime(p)]
def small_factor(x):
    for p in primes:
        if x%p==0:
            return p
    return -1

def rand_str(L):
    return ''.join([str(randint(0,1)) for _ in xrange(L)])

def check_jamcoin(c):
    vals = [int(c, b) for b in xrange(2, 11)]
    factors = [small_factor(val) for val in vals]
    
    if any([factor==-1 for factor in factors]):
        return None
    else:
        return factors
    

checked = set()
good_coins = []

while len(good_coins) < J:
    coin = '1' + rand_str(N-2) + '1'
    if coin not in checked:
        checked.add(coin)
        
        cert = check_jamcoin(coin)
#        print coin, cert
        if cert:
            good_coins.append((coin, cert))
    
print 'Case #1:'
for coin in good_coins:
    print coin[0], ' '.join([str(v) for v in coin[1]])