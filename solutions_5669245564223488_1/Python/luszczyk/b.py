#!/usr/bin/env python3

from collections import Counter
from itertools import *
from string import ascii_lowercase

def read_ints():
	return map(int, input().strip().split())

def unique_str(s):
	res = []
	used = set()
	last = None
	for ch in s:
		if ch == last:
			continue
		if ch in used:
			return False
		last = ch
		used.add(ch)
		res.append(ch)
	return ''.join(res)

def fact(x, mod):
	return 1 if x == 0 else (x*fact(x-1, mod))%mod

def test():
	n, = read_ints()
	t = input().strip().split()

	single = Counter()
	begins = set()
	ends = set()
	inside = set()

	vertices = set()

	graph = { let: [] for let in ascii_lowercase }

	for s in t:
		uniq = unique_str(s)
		if not uniq:
			return 0

		#print(uniq)

		if len(uniq)==1:
			single[uniq] += 1

		else:
			if uniq[0] in begins or uniq[0] in inside:
				return 0
			if uniq[-1] in ends or uniq[-1] in inside:
				return 0

			begins.add(uniq[0])
			ends.add(uniq[-1])

			for ch in uniq[1:-1]:
				if ch in inside or ch in ends or ch in begins:
					return 0
				inside.add(ch)

			#vertices.add((uniq[0], uniq[-1]))
			graph[uniq[0]].append(uniq[-1])

	vis = set()
	ord = []
	num = dict()
	def toposort(v):
		if v in vis:
			return 	
		vis.add(v)

		for u in graph[v]:
			toposort(u)

		num[v] = len(ord)
		ord.append(v)

	for x in ascii_lowercase:
		toposort(x)

	for v in ord:
		for u in graph[v]:
			if num[u] > num[v]:
				return 0

	independent = 0
	for ch in ascii_lowercase:
		if ch in begins and not ch in ends:
			independent += 1
		if ch in single and not ch in begins and ch not in ends:
			independent += 1
	
	#print(independent)
	#print(single)
	#print(begins)
	#print(ends)
	
	MOD = 1000000007
	result = fact(independent, MOD)
	for (x, rep) in single.items():
		result = (result * fact(rep, MOD))%MOD

	return result


if __name__=="__main__":
	T, = read_ints()
	for x in range(T):
		print("Case #{}: {}".format(x+1, test()))
