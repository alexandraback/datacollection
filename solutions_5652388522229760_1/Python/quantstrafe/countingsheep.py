import sys

cases = sys.stdin.readlines()
cases = map(int, map(str.strip, cases))

for i in range(1, cases[0]+1):
	digits = set(range(10))
	number = cases[i]
	for n in range(1, 1000):
		digits = digits - set(map(int, `number * n`))
		if not digits:
			print 'Case #{}: {}'.format(i, number * n)
			break
	else:
		print 'Case #{}: INSOMNIA'.format(i)