import sys
import math
sys.setrecursionlimit(10001)

def palindrome(num):
	s = str(num)
	return s == s[::-1]

T = int(sys.stdin.readline().strip())
for t in xrange(1, T+1):
	A, B = map(int, sys.stdin.readline().strip().split())
	a = int(math.ceil(math.sqrt(A)))
	b = int(math.floor(math.sqrt(B)))
	
	count = 0
	for i in xrange(a, b + 1):
		if palindrome(i) and palindrome(i ** 2):
			count += 1

	print "Case #{}: {}".format(t, count)
