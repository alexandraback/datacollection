
def solve(n):
	if n == 0:
		return 'INSOMNIA'
	seen = [False] * 10
	a = n
	while True:
		for d in str(a):
			seen[int(d)] = True
		if not False in seen:
			return a
		a += n
	return 'INSOMNIA'

t = int(input().strip())
for c in range(t):
	print('Case #{}: {}'.format(c + 1, solve(int(input().strip()))))
