import sys
import string
t = int(sys.stdin.readline())
for i in range(t):
	line = sys.stdin.readline().strip().split()
	a = int(line[0])
	b = int(line[1])
	count = 0
	for n in range(a, b):
		ns = str(n)
		p = set([])
		for j in range(1,len(ns)):
			m = int(ns[j:] + ns[:j])
			if(m > n and m <= b and  m not in p):
				p.add(m)
				count += 1
	print 'Case #' + str(i+1) + ': ' + str(count)
			