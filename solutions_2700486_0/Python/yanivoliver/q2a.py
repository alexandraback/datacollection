import sys

def main():
	testCases = int(raw_input())
	#print testCases
	testCount = 1
	while (testCount <= testCases):
		testCase = []
		(n, x, y) = raw_input().split(" ")
		diamonds = []

		result = handleTest(int(n), int(x), int(y))

		print "Case #%d:" % (testCount),
		print(result)

		testCount += 1

	return 0

def handleTest(N, x, y):
	h = abs(y)+1
	a = ((abs(x)+abs(y))/2)+1
	n1 = (2*a-3)*(a-1)
	n2 = (2*a-1)*a

#	print h, a, n1, n2

	if (N <= n1):
		return 0.0
	if (N >= n2):
		return 1.0
	if (h == 2*a-1):
		return 0.0

	return calc(2*a-2, h, h, N-n1)

def calc(l, r, h, n):
#	print l, r, h, n

	if (h == 0):
		return 1.0
	if (n == 0):
		return 0.0
	if (l == 0):
		if (n >= h):
			return 1.0
		if (n < h):
			return 0.0

	res_l = 0.5*calc(l-1, r, h, n-1)
#	print "R"
	res_r = 0.5*calc(l,r-1,h-1,n-1)
#	print "Result: ",
#	print(res_l + res_r)
	return res_l + res_r

if __name__ == "__main__":
	main()
