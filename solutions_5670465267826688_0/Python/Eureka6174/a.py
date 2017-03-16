import itertools
def mul(a, b):
	c = 1
	f = 1
	if a[0] == '1':
		c = b[0]
	elif b[0] == '1':
		c = a[0]
	elif a[0] == b[0]:
		c = '1'
		f = -1
	else:
		s = 'ijkijk'
		for i in range(3):
			if a[0] == s[i] and b[0] == s[i+1]:
				c = s[i+2]
			if b[0] == s[i] and a[0] == s[i+1]:
				c = s[i+2]
				f = -1
	f *= a[1] * b[1]
	return (c, f)
	
def gao(l):
	first = {}
	last = {}
	t = ('1', 1)
	for i in range(len(l)):
		if t not in first:
			first[t] = i
		last[t] = i
		t = mul(t, l[i])
	if t != ('1', -1):
		return 'NO'
	if ('i', 1) in first and ('k', 1) in last and first[('i', 1)] < last[('k', 1)]:
		return 'YES'
	else:
		return 'NO'


div = {}
s = '1ijk'
f = [1, -1]
for a in itertools.product(s, f):
	for b in itertools.product(s, f):
		c = mul(a, b)
		div[(c, b)] = a

t = int(input())
for cas in range(t):
	(n, x) = list(map(int, input().split()))
	if x > 16:
		x = x % 16 + 16
	s = input() * x
	l = [(i, 1) for i in s]
	print('Case #%d:' % (cas+1), end=' ')
	print(gao(l))
