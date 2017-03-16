T = int(raw_input())

for t in range(1,T+1):
	print 'Case #%d:'%t,

	n,m = raw_input().split()
	n = int(n)
	m = int(m)
	
	if m > 2**(n-2):
		print 'IMPOSSIBLE'
		continue
	print 'POSSIBLE'

	code = '1'
	m -= 1

	for i in range(n-1):
		if m % 2:
			code = '1'+code
		else:
			code = '0'+code
		m /= 2
	print code

	for i in range(n-1):
		print '0'* (i+2) +'1'*(n-i-2)
