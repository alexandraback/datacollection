
def brute(line):
	c, j = line.split()
	c = [int(x) if x != '?' else -1 for x in c]
	j = [int(x) if x != '?' else -1 for x in j]
	n = len(c)

	sols = []
	def recgen(solc,solj,i):
		if i == n:
			sols.append((abs(solc-solj),solc,solj))
		else:
			if c[i] == -1 and j[i] == -1:
				for cval in xrange(10):
					for jval in xrange(10):
						recgen(10*solc+cval,10*solj+jval,i+1)
			elif c[i] == -1:
				for cval in xrange(10):
					recgen(10*solc+cval,10*solj+j[i],i+1)
			elif j[i] == -1:
				for jval in xrange(10):
					recgen(10*solc+c[i],10*solj+jval,i+1)
			else:
				recgen(10*solc+c[i],10*solj+j[i],i+1)

	recgen(0,0,0)
	sols.sort()
	s = sols[0]
	return ('0'*n+str(s[1]))[-n:] + ' ' + ('0'*n+str(s[2]))[-n:]

def solve(line):
	c, j = line.split()
	c = [int(x) if x != '?' else -1 for x in c]
	j = [int(x) if x != '?' else -1 for x in j]
	n = len(c)

	def maxcminj(solc,solj,i):
		if i == n:
			return (solj-solc,solc,solj)
		if c[i] == -1 and j[i] == -1:
			return maxcminj(10*solc+9,10*solj+0,i+1)
		elif c[i] == -1:
			return maxcminj(10*solc+9,10*solj+j[i],i+1)
		elif j[i] == -1:
			return maxcminj(10*solc+c[i],10*solj+0,i+1)
		else:
			return maxcminj(10*solc+c[i],10*solj+j[i],i+1)

	def mincmaxj(solc,solj,i):
		if i == n:
			return (solc-solj,solc,solj)
		if c[i] == -1 and j[i] == -1:
			return mincmaxj(10*solc+0,10*solj+9,i+1)
		elif c[i] == -1:
			return mincmaxj(10*solc+0,10*solj+j[i],i+1)
		elif j[i] == -1:
			return mincmaxj(10*solc+c[i],10*solj+9,i+1)
		else:
			return mincmaxj(10*solc+c[i],10*solj+j[i],i+1)

	def recsolve(solc,solj,i):
		if i == n:
			return (abs(solc-solj),solc,solj)
		if c[i] == -1 and j[i] == -1:
			a = maxcminj(10*solc+0,10*solj+1,i+1)
			b = recsolve(10*solc,10*solj,i+1)
			d = mincmaxj(10*solc+1,10*solj+0,i+1)
			return min(a,b,d)
		elif c[i] == -1:
			a = (10**20,0,0)
			d = (10**20,0,0)
			if j[i] > 0:
				a = maxcminj(10*solc+j[i]-1,10*solj+j[i],i+1)
			b = recsolve(10*solc+j[i],10*solj+j[i],i+1)
			if j[i] < 9:
				d = mincmaxj(10*solc+j[i]+1,10*solj+j[i],i+1)
			return min(a,b,d)
		elif j[i] == -1:
			a = (10**20,0,0)
			d = (10**20,0,0)
			if c[i] < 9:
				a = maxcminj(10*solc+c[i],10*solj+c[i]+1,i+1)
			b = recsolve(10*solc+c[i],10*solj+c[i],i+1)
			if c[i] > 0:
				d = mincmaxj(10*solc+c[i],10*solj+c[i]-1,i+1)
			return min(a,b,d)
		else:
			if c[i] > j[i]:
				return mincmaxj(10*solc+c[i],10*solj+j[i],i+1)
			elif j[i] > c[i]:
				return maxcminj(10*solc+c[i],10*solj+j[i],i+1)
			else:
				return recsolve(10*solc+c[i],10*solj+j[i],i+1)

	s = recsolve(0,0,0)
	return ('0'*n+str(s[1]))[-n:] + ' ' + ('0'*n+str(s[2]))[-n:]

'''
# TESTING CODE

import random
def genrand(size,qs):
	x = [str(random.randint(0,9)) for i in xrange(size)]
	y = [str(random.randint(0,9)) for i in xrange(size)]

	qcount = 0
	while qcount < qs:
		use = x
		if random.random() < 0.5:
			use = y
		pos = random.randint(0,size-1)
		if use[pos] != '?':
			qcount += 1
		use[pos] = '?'

	return ''.join(x) + ' ' + ''.join(y)

for i in xrange(100):
	gen = genrand(18,4)
	sans = solve(gen)
	bans = brute(gen)
	print gen, sans, bans, sans==bans
	if sans != bans:
		print "BAD"
		break

'''


output = []
with open('B_input.txt') as f:
	t = int(f.readline())
	for i,line in enumerate(f):
		output.append("Case #%d: %s\n" % (i+1,solve(line.strip())))

with open('B_output.txt','w') as f:
	for line in output:
		print line,
		f.write(line)