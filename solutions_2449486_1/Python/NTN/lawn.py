def check(case_no):
	N, M = (int(i) for i in input().split())
	rows = [[int(j) for j in input().split()] for i in range(N)]
	columns = zip(*rows)

	lawn = [[100]*M for i in range(N)]

	for i, row in enumerate(rows):
		height = max(row)
		for j in range(M):
			lawn[i][j] = min(lawn[i][j], height)

	for i, col in enumerate(columns):
		height = max(col)
		for j in range(N):
			lawn[j][i] = min(lawn[j][i], height)

	if lawn == rows:
		print('Case #%i: YES' % case_no)
	else:
		print('Case #%i: NO' % case_no)

for i in range(1, int(input()) + 1):
	check(i)