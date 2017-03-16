import math
import sys

MASK = [int(math.pow(10,v)) for v in xrange(0,9)]

def count(A,B,X):
	N = len(str(X))
	S = set()
	count = 0
	for i in xrange(1,N):
		Y = int(math.floor((X%MASK[i])*(MASK[N]/MASK[i])+X/MASK[i]))
		if X<Y and Y<=B and Y not in S:
			count += 1
			S.add(Y)
	return count

def countAll(A,B):
	tot = 0
	for x in xrange(A,B+1):
		tot += count(A,B,x)
	return tot

if __name__ == '__main__':
	fin = sys.stdin
	T = int(fin.readline())
	for t in xrange(T):
		(A,B) = [int(v) for v in fin.readline().split()]
		print 'Case #%d: %d' % (t+1,countAll(A,B))
