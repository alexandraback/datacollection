from sys import stdin

for case in range(int(stdin.readline())):
	a, b, k = [int(x) for x in stdin.readline().split()]
	count = 0
	for i in range(a):
		for j in range(b):
			if (i & j) < k:
				count += 1
	ans = count
	print('Case #{}: {}'.format(case + 1, ans), end='\n')