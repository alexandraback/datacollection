debug = 0
tn = input()
def solve(l, r, start, end):
	if l == r:
		return 0
	mv = V[l]
	mi = l
	for i in xrange(l, r):
		if V[i] >= mv:
			mi = i
			mv = V[i]
	i = mi
	v = mv
	c = 0
	c += solve(l, i, start, E)
	save = end - (r-i)*R
	if save < 0:
		save = 0
	if save > min(E, start+R*(i-l)):
		save = min(E,start+R*(i-l))
	if debug: print '<',l, r, start,end, c, save
	c += (min(E, start+R*(i-l)) - save)*v
	if debug: print '>',l, r, start,end, c, save
	c += solve(i+1, r, min(E,save+R), end)
	if debug: print l, r, start,end, c, save
	return c
for loop in xrange(tn):
	print 'Case #%d:'%(loop+1),
	if debug: print
	E, R, N = [int(x) for x in raw_input().split()]
	V = [int(x) for x in raw_input().split()]
	print solve(0, N, E, R)
