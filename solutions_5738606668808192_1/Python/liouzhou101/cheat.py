
print "Case #1:"

n = 32
k = 500

for i in range(k):
	s = '1'
	x = i
	for j in range(n/2-2):
		s += chr(x%2+48)
		x /= 2
	s += '1'
	print s+s,
	for p in range(2,11):
		t = 0
		for c in s:
			t *= p
			if (c=='1'):
				t += 1
		print t,
	print
