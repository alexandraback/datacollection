import sys, math
sys.setrecursionlimit(10001)

P = [1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002]

def palindrome(num):
	s = str(num)
	return s == s[::-1]

T = int(sys.stdin.readline().strip())
for t in xrange(1, T+1):
	A, B = map(int, sys.stdin.readline().strip().split())
	a = int(math.ceil(math.sqrt(A)))
	b = int(math.floor(math.sqrt(B)))
	
	count = 0
	for p in P:
		if a <= p and p <= b:
			count += 1

	print "Case #{}: {}".format(t, count)
