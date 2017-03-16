for _ in range(input()):
	n, m = map(int, raw_input().split())
	a = [map(int, raw_input().split()) for i in range(n)]
	r = [max(x) for x in a]
	c = [max(x) for x in zip(*a)]
	print ('Case #%d: ' % (_ + 1)) + ['NO', 'YES'][all(a[i][j] == min(r[i], c[j]) for i in range(n) for j in range(m))]
