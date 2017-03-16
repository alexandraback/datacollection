for T in range(1, int(input())+1):
	J, P, S, K = input().split()
	J, P, S, K = int(J), int(P), int(S), int(K)

	JP = [[0 for p in range(P)] for j in range(J)]
	JS = [[0 for s in range(S)] for j in range(J)]
	PS = [[0 for s in range(S)] for p in range(P)]
	res = []
	for j in range(J):
		for p in range(P):
			for s in range(S):
				if JP[j][p] < K and JS[j][s] < K and PS[p][s] < K:
					JP[j][p] += 1
					JS[j][s] += 1
					PS[p][s] += 1
					res.append('{} {} {}'.format(j+1, p+1, s+1))

	print('Case #{}: {}\n{}'.format(T, len(res), '\n'.join(res)))

