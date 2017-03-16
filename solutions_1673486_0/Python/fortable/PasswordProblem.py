#!/bin/python

import sys

def foo(A, B, P):
		res = []
		for c in range(A):
				p = reduce(float.__mul__, P[:len(P)-c], 1.)
				res.append( (B - A + 2*c+1) * p + 
								(2*B -A + 2*c + 2) * (1-p))
		res.append(B+2.0)
		return min(res)

if __name__ == "__main__":
		T = int(sys.stdin.readline()[:-1])
		for t in range(T):
				A, B = map(lambda x: int(x), sys.stdin.readline()[:-1].split(" "))	
				P = map(lambda x: float(x), sys.stdin.readline()[:-1].split(" "))
				print "Case #"+str(t+1)+": "+str(foo(A, B, P))
