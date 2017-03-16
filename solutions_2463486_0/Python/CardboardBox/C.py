import math
n_cases = input()

def palindrome(i):
	return str(i) == str(i)[::-1]

def solve():
	a,b = map(eval,raw_input().split())
	s = int(math.ceil(math.sqrt(a)))
	l = int(math.floor(math.sqrt(b)))
	n = 0
	for i in range(s,l+1):
		if palindrome(i):
			if palindrome(i*i):
				n += 1
	return n

for case in range(1,n_cases+1):
	print 'Case #'+`case`+': '+`solve()`