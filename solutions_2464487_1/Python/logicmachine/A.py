T = int(raw_input())
for caseNum in range(1, T + 1):
	values = raw_input().split(' ');
	r = int(values[0])
	t = int(values[1])
	left = 0
	right = 0x100000000
	while(left < right):
		n = (left + right) / 2
		a = 2 * n * r + (n * (2 * n - 1))
		if(a > t):
			right = n
		else:
			left = n + 1;
	print "Case #%d: %d" % (caseNum, left - 1)

