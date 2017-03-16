t = input()
for j in xrange(int(t)):
	s = raw_input()
	zero = s.count('Z')
	two = s.count('W')
	four = s.count('U')
	six = s.count('X')
	eight = s.count('G')
	seven = s.count('S')-six
	five = s.count('F')-four
	one = s.count('O')-zero-two-four
	three = s.count('R')-four-zero
	nine = s.count('I')-six-eight-five
	ans = ''
	for i in xrange(zero):
		ans += '0'
	for i in xrange(one):
		ans += '1'
	for i in xrange(two):
		ans += '2'
	for i in xrange(three):
		ans += '3'
	for i in xrange(four):
		ans += '4'
	for i in xrange(five):
		ans += '5'
	for i in xrange(six):
		ans += '6'
	for i in xrange(seven):
		ans += '7'
	for i in xrange(eight):
		ans += '8'
	for i in xrange(nine):
		ans += '9'
	print 'Case #{}: {}'.format(j+1, ans)