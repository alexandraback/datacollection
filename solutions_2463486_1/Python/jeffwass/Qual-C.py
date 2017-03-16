from math import sqrt

maxx = 10000000 #sqrt(10^14, can handle small and first large dataset easily with this)

mapp = set()
for x in range(1,maxx+1):
	if( str(x) != str(x)[::-1]):
		continue
	sqr = x*x
	if( str(sqr) != str(sqr)[::-1]):
		continue
	mapp.add(sqr)

base = "C-large-1"
f = open(base+'.in','r')
fout = open(base+'.out','w')

num = int(f.readline())
for case in range(1,num+1):
	prefix = "Case #" + str(case) + ": "
	l = f.readline()
	a,b = l.split()
	a = int(a)
	b = int(b)
	count = 0
	for sq in mapp:
		if( sq >= a and sq <= b ):
			count += 1
	fout.write( prefix + str(count) + "\n")

f.close
fout.close