import itertools

def solve(N, Z, F):
	ans = "99999"*N
	for P in itertools.permutations(range(N)):
		ok = True
		S = [P[0]]
		for p in P[1:]:
			while len(S)>0:
				if F[S[-1]][p]:
					S.append(p)
					break
				S.pop()
			else:
				ok = False
				break
		if ok:
			ans = min(ans, "".join(Z[p] for p in P))
	
	return ans

for t in range(input()):
	N, M = map(int, raw_input().split())
	Z = [raw_input() for _ in range(N)]
	F = [[False]*N for _ in range(N)]
	for _ in range(M):
		a, b = map(lambda x: int(x)-1, raw_input().split())
		F[a][b] = F[b][a] = True
	print "Case #%s: %s" % (t+1, solve(N,Z,F))
