import sys

if __name__ == '__main__':
	fin = sys.stdin
	N = int(fin.readline())
	for i in xrange(N):
		line = fin.readline()
		arr = [int(v) for v in line.split()]
		(n,s,p) = arr[:3]
		t = arr[3:]
		thr1 = 3*p-2
		thr2 = 3*p-4
		tot = 0
		for v in t:
			if v >= thr1:
				tot += 1
			elif v >= thr2 and v>=2 and s>0:
				s -= 1
				tot += 1
		print 'Case #%d: %d' % (i+1,tot)
