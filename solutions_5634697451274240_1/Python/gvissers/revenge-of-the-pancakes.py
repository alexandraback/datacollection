#!/usr/bin/python3

def flip(s):
	return ''.join('+' if c == '-' else '-' for c in s)

def count(s):
	#print('s ="%s"' % s)
	if s not in cache:
		l = len(s)
		#print('l = %d' % l)
		idx = s.rfind('-')
		#print('idx = %d' % idx)
		if idx == -1:
			cache[s] = 0
		elif idx == l-1:
			#print('pfx = %s, flip(pfx) = %s' % (s[:-1], flip(s[:-1])))
			n0 = 1 + count(flip(s[:-1]))
			n1 = n0
			if s[0] == '-':
				n1 = 1 + count(flip(s))
			#print('n0 = %d, n1 = %d' % (n0, n1))
			cache[s] = min(n0, n1)
		else:
			cache[s] = count(s[:idx+1])
	return cache[s]

t = int(input())
cache = {}
for icase in range(1, t+1):
	s = input().strip()
	n = count(s)
	print('Case #%d: %d' % (icase, n))
