testcases = int(raw_input().strip())


def bw(num):
	res = 0
	while num > 0:
		res = 10*res + (num%10)
		num = num/10
	return res

for testcase in xrange(testcases):
	n = int(raw_input().strip())		
	res = 1
	DP = [2**30]*(n+1)
	DP[1] = 1
	for i in xrange(2,n+1):
		shortest = DP[i-1]+1
		backwards = bw(i)
		#print i, bw(i),
		if (i%10) != 0 and backwards < i:
			#print DP[i-1]+1, DP[backwards]+1
			DP[i] = min(DP[i-1]+1, DP[backwards]+1)
		else:
			#print
			DP[i] = DP[i-1]+1
	#print DP
	print "Case #%d:" % (1+testcase), DP[n]
