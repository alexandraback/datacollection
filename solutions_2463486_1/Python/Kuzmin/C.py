import math
lines = open("C-large-1.in").readlines()

maxB = 10**7
minA = 1

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

palindromeSquares = []
i = minA
while i <= maxB:
	if isPalindrome(i) and isPalindrome(i**2):
		palindromeSquares.append(i**2)

	i += 1
		
for i in range(0, n):
	s = 0
	A, B = map(int, lines.pop(0).split())
	
	"""lb = isqrt(A)
	ub = isqrt(B)

	if not lb**2 == A:
		lb += 1
	
	j = lb
	while j <= ub:
		if isPalindrome(j) and isPalindrome(j**2):
			print(j, j**2)
			s += 1

		j = addOne(j) 
"""
	s = len([a for a in palindromeSquares if a >= A and a <= B]) 
	print("Case #%s: %s" % (i + 1, s))
