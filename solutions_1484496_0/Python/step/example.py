import sys
def decode(x, nums, N):
	res = []
	for b in xrange(N):
		if x & (2**b):
			res.append( nums[ b] )
	return res

# Read number of cases
for tc in xrange(1, int(sys.stdin.readline())+1):
# Read integers from a line
	print 'Case #%d:' % tc
	nums = [int(w) for w in sys.stdin.readline().split()]

	N = nums[0]
	nums =  nums[1:]
	sums = {}

	found = False
	for i in xrange(2**N):
		l = decode( i, nums, N )
		s = sum( l )

		if s in sums:
			l2 = decode( sums[s], nums, N )
			print " ".join([ str(x) for x in l])
			print " ".join([ str(x) for x in l2])
			found = True
			break
		else:
			sums[s] = i
	if not found:
		print "Impossible"

