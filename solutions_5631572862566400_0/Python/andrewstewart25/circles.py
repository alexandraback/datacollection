from itertools import permutations
import sys

def toDict(l):
	d = {}
	for kid, bff in enumerate(l):
		d[kid+1] = bff
	return d


def f(line):
	bffs = toDict(map(int, line.split(' ')))
	n = len(bffs)
	best = 0
	for i in xrange(2, n+1):
		for s in permutations(xrange(1,n+1), i):
			for index, kid in enumerate(s):
				bff = bffs[kid]
				if s[index-1] == bff or s[(index+1)%i] == bff:
					continue
				break
			else:
				best = i
				continue
	return best
	
count = None
total = None
i = 0
for line in sys.stdin:
	line = line.strip()
	if (total == None):
		total = int(line)
		continue
	if (count == None):
		count = int(line)
		continue
	count = None
	i += 1
	print "Case #%s: %s"%(i,f(line))
	if i == total:
		break

