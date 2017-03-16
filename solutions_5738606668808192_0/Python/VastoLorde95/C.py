from math import *
from fractions import *
from random import *

def mult(s, m, mod):
	if m == 0: return 0
	ret = mult(s, m/2, mod)
	ret = (ret + ret) % mod
	if m % 2 == 1: ret = (ret + s) % mod
	return ret
	
def power(x, p, mod):
	s, m = 1, x
	while p > 0:
		if p % 2 == 1:
			s = mult(s, m, mod)
		p >>= 1
		m = mult(m, m, mod)
	return s

def witness(a, n, u, t):
	x = power(a, u, n)
	for i in xrange(t):
		nx = mult(x, x, n)
		if nx == 1 and x != 1 and x != n-1: return 1
		x = nx
	
	if x != 1: return 1
	return 0

def Miller(n):
	u, t = n-1, 0
	while u % 2 == 1:
		u >>= 1
		t += 1
	
	testlist = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59]
	
	for num in testlist:
		if witness(num, n, u, t) == 1: return False

	return True
	

t = input()
n, J = [int(x) for x in raw_input().split()]


dic = {}

print "Case #1:"
cnt = 0
while cnt < J:
	s = bin(getrandbits(n-2))[2:]
	s = "0" * (n-2 - len(s)) + s
	s = "1" + s + "1"
	
	if s in dic: continue
	
	ints = [int(s, i) for i in xrange(2, 11)]
	
	ok = True
	for i in ints:
		if Miller(i) == True:
			ok = False
			break
	
	if not ok: continue
	
	divisors = []
	
	for i in ints:
		j = 3
		while j*j <= i:
			if i % j == 0:
				divisors.append(j)
				break
			j += 1
		
	if len(divisors) != len(ints):
		continue
	
	print s,
	for div in divisors: print div,
	print
	
	cnt += 1
	dic[s] = 1
			
	
			
	
