import math


def is_palindrome(x):
	s = str(x)
	for i in range(len(s)):
		if s[i] != s[len(s)-i-1]:
			return False
	return True


T=int(raw_input())

# print "T",T
for t in range(T):
	# print t
	A, B = raw_input().split(' ')
	A, B = int(A), int(B)
	# print A,B
	a = int(math.ceil(math.sqrt(A)))
	b = int(math.floor(math.sqrt(B)))
	# print a,b
	count = 0
	for i in range(b-a+1):
		x = a+i
		# print "try ",x
		if is_palindrome(x):
			y = x*x
			if is_palindrome(y):
				# print y, " is a fair and square number of ",x
				count+=1
	s = "Case #"+str(t+1)+": "+str(count)
	print s