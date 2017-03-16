def solve(n):
	if n == 0:
		print('INSOMNIA')
		return
	seen = set()
	i = 1
	while i<1000:
		seen = seen.union(set(list(str(i*n))))
		if len(seen) == 10:
			break
		i += 1
	print(i*n)

if __name__ == '__main__':
	tc = int(input())
	for t in range(1, tc+1):
		n = int(input())
		print('Case #%i: ' % t, end='')
		solve(n)
