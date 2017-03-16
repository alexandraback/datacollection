from pprint import pprint
def is_palinedome(x):
	sx = str(x)
	return (sx == sx[::-1])
#for k in range(4):
#	for i in range(10**k, 10**(k+1)):
#		j = long(str(i)+str(i)[-2::-1])
#		if is_palinedome(j*j):
#			print j*j
#	for i in range(10**k, 10**(k+1)):
#		j = long(str(i)+str(i)[::-1])
#		if is_palinedome(j*j):
#			print j*j
#raise SystemExit
p = ['']
for n in range(10):
	if is_palinedome(n**2):
		#print n
		p.append(str(n))
np = list()
for t in range(2, 52, 2):
	for x in p:
		lx = len(x)
		nz = (t-lx-1)/2
		n = '1'+'0'*nz+x+'0'*nz+'1'
		if is_palinedome(long(n)**2):
			#print n
			np.append(n)
		n = '2'+'0'*nz+x+'0'*nz+'2'
		if is_palinedome(long(n)**2):
			#print n
			np.append(n)
	p.extend(np)
	np = list()
p = map(lambda x:long(x)**2, p[2:])
p.sort()
#pprint(p)

def bs(p, n):
	if p[0] > n:
		return 0
	elif p[-1] <= n:
		return len(p)
	l, h = 0, len(p)-1
	while(h - l > 1):
		m = (h+l)/2
		if p[m] <= n:
			l = m
		else:
			h = m
	return h
t = int(raw_input())
for _ in range(1, t+1):
	a, b = map(int, raw_input().split())
	print 'Case #%d: %d' % (_, bs(p, b) - bs(p, a-1))
