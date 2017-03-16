f = open("B-large.in", "r")
g = open("answer.txt", "w")

N = int(f.readline().split()[0])

for mm in range(N):
	g.write("Case #{}: ".format(mm+1))
	lawn = []
	bad = []
	n, m = map(int, f.readline().split())
	for i in range(n):
		lawn.append([x for x in map(int, f.readline().split())])
		bad.append([False for x in range(m)])
	for i, row in enumerate(lawn):
		k = max(row)
		for j, cc in enumerate(row):
			if cc!=k:
				bad[i][j] = True
	tlawn = [[row[i] for row in lawn] for i in range(m)]
	for i, row in enumerate(tlawn):
		k = max(row)
		for j, cc in enumerate(row):
			if (cc!=k) and bad[j][i]:
				break
		else:
			continue
		break
	else:
		g.write("YES\n")
		continue
	g.write("NO\n")
f.close()
g.close()
