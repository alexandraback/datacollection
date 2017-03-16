import math

def isPalindrome(string):
	i = 0
	while i < len(string):
		if string[i] != string[-(i+1)]:
			return False
		i += 1
	return True

def problem():
	theFile = open("C-small-attempt0.in")
	N = int(theFile.readline())
	precompute = []
	for x in range(0,1001):
		#print math.sqrt(x), math.floor(math.sqrt(x))
		squirt = math.sqrt(x)
		precompute.append(squirt == math.floor(squirt) and isPalindrome(str(x)) and isPalindrome(str(int(squirt))))
	for k in range(N):
		minimum, maximum = [int(x) for x in theFile.readline().split(' ')]
		count = 0
		for x in range(minimum,maximum+1):
			if precompute[x]:
				count += 1
		print "Case #%d: %d" % (k+1, count)
		
	print

problem()
