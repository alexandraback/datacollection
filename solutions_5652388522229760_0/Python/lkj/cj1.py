def solve(n):
	if n == 0:
		print('INSOMNIA')
		return
	seen = set()
	i = 1
	while i<1000:
		seen = seen.union(set(list(str(i*n))))
		#print(i, i*n, seen)
		if len(seen) == 10:
			break
		i += 1
	#print('DEBUGINFO: i=', i)
	print(i*n)
	#print('DBG', i)
	#if i > 45:
	#	print(n, i)
	#assert(i <= 45)

if __name__ == '__main__':
	tc = int(input())
	for t in range(1, tc+1):
		n = int(input())
		print('Case #%i: ' % t, end='')
		solve(n)
