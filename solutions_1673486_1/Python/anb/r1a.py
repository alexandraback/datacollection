from sys import stdin
from operator import mul
from decimal import *

def right_away(B):
	return B + 2

def keep_typing(A, B, p):
	ok = reduce(mul, p)
	return ok * (B - A + 1) + (1 - ok) * (B - A + B + 2)
	
def backspace(A, B, p):
	results = []
	ok = reduce(mul, p)
	c_ok = ok
	for i in xrange(1, A + 1):
		c_ok = ok / p[-i] * (1 - p[-i])
		results.append((ok + c_ok) * (B - A + 1 + 2 * i) + (1 - (ok + c_ok)) * (B - A + B + 2 + 2 * i))
	return min(results)
	
def keystrokes(A, B, p):
	k = ( right_away(B), keep_typing(A, B, p), backspace(A, B, p) )
	return min(k)

def program():
	T = int(stdin.readline())
	for Ti in xrange(T):
		A, B = map(int, stdin.readline().rstrip().split(' '))
		p = map(Decimal, stdin.readline().rstrip().split(' '))
		
		k = keystrokes(A, B, p)
		
		print 'Case #%d: %f' % (Ti + 1, k)	
	
if __name__ == '__main__':
	program()