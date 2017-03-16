#!/usr/bin/env python
import sys
import random

from collections import defaultdict
from itertools import combinations_with_replacement, chain, combinations

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def random_powerset(iterable, num):
	s = list(iterable)
	for i in xrange(num):
		l = []
		for x in s:
			if random.random() >= 0.5:
				l.append(x)

		yield l


def build_products(N, M):
	counts = defaultdict(int)
	possible = defaultdict(set)
	total = 0

	for seq in combinations_with_replacement(xrange(2, M + 1), N):
		#for s in powerset(seq):
		for s in random_powerset(seq, 500):
			prod = reduce(lambda x, y: x * y, s, 1)
			possible[prod].add(seq)
			counts[prod] += 1
			total += 1

	return (counts, possible, total)

if __name__ == '__main__':
	T = int(sys.stdin.readline().strip())
	for CASE in xrange(1, T + 1):
		R, N, M, K = map(int, sys.stdin.readline().strip().split())
		counts, possible, total = build_products(N, M)

		print "Case #{}:".format(CASE)
		for i in xrange(R):
			product  = map(int, sys.stdin.readline().strip().split())
			could_be = None

			for p in product:
				if could_be is None:
					could_be = possible[p]
				else:
					could_be = could_be & possible[p]

			if len(could_be) > 0:
				result = iter(could_be).next()
				s = ""
				for x in result:
					s += str(x)
				print s
			else:
				print "2" * N
