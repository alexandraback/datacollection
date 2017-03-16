data = open('a.txt', 'r').read().split('\n')
(T,) = map(int, data.pop(0).split(' '))

def solve(t):
	moves = 0
	costos = []
	costosTotales = []
	(A, N) = map(int, data.pop(0).split(' '))
	otherMotes = map(int, data.pop(0).split(' '))
	otherMotes.sort()

	if A == 1:
		return N

	for other in otherMotes:
		if other < A:
			costos.append(moves)
		else:
			while A <= other:
				A += A-1
				moves += 1
			costos.append(moves)
		A += other

	for i in range(N):
		costosTotales.append(costos[i] + (N - i -1))

	mini = min(costosTotales)
	if mini > N:
		return N
	else:
		return mini

for t in range(T):
   print 'Case #' + str(t+1) + ': ' + str(solve(t))