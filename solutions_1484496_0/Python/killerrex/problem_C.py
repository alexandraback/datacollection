#!/usr/bin/python3

import itertools

def printl(L):
	s = ""
	for i in L:
		s += str(i) + " "
	print(s[:-1])

def solve(elems):

	sums = dict()
	for i in range(len(elems)):
		for rng in itertools.combinations(elems, i):
			S = sum(rng)
			if S in sums:
				printl(sums[S])
				printl(rng)
				# Finish!
				return
			else:
				sums[S] = rng
	print("Impossible")


def read_int(fd):
	return [ int(x) for x in fd.readline().strip().split() ]


def main(fd):
	T = read_int(fd)[0]
	
	for i in range(T):
		V = read_int(fd)
		print("Case #" + str(i+1) + ":")
		solve(V[1:])



import sys

fd = open(sys.argv[1], "r")

main(fd)

fd.close()
	

