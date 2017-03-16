import sys
cases = sys.stdin.readlines()

for i in range(1, int(cases[0].strip()) + 1):
	prev = '+'
	count = 0
	for c in reversed(cases[i].strip()):
		if c != prev:
			prev = c
			count += 1
	print 'Case #{}: {}'.format(i, count)