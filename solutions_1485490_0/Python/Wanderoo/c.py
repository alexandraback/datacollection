# usage c.py <infile> > outfile
import sys

def getmax(memo, a, b, i, j):
	if (i >= len(a) or j >= len(b)):
		return 0
	if (i, j) in memo:
		return memo[(i, j)]
	total = 0
	if a[i][1] == b[j][1]:
		used = min(a[i][0], b[j][0])
		total += used
		if a[i][0] == b[j][0]:
			total += getmax(memo, a, b, i + 1, j + 1)
		elif a[i][0] < b[j][0]:
			origa, origb = a[i][0], b[j][0]
			a[i][0] = 0
			b[j][0] -= used
			total += getmax(memo, a, b, i + 1, j)
			a[i][0], b[j][0] = origa, origb
		else:
			origa, origb = a[i][0], b[j][0]
			a[i][0] -= used
			b[j][0] -= 0
			total += getmax(memo, a, b, i, j + 1)
			a[i][0], b[j][0] = origa, origb
	else:
		total += max(getmax(memo, a, b, i + 1, j), getmax(memo, a, b, i, j + 1))
	memo[(i, j)] = total
	return total

infile = sys.argv[1]

f = open(infile, "r")

T = (int) (f.readline().strip())

for t in range(1, T + 1):
	(N, M) = map(int, f.readline().split())

	aa = map(int, f.readline().split())
	bb = map(int, f.readline().split())
		
	a = []
	b = []
	
	for i in range(N):
		a.append([aa[2*i], aa[2*i+1]])
	
	for i in range(M):
		b.append([bb[2*i], bb[2*i+1]])
	
	memo = {}
	result = getmax(memo, a, b, 0, 0)
		
	print "Case #%d: %s" % (t, result)
	
f.close()
