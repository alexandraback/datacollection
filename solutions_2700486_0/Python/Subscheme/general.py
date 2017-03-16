#from sys import stdin as fin, stdout as fout
from collections import defaultdict
fin = open('input.txt'); fout = open('output.txt','w')
get = lambda: map(int,fin.readline().split())

def memo(f):
	cache = dict()
	def wrap(*args):
		if args not in cache: cache[args] = f(*args)
		return cache[args]
	return wrap


T, = get()

for case in range(1,T+1):

	N,X,Y = get()
	
	N -= 1
	diff = 5
	height = 1

	while N>=diff:
		N -= diff
		diff += 4
		height += 1

	if (abs(X)+Y)/2 < height:
		p = 1.0
	elif (abs(X)+Y)/2 > height:
		p = 0.0
	else:

		space = defaultdict(lambda: 0.0)
		space[0] = 1.0
		height += 2

		for tot in range(N):
			nspace = defaultdict(lambda: 0.0)
			for filled, prob in space.iteritems():
				if filled < height and tot-filled < height:
					nspace[filled+1] += prob*0.5
					nspace[filled] += prob*0.5
				elif filled < height:
					nspace[filled+1] += prob
				elif tot-filled < height:
					nspace[filled] += prob
				else:
					assert False
				
			space = nspace

		p = sum(space[f] for f in xrange(Y+1,height+2))


	fout.write('Case #%d: %.10f\n' % (case,p))
