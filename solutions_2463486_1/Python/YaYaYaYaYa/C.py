dec = ['1', '2', '3']
for i in xrange(49):
	dec.append('1' + '0' * i + '1')
	dec.append('2' + '0' * i + '2')
for i in xrange(24):
	dec.append('1' + '0' * i + '1' + '0' * i + '1')
	dec.append('1' + '0' * i + '2' + '0' * i + '1')
	dec.append('2' + '0' * i + '1' + '0' * i + '2')
for i in xrange(24):
	for mid in xrange(47 - 2 * i):
		dec.append('1' + '0' * i + '1' + '0' * mid + '1' + '0' * i + '1')
for i1 in xrange(23):
	for i2 in xrange(23 - i1):
		dec.append('1' + '0' * i1 + '1' + '0' * i2 + '1' + '0' * i2 + '1' + '0' * i1 + '1')
		dec.append('1' + '0' * i1 + '1' + '0' * i2 + '2' + '0' * i2 + '1' + '0' * i1 + '1')
for i1 in xrange(23):
	for i2 in xrange(23 - i1):
		for mid in xrange(45 - i1 * 2 - i2 * 2):
			dec.append('1' + '0' * i1 + '1' + '0' * i2 + '1' + '0' * mid + '1' + '0' * i2 + '1' + '0' * i1 + '1')
for i1 in xrange(22):
	for i2 in xrange(22 - i1):
		for i3 in xrange(22 - i1 - i2):
			dec.append('1' + '0' * i1 + '1' + '0' * i2 + '1' + '0' * i3 + '1' + '0' * i3 + '1' + '0' * i2 + '1' + '0' * i1 + '1')
for i1 in xrange(22):
	for i2 in xrange(22 - i1):
		for i3 in xrange(22 - i1 - i2):
			for mid in xrange(43 - i1 * 2 - i2 * 2 - i3 * 2):
				dec.append('1' + '0' * i1 + '1' + '0' * i2 + '1' + '0' * i3 + '1' + '0' * mid + '1' + '0' * i3 + '1' + '0' * i2 + '1' + '0' * i1 + '1')
for i1 in xrange(21):
	for i2 in xrange(21 - i1):
		for i3 in xrange(21 - i1 - i2):
			for i4 in xrange(21 - i1 - i2 - i3):
				dec.append('1' + '0' * i1 + '1' + '0' * i2 + '1' + '0' * i3 + '1' + '0' * i4 + '1' + '0' * i4 + '1' + '0' * i3 + '1' + '0' * i2 + '1' + '0' * i1 + '1')

num = [int(i) * int(i) for i in dec]
num.sort()
num.append(100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)

T = int(raw_input())
for case in xrange(T):
	A, B = (int(i) for i in raw_input().split())
	indexa = 0
	while num[indexa] < A:
		indexa += 1
	indexb = indexa
	while num[indexb] <= B:
		indexb += 1
	print "Case #%d: %d" % (case + 1, indexb - indexa)
