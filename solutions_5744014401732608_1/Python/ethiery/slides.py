def nbPaths(n):
	if n <= 2:
		return 1
	else:
		return 2**(n-2)

def diagSupMat(n, needed):
	first_line = ['0']
	for i in range(1, n):
		nb = nbPaths(n-i)
		if needed >= nb:
			first_line.append('1')
			needed -= nb
		else:
			first_line.append('0')

	lines = [''.join(first_line)]
	for i in range(1, n):
		lines.append(''.join((['0']*(i+1)) + (['1']*(n-i-1))))
	return '\n'.join(lines)

for T in range(1, int(input())+1):
	B, M = input().split()
	B, M = int(B), int(M)

	maxNbPaths = nbPaths(B)
	if M <= maxNbPaths:
		print('Case #{}: POSSIBLE\n{}'.format(T, diagSupMat(B, M)))
	else:
		print('Case #{}: IMPOSSIBLE'.format(T))

