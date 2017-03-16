#! /usr/bin/env python

from collections import defaultdict, Counter
from itertools import permutations

fname = 'B-small-attempt1'
fin = open(fname+'.in', 'r')
fout = open(fname+'.out', 'w')

def paths(e, nodes):
	if sum([sum(v.values()) for k, v in nodes.iteritems()]) == 0:
		return 1
	result = 0
	for n in nodes[e]:
		if nodes[e][n] > 0:
			nodes[e].subtract({n : 1})
			result += (1 + nodes[e][n]) * paths(n, nodes)
			nodes[e].update({n : 1})
	return result
	
def isvalid(s, found=None):	
	found = set()
	curr = s[0]
	for c in s:
		if c in found and c != curr:
			return False
		curr = c
		found.add(c)
	return True
	
def perms(carts, found, curr):
	if not carts:
		return 1
	r = 0
	for c in carts:
		if c[2] not in found and (c[0] not in found or curr == c[0]) and len(c[1] & found) == 0:
			newcarts = list(carts)
			newcarts.remove(c)
			newfound = set(found)
			newfound.update(c[1])
			newfound.add(c[0])
			newfound.add(c[2])
			r += perms(newcarts, newfound, c[2])
	return r
	
def solve(fin):
	N = int(fin.readline())
	nodes = defaultdict(Counter)
	carts = fin.readline().split()
	cartsets = []
	internals = set()
	dupcount = Counter(carts)
	m = 1
	for c in dupcount:
		mult = 1
		while dupcount[c] > 1:
			carts.remove(c)
			dupcount[c] -= 1
			mult *= 2
		m *= mult
	for c in carts:
		inter = set(c[1:-1])
		cartsets.append((c[0], inter, c[-1]))
		if len(inter & internals) > 0 or not isvalid(c):
			return 0
		internals.update(inter)
		# nodes[c[0]].update({c[-1]: 1})
	r = 0
	# startnodes = nodes.keys()
	# print startnodes
	# for start in startnodes:
	# 	r += paths(start, nodes)
	# for p in permutations(carts):
		# if isvalid(''.join(p)):
			# r += 1
	# cartsets.remove(cartsets[0])
	for c in cartsets:
		newcarts = list(cartsets)
		newcarts.remove(c)
		newfound = set()
		newfound.update(c[1])
		newfound.add(c[0])
		r2 = perms(newcarts, newfound, c[2])
		r += r2
	return m*r

T = int(fin.readline())
for i in xrange(1,T+1):
	print i
	fout.write("Case #"+str(i)+": "+str(solve(fin))+"\n")
fout.close()
fin.close()
