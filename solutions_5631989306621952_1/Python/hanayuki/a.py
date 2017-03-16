import sys

T = int(raw_input())

for t in range(1, T+1):
	S = raw_input()

	lw = ''
	for c in S:
		if lw == '':
			lw = c
		else:
			if lw[0] > c:
				lw = lw + c
			else:
				lw = c + lw


	print 'Case #%d: %s' % (t, lw)
