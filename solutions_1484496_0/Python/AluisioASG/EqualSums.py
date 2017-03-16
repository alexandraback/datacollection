# -*- coding: utf-8 -*-
# Google Code Jam 2012 - Round 1B - Equal Sums
# http://code.google.com/codejam/contest/1836496/dashboard#s=p2
# Copyright © 2012 Aluísio Augusto Silva Gonçalves
# This module is free software, licensed under the terms of the Artistic License 2.0


# Imports {{{1
##############

import itertools

import CodeJam


# Functions {{{1
################

def findEquals (subsets):
	sums = [sum(ss) for ss in subsets]
	for i1, s in enumerate(sums):
		try:
			return (i1, sums.index(s, i1 + 1))
		except ValueError:
			continue
	return None


def join (iterable):
	return ' '.join(str(e) for e in iterable)


# Entry point {{{1
##################

@CodeJam.ProblemSolver(__name__, lines=1)
def solve (input):
	input = [int(n) for n in input[0].split()]
	n, inset = input[0], input[1:]
	subsets = [ss for l in range(1, n) for ss in itertools.combinations(inset, l)]
	r = findEquals(subsets)
	if r is not None:
		return '\n%s\n%s' % (join(subsets[r[0]]), join(subsets[r[1]]))
	return '\nImpossible'
