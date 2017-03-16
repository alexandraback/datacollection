import sys
import math
import decimal

num_of_test_cases = int(sys.stdin.readline())
for k in xrange(1, num_of_test_cases + 1):
	A,B,K = map(int, sys.stdin.readline()[:-1].split(" "))

	y = 0


	for i in xrange(A):
		for j in xrange(B):
			if (i & j) < K:
				y += 1
				#print y,i,j,i&j, K, (i & j) < K
	print "Case #{}: {}".format(k, y)