t = int(input())
for test in range(t):
	print('Case #%d: ' % (test + 1), end = '')
	a, b, c, k = map(int, input().split())
	cnt1 = [[0 for i in range(b)] for j in range(a)]
	cnt2 = [[0 for i in range(c)] for j in range(a)]
	cnt3 = [[0 for i in range(c)] for j in range(b)]
	cnt = [[[0 for z in range(c)] for y in range(b)] for x in range(a)]
	ans = []
	cur = 0
	while 1:
		found = False
		for x in range(a):
			for y in range(b):
				z = (x + y + cur) % c
				if cnt[x][y][z] < 1 and cnt1[x][y] < k and cnt2[x][z] < k and cnt3[y][z] < k:
					cnt[x][y][z] += 1
					cnt1[x][y] += 1
					cnt2[x][z] += 1
					cnt3[y][z] += 1
					ans.append((x, y, z))
					found = True
		if not found:
			break
		cur += 1
	print(len(ans))
	for i in ans:
		for j in i:
			print(j + 1, end = ' ')
		print()