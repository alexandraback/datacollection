import os, sys, fractions
problem = sys.argv[0].split('.')[0]
try:
    fn = "%s-small-attempt%s.in" % (problem, sys.argv[1])
except:
    fn = "%s-large.in" % problem
lines = [line.strip() for line in open(fn)][::-1]
fout = open("%s.out" % problem,"w+")

denominators = map(lambda x: 2**x, xrange(1,41))

for case in range(int(lines.pop())):
	pq = fractions.Fraction(lines.pop())
	q = pq.denominator
	y = 'impossible'
	if pq.denominator in denominators:
		for i in xrange(1,41):
			pq *= 2
			if pq >= 1:
				y = i
				break
	print >>fout, "Case #%s: %s" % ((case+1),y)


