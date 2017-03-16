trans = {'q':'z', 'z':'q', ' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm'}

t = int(raw_input())
def tran(s):
	return ''.join(trans[c] for c in s)

for i in xrange(t):
	line = raw_input()
	print 'Case #%d: %s' % (i+1, tran(line))
