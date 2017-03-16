import sys
fname = "D-small-attempt0.in"
fname = "D-large.in"
# fname = "sample.in"
fi = open(fname)
fo = open("fo.txt","w")
def check(a,b):
	j = 0
	t = 0
	print n
	for i in range(n):
		while j < n and b[i]>a[j]:
			j+=1
		if j >=n: 
			break
		print a[i],b[j]
		j += 1
		t += 1
	return t
for test in range(int(fi.readline())):
	n = int(fi.readline())
	a = [float(x) for x in fi.readline().strip().split()]
	b = [float(x) for x in fi.readline().strip().split()]
	a.sort()
	b.sort()

	print a
	print b
	ra,rb = check(a,b),check(b,a)
	print >>fo,"Case #%d: %d %d"%(test+1, ra,n-rb)
