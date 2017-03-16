#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
#from functools32 import lru_cache

def sgn(xi,yi):
	if xi[0] == "-" and yi[0] != "-":
		return "-1"
	elif xi[0] != "-" and yi[0] == "-":
		return "-1"
	return "1"

def cabs(x):
	if x[0] == "-": return "".join(x[1:])
	else: return x

lookup = [
	["1","i","j","k"],
	["i","-1","k","-j"],
	["j","-k","-1","i"],
	["k","j","-i","-1"]
]
idxs = ["1","i","j","k"]
def mult(x,y):
	xi = idxs.index(cabs(x))
	yi = idxs.index(cabs(y))
	xy = lookup[xi][yi]
	sxy = "-1" if xy[0] == "-" else "1"
	sign = sgn(sgn(x, y), sxy)
	if sign == "-1":
		return "-"+cabs(lookup[xi][yi])
	else: return cabs(lookup[xi][yi])

def collapse(s):
	if len(s) <= 1: return s
	else: return [reduce(lambda x,y: mult(x,y), s)]

if __name__ == "__main__":
	T = int(raw_input())
	for t in xrange(1,T+1):
		L, X = map(long, raw_input().split())

		orig = raw_input()
		orig_sz = list(orig)
		orig_sz_save = orig_sz

		letter, pos = "i", -1

		orig_set = [["1"]]
		tmp = orig_sz[0]
		orig_set.append([tmp])
		for i in xrange(1, len(orig_sz)):
			tmp = mult(tmp, orig_sz[i])
			orig_set.append([tmp])
		print>>sys.stderr, "(0):", orig_set
		ncycle = 1

		orig_set_save = orig_set

		if [letter] in orig_set:
			pos = orig_set.index([letter])
		else:
			pdt = orig_set[-1][0]
			found = False
			for i in xrange(1,5):
				# orig_set = map(lambda s: [pdt, s[0]], orig_set)
				# orig_set = map(collapse, orig_set)
				orig_set = map(lambda s: [mult(pdt, s[0])], orig_set)

				print>>sys.stderr, "(%d):"%i, orig_set

				ncycle += 1
				if [letter] in orig_set:
					found = True
					pos = orig_set.index([letter])
					break
			if not found:
				print>>sys.stderr, "--- i case ---"
				print "Case #%d: NO"%t
				continue

		remainder = ("1"+orig)[pos+1:]
		print>>sys.stderr, "found:", letter, "@", pos, "remainder =", remainder, "ncycle =", ncycle

		letter, pos = "j", -1
		# check if letter in remainder string
		remainder_set = list(remainder)
		remainder_set = map(collapse, remainder_set)
		if letter in remainder_set:
			pos = remainder_set.index(letter)
		else:
			found = False
			for power in xrange(4):
				# nxt_set = []
				# for item in orig_set_save:
				# 	nxt_set.append(remainder_set+(orig_sz_save*power)+item)
				# nxt_set = map(collapse, nxt_set)
				multiplier = collapse(remainder_set+(orig_sz_save*power))
				multiplier = "1" if len(multiplier) == 0 else multiplier[0]
				nxt_set = map(lambda s: [mult(multiplier, s[0])], orig_set_save)

				print>>sys.stderr, "original string powered %d times:"%power, nxt_set
				ncycle += 1
				if [letter] in nxt_set:
					found = True
					pos = nxt_set.index([letter])
					break
			if not found:
				print>>sys.stderr, "--- j case ---"
				print "Case #%d: NO"%t
				continue

		print>>sys.stderr, "found:", letter, "@", pos, "remainder =", remainder, "ncycle =", ncycle

		Xp = X % 4
		if Xp == 0: total = 1
		else:
			total = orig_sz_save*Xp
			total = reduce(lambda x,y: mult(x,y), total)

		ans = (total=="-1") and (X>=ncycle)
		print>>sys.stderr, "total =", total, ";X =", X, ";ncycle =", ncycle

		print "Case #%d: %s"%(t, "YES" if ans else "NO")
