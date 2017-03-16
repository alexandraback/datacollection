#!/usr/bin/python3

t = int(input())
for icase in range(1, t+1):
	n = int(input())
	if n == 0:
		print('Case #%d: INSOMNIA' % icase)
	else:
		l = len(str(n))
		up = 10**(l+1)
		ds = set()
		for nn in range(n, up*n, n):
			ds.update(c for c in str(nn))
			if len(ds) == 10:
				print('Case #%d: %d' % (icase, nn))
				break
		else:
			print('Case #%d: INSOMNIA' % icase)
