import sys

T = int(sys.stdin.readline().strip())
for t in range(T):
	s = list(map(int, sys.stdin.readline().strip().split(' ')))
	N = s[0]
	S = s[1:]
	total = sum(S)

	X = []
	n = 0
	nT = 0
	zero = False
	for s in S:
		x = 2 / N - s / total
		if x > 0:
			n += 1
			nT += s
			X.append(x)
		else:
			zero = True
			X.append(0)
	
	while zero and n > 2:
		zero = False
		n = 0
		nT = 0
		for i in range(N):
			if X[i] > 0:
				n += 1
				nT += S[i]

		i = 0
		for s in S:
			x = (total + nT - s * n) / (n * total)
			if x > 0:
				X[i] = x
			else:
				if X[i] != 0:
					zero = True
				X[i] = 0
			i += 1
	
	'''
	print('total', total)
	A = [0]
	for i in range(1, N):
		A.append((S[i - 1] - S[i]) / total)
	print(A)
	
	x = (1 - sum(A[i] * (N - i) for i in range(N))) / N
	print('x', x)
	X = [x]
	abc = 0
	for i in range(1, N):
		abc += A[i]
		X.append(abc + x)
	'''
#	X[0] = abs(1 - sum(X[1:]))
	print('Case #{0}: {1}'.format(t + 1, ' '.join('{0:.6f}'.format(x * 100) for x in X)))
