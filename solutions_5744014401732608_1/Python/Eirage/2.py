T = int(raw_input())  
#n, m = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case

for k in xrange (T):
	n, m= [int(s) for s in raw_input().split(" ")]
	maxm = 2 ** (n - 2)
	if m > maxm:
		print "Case #{}: {}".format(k+1, 'IMPOSSIBLE')
	else:
		print "Case #{}: {}".format(k+1, 'POSSIBLE')
		a = ['0'] * n
		g = maxm / 2
		i = n - 2
		while g >= 1:
			if m > g:
				m = m - g
				a[i] = '1'
			g = g / 2
			i -= 1
		if m == 1:
			a[0] = '1'

		for i in xrange(n-1):
			ans = '0' * (i+1) + '1' * (n-i-1 - 1) + a[i]
			print(ans)
		print('0' * n)