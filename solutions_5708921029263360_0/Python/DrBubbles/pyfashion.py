import sys

T = int(sys.stdin.readline())
for C in range(T):
	print("Case #" + str(C+1) + ": ", end="")

	J, P, S, K = [int(x) for x in sys.stdin.readline().split()]

	freq = [[[0 for _ in range(S+1)] for _ in range(P+1)] for _ in range(J+1)]

	ops = set()
	for j in range(J):
		for p in range(P):
			if freq[j][p][-1] >= K:
				continue
			for a in range(S):
				s = (a + j + p) % S
				if freq[j][-1][s] < K and freq[-1][p][s] < K:
					freq[j][p][-1] += 1
					freq[j][-1][s] += 1
					freq[-1][p][s] += 1
					ops.add((j+1, p+1, s+1))
					if freq[j][p][-1] >= K:
						break
	print(len(ops))
	for o in ops:
		print(*o)
	
