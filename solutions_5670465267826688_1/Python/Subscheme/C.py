getl = lambda: raw_input().split()
get = lambda: map(int, getl())

SYMBOLS = 'oijkOIJK'

TABLE = dict((l[0], dict(zip(SYMBOLS, l[1:]))) for l in (l.split() for l in '''
o  o i j k  O I J K
O  O I J K  o i j k

i  i O k J  I o K j
I  I o K j  i O k J

j  j K O i  J k o I
J  J k o I  j K O i

k  k j I O  K J i o
K  K J i o  k j I O
'''.splitlines() if l.strip()))

T, = get()

def mul(x,y):
	#print x, '*', y, '=', TABLE[x][y]
	return TABLE[x][y]

def test(S):
	c = 'o'
	ind = 0
	while ind < len(S) and c != 'i':
		c = mul(c, S[ind])
		ind += 1
	if c != 'i':
		return False
	
	c = 'o'
	while ind < len(S) and c != 'j':
		c = mul(c, S[ind])
		ind += 1
	if c != 'j':
		return False
	
	c = 'o'
	while ind < len(S):
		c = mul(c, S[ind])
		ind += 1
	if c != 'k':
		return False

	return True

for testCase in range(1, T+1):
	L, X = get()
	if X > 20:
		X = 20 + X % 4
	S, = getl()
	S *= X
	print "Case #%d: %s" % (testCase, "YES" if test(S) else "NO")





