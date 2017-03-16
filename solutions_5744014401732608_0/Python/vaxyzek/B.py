import gcj

def paths_from(mx, i):
	pf = 0
	B = len(mx)

	if i == B - 1:
		return 0

	for j in range(i + 1, B):
		if j == B - 1 and mx[i][j]:
			pf += 1
		elif mx[i][j]:
			pf += paths_from(mx, j)


	#print("pf " + str(i) + " = " + str(pf))
	return pf


def check(mx, M):
	pf = paths_from(mx, 0)
	#rint(mx, M, pf)
	return pf == M
	

ifile, ofile = gcj.get_files('B')

T = int(ifile.readline().strip())
for t in range(T):
	B, M = map(int, ifile.readline().strip().split(' '))

	paths = []
	for i in range(0, B - 1):
		for  j in range(i + 1, B):
			paths.append([i,j])

	L = len(paths)
	ans = "IMPOSSIBLE"
	for X in range(1 << L):
		mx = [[0] * B for b in range(B)]
		for l in range(L):
			if (X >> l) & 1:
				mx[paths[l][0]][paths[l][1]] = 1

			#print("---")
			if check(mx, M):
				ans = "POSSIBLE"
				for i in range(B):
					ans += "\n" + ''.join(list(map(str, mx[i])))
				break

	gcj.print_answer(ofile, t, ans)