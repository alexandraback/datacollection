#!/usr/bin/python

from collections import defaultdict

import sys
import math

def equal(a,b):
	return math.rabs(a-b) <= 0.000001

def solve(S):
	ch = defaultdict(int)
	for c in S:
		ch[c] += 1

	count = [0] * 10
	while ch['Z'] > 0:
		ch['Z'] -= 1
		ch['E'] -= 1
		ch['R'] -= 1
		ch['O'] -= 1
		count[0] += 1

	while ch['W'] > 0:
		ch['T'] -= 1
		ch['W'] -= 1
		ch['O'] -= 1
		count[2] += 1

	while ch['U'] > 0:
		ch['F'] -= 1
		ch['O'] -= 1
		ch['U'] -= 1
		ch['R'] -= 1
		count[4] += 1

	while ch['X'] > 0:
		ch['S'] -= 1
		ch['I'] -= 1
		ch['X'] -= 1
		count[6] += 1

	while ch['G'] > 0:
		ch['E'] -= 1
		ch['I'] -= 1
		ch['G'] -= 1
		ch['H'] -= 1
		ch['T'] -= 1
		count[8] += 1

	while ch['O'] > 0:
		ch['O'] -= 1
		ch['N'] -= 1
		ch['E'] -= 1
		count[1] += 1

	while ch['H'] > 0:
		ch['T'] -= 1
		ch['H'] -= 1
		ch['R'] -= 1
		ch['E'] -= 1
		ch['E'] -= 1
		count[3] += 1

	while ch['F'] > 0:
		ch['F'] -= 1
		ch['I'] -= 1
		ch['V'] -= 1
		ch['E'] -= 1
		count[5] += 1

	while ch['S'] > 0:
		ch['S'] -= 1
		ch['E'] -= 1
		ch['V'] -= 1
		ch['E'] -= 1
		ch['N'] -= 1
		count[7] += 1

	while ch['N'] > 0:
		ch['N'] -= 1
		ch['I'] -= 1
		ch['N'] -= 1
		ch['E'] -= 1
		count[9] += 1

	ret = ''
	for i in range(10):
		for j in range(count[i]):
			ret += str(i)

	return ret

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		S = sys.stdin.readline().strip()
		print "Case #{}: {}".format(t+1, solve(S))
