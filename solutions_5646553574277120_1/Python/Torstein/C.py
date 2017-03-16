def solve():
	res = 1 if 1 not in denoms else 0
	if 1 not in denoms:
		denoms.insert(0,1)			
	
	maxies = []
	i = 0
	## Add denoms in between
	while i < len(denoms):
		maxi = denoms[i]*C if i==0 else denoms[i]*C+maxies[i-1]
		if i > 0 and maxies[i-1] < denoms[i]-1:
			denoms.insert(i,maxies[i-1]+1)
			res += 1
			continue
		maxies.append(maxi)
		i += 1
	
	## Add denoms at end
	while maxies[-1] < V:
		denoms.append(maxies[-1]+1)
		maxi = denoms[-1]*C+maxies[-1]
		maxies.append(maxi)
		res += 1

	return res

testcases = int(raw_input().strip())
for testcase in xrange(testcases):
	C, D, V = map(int, raw_input().split())
	denoms = map(int, raw_input().split())
	denoms.sort()
	res = solve()
	print "Case #%d:"%(testcase+1), res
