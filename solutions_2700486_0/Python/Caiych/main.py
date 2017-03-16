from decimal import Decimal
f = open('in')
T = int(f.readline())
for cas,sent in enumerate(f.readlines()):
	n = int(sent.split(' ')[0])
	x = int(sent.split(' ')[1])
	y = int(sent.split(' ')[2])
	if x < 0:
		x = -x
	s = 1
	k = 2
	while s <= n:
		s += k
		k += 1
		s += k
		k += 1
	k -= 1
	s -= k
	k -= 1
	s -= k
	left = n - s
	k -= 1
	if (x+y) <= (k-1):
		print 'Case #%d: %f'%(cas+1,1.0)
		continue
	if (x+y) > (k+1):
		print 'Case #%d: %f'%(cas+1,0.0)
		continue
	s = 1
	i = 0
	k += 2
	ss = 0
	y += 1
	if y == k:
		print 'Case #%d: %f'%(cas+1,0.0)
		continue

	cnt = 0
	while i <= left:
		if left - i >= k or i >= k:
			cnt += 1
		i += 1

	i = 0
	while i <= left:
		if (i != 0) :
			s = s * (left-i+1)/i
		tmp = i
		if tmp >= k:
			tmp = k - 1
		if left - tmp >= k:
			tmp = left - k + 1
		if tmp >= y:
			ss += s
		i += 1
	ss = Decimal(0.5)**(left) * ss
	#print cnt
	print 'Case #%d: %f'%(cas+1,ss)


