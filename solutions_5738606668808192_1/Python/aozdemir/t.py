import itertools as it
N = 32
J = 500
c = [0]*N
c[0] = 1
c[-1] = 1

C = []

def do():
	global C
	count = 0
	for os in it.combinations(xrange(2, N -1, 2), 8):
		for es in it.combinations(xrange(1, N-1, 2), 8):
			if count == J:
				return
			d = c[:]
			for o in os:
				d[o] = 1
			for e in es:
				d[e] = 1
			s = ''.join(map(str,d))
			i = int(s,6)
			f = factorLessThanN(i, 1000)
			if f > 0:
				count += 1
				C.append((s, [3, 2, 3, 2, f, 2, 3, 2, 3]))


def factorLessThanN(x, n):
	for i in xrange(2, n):
		if x % i == 0:
			return i
	return 0

do()
for (N, f) in C:
	for i in range(2,11):
		if int(N, i) % f[i-2] != 0:
			assert False, "%s, %s, %s !!!" % ( N, i, f)

print "Case #1:"
for (N, f) in C:
	print "%s %s" % (N, ' '.join(map(str,f)) )
