#!/usr/bin/env python
from sys import stdin, stderr
for T in range(1, 1+int(stdin.readline())):
	M={}
	S={}
	N=int(stdin.readline())
	for n in range(1, 1+N):
		m=map(int, stdin.readline().split())
		M[n]=m.pop(0)
		S[n]=m
	C={}
	def R(I, J):
		if I==J: return True
		if I>J: I, J=J, I
		if (I, J) in M: return C[I, J]
		for i in S[I]:
			r=R(i, J)
			if r:
				C[I, J]=r
				return r
		for j in S[J]:
			r=R(I, j)
			if r:
				C[I, J]=r
				return r
	print>>stderr, 'Case', T
	print>>stderr, M
	print>>stderr, S
	diamond=False
	for n in range(1, 1+N):
		m=M[n]
		s=S[n]
		print>>stderr, n, m, s
		for i in range(m):
			for j in range(1+i, m):
				I, J=s[i], s[j]
				if R(I, J):
					print>>stderr, I, J
					diamond=True
					break
			if diamond: break
		if diamond: break
	print 'Case #%d:'%T, 'Yes' if diamond else 'No'
