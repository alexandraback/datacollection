import sys
L = { ' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z':'q', 'q':'z'}
v = raw_input()
v = int(v)
for i in xrange(v):
	s = raw_input()
	print 'Case #%d: '%(i+1),	
	for c in s:
		sys.stdout.write(L[c])
	print
