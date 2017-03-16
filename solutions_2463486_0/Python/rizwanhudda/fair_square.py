from bisect import bisect_left

def find_ge(a, x):
	'Find leftmost item greater than or equal to x'
	i = bisect_left(a, x)
	#if i != len(a):
	#    return a[i]
	#raise ValueError
	return i

def isPresent(a, x):
	i = find_ge(a, x)
	return i < len(a) and a[i] == x

def isPalindrome(s):
	l = 0
	r = len(s) - 1
	while l < r:
		if s[l] != s[r]: return False
		l += 1
		r -= 1
	return True

def computeGood():
	global good
	palindromes = range(1, 10)
	for num in range(1, 1000):
		l = str(num)
		r = l[::-1] 
		palindromes.append(int(l + r)) # even length(2*l)
		for  m in range(10):
			palindromes.append(int(l + str( m) + r))# odd length(2*l + 1)
	good = filter(lambda n: isPalindrome(str(n)), map(lambda n: n*n, palindromes))
	good.sort()
	#print good

good = []
computeGood()
t = input()
for case_no in range(1, t+1):
	a, b = map(int, raw_input().split())
	print 'Case #%d: %d' % (case_no, find_ge(good, b) - find_ge(good, a) + isPresent(good, b))