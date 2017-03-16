t = input()
for cs in xrange(1, t+1):
	k, c, s = map(int, raw_input().split())
	if c * s < k:
		ans = 'IMPOSSIBLE'
	else:
		ans = []
		for i in xrange(0, k+(c-k%c)%c, c):
			tmp = 0
			for j in xrange(i, i+c):
				tmp = tmp * k + j % k
			ans.append(str(tmp + 1))
		ans = ' '.join(ans)
	print 'Case #%d: ' % cs + ans
