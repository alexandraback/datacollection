def rotate(n, i):
	j = 0
	s = str(n)
	while(j < i):
		s = s[-1] + s[:-1]
		j += 1
	return int(s)
	
def rn(n, m):
	count = 0
	for i in range(n,m+1):
		r_l = []
		r = len(str(i))-1
		for j in range(1,r+1):
			r2 = rotate(i, j)
			if r2 not in r_l:
				r_l.append(r2)
				if(i < r2 and r2 <= m and len(str(i).replace('0','')) == len(str(r2).replace('0',''))):
					count += 1
	return count
	
f = open("C-small-attempt0.in")
T = f.readline()
c = 1
for line in f:
	n,m = map(int, line.strip().split())
	print "Case #" + str(c) + ": " + str(rn(n,m))
	c += 1
