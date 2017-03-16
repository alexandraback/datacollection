T = int(raw_input())

def test(seq, k):
#	print k, k + sum((r-1)/k for r in seq)
	return k + sum((r-1)/k for r in seq)

def doprob():
	D = int(raw_input())
	read = raw_input()
	read = [int(x) for x in read.split()]
	c = max(read)
#	print read
	results = [(test(read, x), x) for x in xrange(1,c+1)]
	results.sort()
	return results[0][0]

for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())