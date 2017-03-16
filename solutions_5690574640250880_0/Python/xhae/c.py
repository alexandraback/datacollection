T = int(raw_input())
for case in range(1, T + 1):
	print "Case #" + str(case) + ":"

	r, c, m = map(int, raw_input().split())

	ans = []
	empty = r * c - m

	if empty == 1:
		ans = [['*' for j in range(0, c)] for i in range(0, r)]
		ans[0][0] = 'c'
	elif r == 1 or c == 1:
		ans = [['*' for j in range(0, c)] for i in range(0, r)]
		for i in range(0, r):
			for j in range(0, c):
				if empty > 0:
					ans[i][j] = '.'
					empty -= 1
		ans[0][0] = 'c'
	elif empty < 4:
		ans += ["Impossible"]
	else:
		for i in range(2, r + 1):
			for j in range(2, c + 1):
				if (i == 2 or j == 2) and empty % 2 == 1:
					continue

				if empty <= i * j:
					curEmpty = empty

					ans = [['*' for l in range(0, c)] for k in range(0, r)]

					isRow = isCol = False

					for k in range(0, j):
						if empty < 2:
							break

						isRow = True
						ans[0][k] = ans[1][k] = '.'
						empty -= 2
						
					for k in range(2, i):
						if empty < 2:
							break

						isCol = True
						ans[k][0] = ans[k][1] = '.'
						empty -= 2

					if isRow and isCol:
						for k in range(2, i):
							if empty <= 0:
								break
							for l in range(2, j):
								if empty <= 0:
									break

								ans[k][l] = '.'
								empty -= 1

					if empty == 0:
						ans[0][0] = 'c'
						break
					else:
						ans = []
						empty = curEmpty

			if len(ans) > 0:
				break

		if len(ans) == 0:
			ans += ["Impossible"]

	for i in range(0, len(ans)):
		print "".join(ans[i])
