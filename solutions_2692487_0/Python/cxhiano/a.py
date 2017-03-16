fin = open('a.in', 'r')
fout = open('a.out', 'w')

T = eval(fin.readline())

def read():
	return fin.readline().split(' ')

def nread():
 return map(eval, read())

for t in range(T):
	A, n = nread()
	S = nread()
	S.sort()
	f = []
	for i in range(n + 1):
		f.append([0] * (n + 1))
	f[0][0] = A
	for i in range(0, n):
		for j in range(n + 1):
			if f[i][j] > 0:
				if f[i][j] > S[i]:
					f[i + 1][j] = max(f[i + 1][j], f[i][j] + S[i])
				if j < n:
					f[i][j + 1] = max(f[i][j + 1], f[i][j] * 2 - 1)
					f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j])
	print f
	ans = 0 
	for i in range(n + 1):
		if f[n][i] > 0:
			ans = i
			break
	fout.write("Case #%d: %d\n" % (t + 1, ans))
