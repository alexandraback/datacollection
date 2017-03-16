import sys

z = int(raw_input())

for t in xrange(z):
	tmp = raw_input().split()
	t1 = tmp[0]
	t2 = tmp[1]
	n = len(t1)
	
	best1 = 0
	best2 = 10**5

	for x in xrange(10**n):
		for y in xrange(10**n):
			if abs(x-y) > abs(best1-best2):
				continue
			if abs(x-y) == abs(best1-best2):
				if x > best1:
					continue
				if x == best1:
					if y > best2:
						continue
			t1p = str(x).rjust(n, '0')
			t2p = str(y).rjust(n, '0')
			f = True
			for k in xrange(n):
				if t1[k] != '?' and t1[k] != t1p[k]:
					f = False
				if t2[k] != '?' and t2[k] != t2p[k]:
					f = False
			if f:
				best1 = x
				best2 = y 
			

	sys.stdout.write("Case #" + str(t+1) + ": " + str(best1).rjust(n, '0') + " " + str(best2).rjust(n, '0') + '\n')

