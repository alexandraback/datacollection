T = int(raw_input())

def qmul(a, b, sign):
	if a == '1':
		return (b, sign)
	if b == '1':
		return (a, sign)
	if a == 'i':
		if b == 'i':
			return ('1', 1-sign)
		elif b == 'j':
			return ('k', sign)
		elif b == 'k':
			return ('j', 1-sign)
	if a == 'j':
		if b == 'i':
			return ('k', 1-sign)
		elif b == 'j':
			return ('1', 1-sign)
		elif b == 'k':
			return ('i', sign)
	if a == 'k':
		if b == 'i':
			return ('j', sign)
		elif b == 'j':
			return ('i', 1-sign)
		elif b == 'k':
			return ('1', 1-sign)

def doprob():
#	D = int(raw_input())
	read = raw_input()
	read = [int(x) for x in read.split()]
	L = read[0]
	X = read[1]
	chars = raw_input()

	curr = '1'
	sgn = 0
	for i in xrange(L):
		curr, sgn = qmul(curr, chars[i], sgn)

	if curr == '1':
		if sgn == 0 or X%2 == 0:
			return "NO"
	else:
		if X%4 != 2:
			return "NO"

	curr = '1'
	sgn = 0
	loc = 0
	wrap = 0
	while (curr != 'i' or sgn != 0) and wrap < 4 and wrap < X:
		curr, sgn = qmul(curr, chars[loc], sgn)
		loc += 1
		if loc == L:
			loc = 0
			wrap += 1
	if (curr, sgn) != ('i', 0):
		return "NO"
	offset = L*wrap + loc
	wnought = wrap
	curr = '1'
	sgn = 0
	loc = 0
	wrap = 0
	while (curr != 'j' or sgn != 0) and wrap < 4 and (offset + loc*wrap) < X*L:
		curr, sgn = qmul(curr, chars[(offset + loc)%L], sgn)
		loc += 1
		if loc == L:
			loc = 0
			wrap += 1
	if (curr, sgn) != ('j', 0):
		return "NO"
	return "YES"

for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())