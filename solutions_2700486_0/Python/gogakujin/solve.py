# coding: utf-8

import os, sys, re, string
import math,random


def solve(N, X, Y):
	cache = {}
	count = [0]
	def f(pile, n):
		if n >= N:
			count[0] += 1
			for k in pile.keys():
				if cache.has_key(k):
					cache[k] += 1
				else:
					cache[k] = 1
			return
		key = (0, 2)
		while pile.has_key(key):
			key = (0, key[1] + 2)
		lk = (key[0] - 1, key[1] - 1)
		if not pile.has_key(lk):
			while not pile.has_key(lk) and lk[1] > 0:
				lk = (lk[0] - 1, lk[1] - 1)
			if pile.has_key(lk):
				lk = (lk[0] + 1, lk[1] + 1)
			pile[lk] = 1
			f(pile, n + 1)
			del pile[lk]
		rk = (key[0] + 1, key[1] - 1)
		if not pile.has_key(rk):
			while not pile.has_key(rk) and rk[1] > 0:
				rk = (rk[0] + 1, rk[1] - 1)
			if pile.has_key(rk):
				rk = (rk[0] - 1, rk[1] + 1)
			pile[rk] = 1
			f(pile, n + 1)
			del pile[rk]
		if pile.has_key(lk) and pile.has_key(rk):
			pile[key] = 1
			f(pile, n + 1)
			del pile[key]
	f({(0, 0): 1}, 1)
	if cache.has_key((X, Y)):
		return cache[(X, Y)] / float(count[0])
	return 0

def main():
	T = int(sys.stdin.readline())
	for i in xrange(1, T + 1):
		n,x,y = map(int, sys.stdin.readline().split())
		print "Case #%d: %1.7f" % (i, solve(n, x, y))

if __name__ == '__main__':
	main()


