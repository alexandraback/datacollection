f = open("input2.txt", "rb")
g = open("output2.txt", "wb")
n = int(f.readline().strip())
for y in xrange(n):
	e,r,n = map(int,f.readline().strip().split())
	v = map(int,f.readline().strip().split())
	remaining = e
	w = [0] * len(v)
	for i in xrange(n):
		w[i] = remaining
		for j in xrange(i+1, min(n,i+e/r+1)):
			if(v[j]>v[i]):
				w[i] = max(0,remaining - e + r*(j-i))
				break
		if(i==0):
			remaining = min(e,e - w[i] + r)
		else:
			remaining = min(e,remaining - w[i] + r)
	total = 0
	for i in xrange(n):
		total += w[i]*v[i]
	g.write("Case #%d: %d\n" % (y+1, total))
f.close()
g.close()