import math

def isPalindrome(string):
	i = 0
	while i < len(string):
		if string[i] != string[-(i+1)]:
			return False
		i += 1
	return True

def problem():	
	theFile = open("C-large-1.in")
	N = int(theFile.readline())
	precompute = []
	x = 0
	i = 1
	while x < 10**14:
		squirt = math.sqrt(x)
		if (isPalindrome(str(x)) and isPalindrome(str(int(squirt)))):
			precompute.append(x)
		x = i ** 2
		i += 1
	for k in range(N):
		minimum, maximum = [int(x) for x in theFile.readline().split(' ')]
		count = 0
		for x in precompute:
			if x >= minimum and x <= maximum:
				count += 1
		print "Case #%d: %d" % (k+1, count)
		
	print

problem()
