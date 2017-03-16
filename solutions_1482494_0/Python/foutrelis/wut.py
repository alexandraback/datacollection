#!/usr/bin/env python2

from multiprocessing import Pool
from operator import itemgetter
from collections import defaultdict

def solve(levels):

	one_star = sorted([(level, levels[level][0], levels[level][1]) for level in levels], key=itemgetter(1))
	two_star = sorted([(level, levels[level][1]) for level in levels], key=itemgetter(1))

	stars = 0
	played = 0

	completed_one = defaultdict(lambda: False)
	completed_two = defaultdict(lambda: False)

	while two_star:
		if two_star[0][1] <= stars:
			sel = 0
			while True:
				if sel + 1 == len(two_star):
					sel = 0
					break
				elif completed_one[two_star[sel][0]] and two_star[sel+1][1] <= stars:
					sel += 1
				else:
					sel = 0
					break
			stars += completed_one[two_star[sel][0]] and 1 or 2
			played += 1
			completed_two[two_star[sel][0]] = True
			del two_star[sel]
		elif one_star and one_star[0][1] <= stars:
			if completed_two[one_star[0][0]]:
				del one_star[0]
				continue

			possible = [one_star_sel for one_star_sel in one_star if one_star_sel[1] <= stars]
			possible.sort(key=itemgetter(2), reverse=True)

			for one_star_sel in possible:
				if not completed_two[one_star_sel[0]]:
					sel = one_star.index(one_star_sel)
					break
			else:
				sel = 0

			stars += 1
			played += 1
			completed_one[one_star[sel][0]] = True
			del one_star[sel]
		else:
			return 'Too Bad'

	return played

with open('in.txt') as fin:
	with open('out.txt', 'w') as fout:
		T = int(fin.readline().strip())

		cases = []
		for case in xrange(T):
			levels = int(fin.readline().strip())

			req = {}
			for level in xrange(levels):
				one, two = [int(i) for i in fin.readline().strip().split()]
				req[level] = (one, two)

			cases.append(req)

#		for case in cases:
#			print solve(case)

		pool = Pool(processes=6)
		results = pool.map(solve, cases)

		for case, result in enumerate(results):
			print >>fout, 'Case #%d: %s' % (case+1, result)
