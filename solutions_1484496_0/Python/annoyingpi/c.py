import itertools
def findsubsets(S,m):
	    return set(itertools.combinations(S, m))

for T in xrange(int(raw_input())):
	d = [int(i) for i in raw_input().split()]
	N = d[0]
	nums = d[1:]
	sums = {}
	done = False
	print "Case #%d:" % (T+1)
	for i in xrange(20):
		if done:
			break
		for a in list(findsubsets(nums, i)):
			if sum(a) in sums:
				done = True
				print ' '.join([str(j) for j in sums[sum(a)]])
				print ' '.join([str(j) for j in a])
				break
			else: 
				sums[sum(a)] = a
		
