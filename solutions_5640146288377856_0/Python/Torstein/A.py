def solve(R, C, W):
	## How many to eliminate a row?
	res = (R-1)*(C/W)
	#print "Elim. rows", res
		
	## Now have one row left
	DP = [i for i in xrange(C+1)]
	for i in xrange(W):
		DP[i] = -2**30
	
	for i in xrange(W+1, C+1):
		best = DP[i]
		#print i,":",
		for j in xrange(0,i):
			## Try picking j
			## Case 1: j is hitting
			case1 = W if j==0 or j==i-1 else W+1

			## Case 2: is not hitting
			## Case 2.1: is on left
			case21 = 1+DP[j] + ((i-j-1)/W) if j >= W else -1
			## Case 2.2: is on right
			case22 = 1+DP[i-j-1] + ((j)/W) if (i-j-1) >= W else -1
			case2 = max(case21, case22)
			best = min(best, max(case1, case2))
			#print j, "1:%d, 21:%d, 22:%d    "%(case1,case21,case22),
		DP[i] = best
		#print
	return res + DP[C]


testcases = int(raw_input().strip())
for testcase in xrange(testcases):
	R, C, W = map(int, raw_input().split())
	res = solve(R, C, W)
	print "Case #%d:"%(testcase+1), res
