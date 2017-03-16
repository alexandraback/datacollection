# coding: utf-8

import os, sys, re, string
import math,random

def calculate(E, R, v):
	N = len(v)
	cache = {}
	def f(e, gain, index):
		if index >= N:
			return gain
		e, res = min(E, e + R), gain
		key = (e, index)
		if cache.has_key(key):
			return cache[key] + gain
		for i in xrange(e, -1, -1):
			res = max(res, f(e - i, gain + i * v[index], index + 1))
		cache[key] = res - gain
		return res
	return f(E, 0, 0)

def main():
	for i in xrange(1, int(sys.stdin.readline()) + 1):
		E, R, N = map(int, sys.stdin.readline().split(' '))
		v = map(int, sys.stdin.readline().split(' '))
		print "Case #%d: %d" % (i, calculate(E, R, v))

if __name__ == '__main__':
	main()


