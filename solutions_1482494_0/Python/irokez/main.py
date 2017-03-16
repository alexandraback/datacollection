import sys

T = int(sys.stdin.readline().strip())

for t in range(T):
	N = int(sys.stdin.readline().strip())
	level1 = {}
	level2 = {}
	for n in range(N):
		a, b = map(int, sys.stdin.readline().strip().split(' '))
		level1[n] = a
		level2[n] = b
	
	stars = 0
	i = 0
	while level2:
		i += 1
		level = None
		#print(i, stars, level1, level2)
		for n, l in level2.items():
			if stars >= l:
				level = n
				break
		if level is not None:
			del level2[level]
			if level in level1:
				stars += 2
				del level1[level]
			else:
				stars += 1
		else:
			for n, l in level1.items():
				if stars >= l:
					level = n
					break
			if level is not None:
				stars += 1
				del level1[level]
			else:
				break
#		print(i, stars, level)
	
	print('Case #{0}: {1}'.format(t + 1, i if not level2 else 'Too Bad'))
