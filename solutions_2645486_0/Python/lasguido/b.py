#!/usr/bin/python
import sys
from math import log

e, r, n = 0, 0, 0
v = []

def calc(energy, idx, score):
	if energy > e: energy = e
	if (idx == n): return score
	maks = energy+1 if energy > r else r+1
	acc = []
	for i in range(r, maks):
		acc.append(calc(energy-i+r, idx+1, score+i*v[idx]))
	return max(acc)

t = int(sys.stdin.readline())
for ctr in range(1, t+1):
	e, r, n = [int(x) for x in sys.stdin.readline().split()]
	v = [int(x) for x in sys.stdin.readline().split()]

	print "Case #{0}: {1}".format(ctr, calc(e, 0, 0))