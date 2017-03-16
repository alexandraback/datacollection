import math, sys

def prepare():
	solutions = []
	for x in range(1, int(math.floor(math.sqrt(100000000000000))) + 1):
		if isPalindrome(x) and isPalindrome(x*x):
			solutions.append(x*x)
	print solutions

def isPalindrome(x):
	return str(x) == str(x)[::-1]

solutions = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001L, 10221412201L, 12102420121L, 12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L, 1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L, 4000008000004L, 4004009004004L]

f = open(sys.argv[1], "r")

n = int(f.readline().strip())
for t in range(1, n + 1):
	a, b = map(int, f.readline().strip().split(" "))
	
	count = 0;
	for x in solutions:
		if a <= x and x <= b:
			count += 1
	
	print "Case #%d: %d" % (t, count)
	
f.close()