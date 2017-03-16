import sys
import collections

T = int(raw_input())

for t in range(1, T+1):
	N = int(raw_input())

	hs = []
	hs_fl = []
	for i in range(2 * N - 1):
		h = map(int, raw_input().split())
		hs.append(h)
		hs_fl += h

	#print hs, hs_fl

	cnt = collections.Counter(hs_fl)
	odd = [ k for k,v in cnt.items() if v%2 != 0 ]
	#print odd
	odd_str = ' '.join(map(str, sorted(odd)))

	'''
	hs = sorted(hs)
	#print hs

	sq = []
	# init sq
	for i in range(N):
		sq.append([-1] * N)
	print sq

	r, c = 0,0
	for i in range(len(hs)):
		h = hs[i]
		if i == 0:
			sq[0] = h
			r = 1
		if sq[0][c] == h[0] and sq[0][c+1] == h[0]:
			for j in range(N):
				sq[i][c] = h[j]
			c += 1


		print sq
	'''


	print 'Case #%d: %s' % (t, odd_str)
