# Coin Jam.py

from itertools import *
from random import randrange

small_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31] # etc.

def primes1(n):
    """ Returns  a list of primes < n """
    sieve = [True] * (n/2)
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i/2]:
            sieve[i*i/2::i] = [False] * ((n-i*i-1)/(2*i)+1)
    return [2] + [2*i+1 for i in xrange(1,n/2) if sieve[i]]

primes = primes1(543);
# print primes

def probably_prime(n, k):
    """Return True if n passes k rounds of the Miller-Rabin primality
    test (and is probably prime). Return False if n is proved to be
    composite.

    """
    if n < 2: 
    	return False
    for p in small_primes:
        if n < p * p: return True
        if n % p == 0: return False
    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

def factor(n):

	for p in primes:
		if n%p == 0 :
			return p;
	return -1;

t = int(raw_input());
n,z = map(int,raw_input().split())
ans = []
for a in product('01',repeat=n-2):	
	a = ''.join(a)
	a = '1'+a+'1';
	# print a
	flag = 0;
	curr = [];
	curr.append(a)
	for j in xrange(2,11):
		x = int(a,j);
		# print j,x
		y = factor(x);
		if y == -1 :
			flag = 1;
			break;
		# curr.append(x);
		curr.append(y);
	if flag == 0 :
		ans.append(curr)

	if len(ans) == z :
		break;

print 'Case #1:';
for a in ans:
	for b in a :
		print b,
	print;