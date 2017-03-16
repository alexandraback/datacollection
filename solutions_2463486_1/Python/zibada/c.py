from bisect import bisect
def palindrome(x):
	x = str(x)
	return x == x[::-1]

def precalc(N):
	res = []
	for i in xrange(N + 1):
		if palindrome(i) and palindrome(i * i):
			res.append(i * i)
	return res

numbers = precalc(10**7)
def solve():
	a, b = map(int, raw_input().split())
	return bisect(numbers, b) - bisect(numbers, a - 1)

for i in xrange(input()):
	print "Case #%d: %s" % (i + 1, solve())
