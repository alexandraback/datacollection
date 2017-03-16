

for _ in range(1, int(input()) + 1):
	print('Case #%d:' % _, end = ' ')
	n = int(input())
	if not n:
		print('INSOMNIA')
		continue
	s = set()
	i = 0
	while len(s) < 10:
		i += n
		s |= set(str(i))
	print(i)