import math
lines = open("C-small.in").readlines()

n = int(lines.pop(0))

def reverse(n):
	i = 0
	while n > 0:
		i *= 10
		i += n%10
		n //= 10

	return i


def isPalindrome(n):
	return n == reverse(n)

def isqrt(x):
	if x < 0:
		raise ValueError('square root not defined for negative numbers')
	n = int(x)
	
	if n == 0:
		return 0
	
	a, b = divmod(n.bit_length(), 2)
	x = 2**(a+b)
		
	while True:
		y = (x + n//x)//2
		if y >= x:
			return x
		x = y

for i in range(0, n):
	s = 0
	A, B = map(int, lines.pop(0).split())

	lb = isqrt(A)
	ub = isqrt(B)

	if not lb**2 == A:
		lb += 1
	
	j = lb
	while j <= ub:
		if isPalindrome(j) and isPalindrome(j**2):
			s += 1

		j += 1 

	print("Case #%s: %s" % (i + 1, s))
