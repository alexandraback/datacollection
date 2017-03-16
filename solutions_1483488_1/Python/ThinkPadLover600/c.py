from sys import stdin
def rline():
	return stdin.readline().rstrip()

for l in range(int(rline())):
	(n,m) = map(int, rline().split())
	total = 0
	length = len(str(n))
	highest_first_digit = str(m)[0]
	for k in range(n, m+1):
		s1 = str(k)
		total += len([x for x in set([int(s1[n:]+s1[:n]) for n in range(length)]) if x > k and x <= m])
	print "Case #%s: %s" % (l+1, total)
