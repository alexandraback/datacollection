#!/usr/bin/python

import math
import sys
import math

def equal(a,b):
	return math.rabs(a-b) <= 0.000001

def replaceHigh(s):
	if len(s) == 0:
		return 0
	return int(s.replace('?', '9'))

def replaceLow(s):
	if len(s) == 0:
		return 0
	return int(s.replace('?', '0'))

def getDigit(d, N):
	return d * int(math.pow(10, N-1))

def pad(s, N):
	S = str(s)
	for _ in range(N-len(S)):
		S = '0' + S
	return S

def solve(C,J,N):
	if N == 0:
		return 0, 0

	if C[0] != '?' and J[0] != '?':
		if C[0] > J[0]:
			return replaceLow(C), replaceHigh(J)
		elif J[0] > C[0]:
			return replaceHigh(C), replaceLow(J)
		else:
			c, j = solve(C[1:], J[1:], N-1)
			return getDigit(int(C[0]),N) + c, getDigit(int(J[0]), N) + j

	known = None
	if C[0] == '?' and J[0] == '?':
		known = 0
	elif J[0] != '?':
		known = int(J[0])
	else:
		known = int(C[0])

	c, j = solve(C[1:], J[1:], N-1)
	#if N == 2:
	#	print c,j
	op0 = math.fabs(c - j)

	clow = replaceLow(C[1:])
	jhigh = replaceHigh(J[1:])
	chigh = replaceHigh(C[1:])
	jlow = replaceLow(J[1:])

	# C[0] = 0, J[0] = 1
	op1 = sys.maxint
	if J[0] != '?' and int(J[0]) >= 1:
		op1 = math.fabs(getDigit(1,N) + jlow - chigh)
	if C[0] != '?' and int(C[0]) <= 8:
		op1 = math.fabs(getDigit(1,N) + jlow - chigh)
	if C[0] == '?' and J[0] == '?':
		op1 = math.fabs(getDigit(1,N) + jlow - chigh)

	# C[0] = 1, J[0] = 0
	op2 = sys.maxint
	if J[0] != '?' and int(J[0]) <= 8:
		op2 = math.fabs(getDigit(1,N) + clow - jhigh)
	if C[0] != '?' and int(C[0]) >= 1:
		op2 = math.fabs(getDigit(1,N) + clow - jhigh)
	if C[0] == '?' and J[0] == '?':
		op2 = math.fabs(getDigit(1,N) + clow - jhigh)

	#print C, J, op0, op1, op2


	if op0 <= op1 and op0 <= op2:
		#print 'yolo'
		return getDigit(known, N) + c, getDigit(known, N) + j
	elif op1 <= op2:
 		if J[0] != '?' and int(J[0]) >= 1:
			return chigh + getDigit(known-1, N), jlow + getDigit(known, N)
		if C[0] != '?' and int(C[0]) <= 8:
			return chigh + getDigit(known, N), jlow + getDigit(known+1, N)
		if C[0] == '?' and J[0] == '?':
			return chigh, jlow + getDigit(1, N)
	else:	
		#print 'DOH'
		if J[0] != '?' and int(J[0]) <= 8:
			#print "a"
			return clow + getDigit(known+1, N), jhigh + getDigit(known, N)
		if C[0] != '?' and int(C[0]) >= 1:
			#print "b"
			return clow + getDigit(known, N), jhigh + getDigit(known-1, N)
		if C[0] == '?' and J[0] == '?':
			#print "c"
			return clow + getDigit(1, N), jhigh

	return "ERROR"

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		C, J = sys.stdin.readline().split()
		N = len(C)
		c, j = solve(C,J,N)
		print "Case #{}: {} {}".format(t+1, pad(c, N), pad(j, N))
