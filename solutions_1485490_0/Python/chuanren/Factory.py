#!/usr/bin/env python
from sys import stdin
for T in range(1, 1+int(stdin.readline())):
	N, M=map(int, stdin.readline().split())
	A=map(int, stdin.readline().split())
	a=A[0::2]
	A=A[1::2]
	B=map(int, stdin.readline().split())
	b=B[0::2]
	B=B[1::2]
	def box(a, A, b, B):
		if not a: return 0
		O=box(a[1:], A[1:], b, B)
		C=A[0]
		if C in B:
			m=B.index(A[0])
			if a[0]<b[m]:
				b=b[m:]
				b[0]-=a[0]
				o=a[0]+box(a[1:], A[1:], b, B[m:])
			elif a[0]>b[m]:
				a=a[0:]
				a[0]-=b[m]
				o=b[m]+box(a, A, b[m+1:], B[m+1:])
			else:
				o=a[0]+box(a[1:], A[1:], b[m+1:], B[m+1:])
			return max(o, O)
		return O
	print 'Case #%d:'%T, box(a, A, b, B)
