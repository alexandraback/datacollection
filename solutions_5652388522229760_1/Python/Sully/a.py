import sys

f = open(sys.argv[1],'r')


def sleep(n):
	d = {}
	m = n
	for j in xrange(1,1000000):
		for s in str(m):
			if s in d:
				continue
			else:
				d[s] = 1
				if len(d.keys())==10:
					return m
		m=n*j
	return 'INSOMNIA'
					


f.readline()
i=1
for line in f:
	print "Case #"+str(i)+': '+str(sleep(int(line.strip('\n'))))
	i+=1

