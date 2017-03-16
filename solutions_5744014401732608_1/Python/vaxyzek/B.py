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
	print(mx, M, pf)
	return pf == M
	

ifile, ofile = gcj.get_files('B')

T = int(ifile.readline().strip())
for t in range(T):
	B, M = map(int, ifile.readline().strip().split(' '))

	mx = [[0] * B for b in range(B)]

	for i in range(1, B):
		for j in range(i + 1, B):
			mx[i][j] = 1

	#print(str(1 << (B - 1)))

	if M > (1 << (B - 2)):
		ans = "IMPOSSIBLE"
	else:
		#print(B)
		i = 0 
		while M > 0:
			#print(B)
			if M % 2 == 1:
				mx[0][B - 1 - i] = 1

			M >>= 1
			i += 1

	#	print(check(mx, M))
		ans = "POSSIBLE"
		for i in range(B):
			ans += "\n" + ''.join(list(map(str, mx[i])))

	gcj.print_answer(ofile, t, ans)