import sys
sys.stdin = open( "in", "r" )
sys.stdout = open( "out", "w" )

for t in xrange(input()):
	print "Case #"+str(t+1)+":",

	a = [0]*26
	for x in raw_input() :
		a[ ord(x)-65 ] += 1

	ans = ''

	if a[6] :
		v = a[6]
		ans += '8'*v
		for x in [4,8,6,7,19] :
			a[x] -= v

	if a[20] :
		v = a[20]
		ans += '4'*v
		for x in [5,14,20,17]:
			a[x] -= v

	if a[22] :
		v = a[22]
		ans += '2'*v
		for x in [19,22,14]:
			a[x] -= v

	if a[23] :
		v = a[23]
		ans += '6'*v
		for x in [18,8,23]:
			a[x] -= v

	if a[25] :
		v = a[25]
		ans += '0'*v
		for x in [25,4,17,14]:
			a[x] -= v

	if a[5] :
		v = a[5]
		ans += '5'*v
		for x in [5,8,21,4]:
			a[x] -= v

	if a[7] :
		v = a[7]
		ans += '3'*v
		for x in [19,7,17,4]:
			a[x] -= v

	if a[8] :
		v = a[8]
		ans += '9'*v
		for x in [13,8,4]:
			a[x] -= v

	if a[18] :
		v = a[18]
		ans += '7'*v
		for x in [18,4,21,13]:
			a[x] -= v

	if a[14] :
		v = a[14]
		ans += '1'*v
		for x in [14,13,4]:
			a[x] -= v

	print ''.join(sorted(ans))