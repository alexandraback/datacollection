#!/usr/bin/env python2

import operator

from multiprocessing import Pool

def keep_typing_calc(typed, total, probs):

	prob_correct = reduce(operator.mul, probs[:typed])
	continue_typing = prob_correct * (total - typed + 1) + (1 - prob_correct) * (total - typed + 1 + total + 1)

	return continue_typing

def solve(args):
	typed, total = args[:2]
	probs = args[2]

	min_keys = enter_right_away = total + 2

	for backspaces in range(typed):
		min_keys = min(min_keys, keep_typing_calc(typed - backspaces, total, probs) + backspaces)

	return min_keys

with open('in.txt') as fin:
	with open('out.txt', 'w') as fout:
		T = int(fin.readline().strip())

		cases = []
		for case in xrange(T):
			cases.append([int(i) for i in fin.readline().strip().split()])
			cases[-1].append([float(i) for i in fin.readline().strip().split()])

		pool = Pool(processes=6)
		results = pool.map(solve, cases)

		for case, result in enumerate(results):
			print >>fout, 'Case #%d: %s' % (case+1, result)
