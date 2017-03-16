from __future__ import division

filename = "A-large.in"

def solve(t, fin, fout):
	for i in xrange(t):
		ans = ""
		p, q = map(int, fin.readline().strip().split('/'))
		if q %2 != 0:
			fout.write("Case #%d: impossible\n" %(i+1))
			continue
		generation = 0
		if (q & (q-1)) != 0:
			divideby = q
			while divideby %2 ==0:
				divideby /= 2
			if p%divideby != 0:
				fout.write("Case #%d: impossible\n" %(i+1))
				continue
			else:
				p /= divideby
				q /= divideby
		while p<q:
			p *= 2
			generation += 1
		fout.write("Case #%d: %d\n" %((i+1), generation))
		


if __name__ == "__main__":
	fin = open(filename, 'r')
	fout = open('output.txt', 'w')
	t = int(fin.readline().strip())
	solve(t, fin, fout)