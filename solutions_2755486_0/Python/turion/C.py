#! /usr/bin/python
# -*- coding: utf-8 -*-

import codejammer # https://bitbucket.org/turion/codejammer
#codejammer.set_level(codejammer.DEBUG)

import collections


def solve(case):
	wall = collections.defaultdict(lambda:0)
	successes = 0
	attacks = []
	for tribe in case[1:]:
		d, n, w, e, s, dd, dp, ds = map(int, tribe)
		for i in range(n):
			attacks.append((d, s, w, e))
			d += dd
			w += dp
			e += dp
			s += ds
	#attacks = sorted(attacks, key=lambda attack: attack[0])
	kattacks = collections.defaultdict(lambda: list())
	for attack in attacks:
		kattacks[attack[0]].append(attack)
	for day in sorted(kattacks.keys()):
		codejammer.debug(("today:", day, kattacks[day]))
		for attack in kattacks[day]:
			d, s, w, e = attack
			segment = range(w, e)
			codejammer.debug(("trying", [wall[i] for i in segment], s))
			if any([wall[i] < s for i in segment]):
				codejammer.debug("yes")
				successes += 1
		for attack in kattacks[day]:
			d, s, w, e = attack
			segment = range(w, e)
			for i in segment:
				wall[i] = max(s, wall[i])
	return successes

test_in = """2
2
0 3 0 2 10 2 3 -2
10 3 2 3 8 7 2 0
3
1 1 0 5 10 2 8 0
0 3 0 1 7 1 2 2
3 3 0 5 1 1 4 0"""

test_solution = """Case #1: 5
Case #2: 6"""

codejammer.test_jam(test_in, test_solution, solve, handler="numbered")
codejammer.jam("C", solve, handler="numbered")
