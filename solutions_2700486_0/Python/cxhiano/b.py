fin = open('a.in', 'r')
fout = open('a.out', 'w')

T = eval(fin.readline())

def read():
	return fin.readline().split(' ')

def nread():
	return map(eval, read())

def f(n):
	ret = 1
	for i in range(1, n + 1):
		ret *= i
	return ret

for t in range(T):
	fout.write('Case #%d: ' % (t + 1))
	N, X, Y = nread()
	
	n = 1
	for i in range(1, 10000):
		if i * (i + 1) / 2 > N:
			n = i - 1
			break
	if n % 2 == 0: 
		n = n - 1

	N -= n * (n + 1) / 2

	if abs(X) + abs(Y) < n:
		fout.write('1.0\n')
		continue
	
	if abs(X) + abs(Y) > n + 2 or N == 0:
		fout.write('0.0\n')
		continue

	ans = 0
	
	tot = 0
	for i in range(0, n + 2):
		if i <= N and N - i < n + 2:
			tot += f(N) / f(N - i) / f(i)
	for i in range(Y + 1, n + 2):
		if i <= N and N - i < n + 2:
			ans += f(N) / f(N - i) / f(i)

	fout.write('%.6lf\n' % ((ans + 0.00000001) / tot))
