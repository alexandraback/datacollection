def check(case_no):
	N, M = (int(i) for i in input().split())
	rows = [[int(j) for j in input().split()] for i in range(N)]
	columns = zip(*rows)

	for i, row in enumerate(rows):
		if all(i == 1 for i in row):
			rows[i] = [0] * M

	for i, col in enumerate(columns):
		if all(i == 1 for i in col):
			for row in rows:
				row[i] = 0

	for r in rows:
		if 1 in r:
			print('Case #%i: NO' % case_no)
			break
	else:
		print('Case #%i: YES' % case_no)

for i in range(1, int(input()) + 1):
	check(i)