for _ in range(1, int(input()) + 1):
	print('Case #%d:' % _, end = ' ')
	a, b, c = map(int, input().split())
	if b * c < a:
		print('IMPOSSIBLE')
		continue
	for i in range(c):
		t = 0
		for j in range(b):
			t = t * a + (i * b + j) % a
		print(i + 1, end = ' ')
	print()