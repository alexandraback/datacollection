#!/usr/bin/python3

t = int(input())
for icase in range(1, t+1):
	k, c, s = map(int, input().split())
	if k == 1:
		print('Case #%d: 1' % icase)
	elif c == 1:
		if s < k:
			print('Case #%d: IMPOSSIBLE' % icase)
		else:
			print(('Case #%d: ' % icase) + ' '.join(map(str, range(1, k+1))))
	else:
		if s < k-1:
			print('Case #%d: IMPOSSIBLE' % icase)
		else:
			print(('Case #%d: ' % icase) + ' '.join(map(str, range(2, k+1))))
