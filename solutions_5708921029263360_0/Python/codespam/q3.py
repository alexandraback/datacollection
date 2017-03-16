#!/usr/bin/env pypy

import collections
import itertools
import sys

d = sys.stdin.readlines()

def ok(pcs, K):
	seen_jp = collections.defaultdict(int)
	seen_js = collections.defaultdict(int)
	seen_ps = collections.defaultdict(int)

	for cs in pcs:
		j, p, s = cs
		if not (seen_jp[(j, p)] < K and seen_js[(j, s)] < K and seen_ps[(p, s)] < K):
			return False
		seen_jp[(j, p)] += 1
		seen_js[(j, s)] += 1
		seen_ps[(p, s)] += 1
	
	return True



def slow(J, P, S, K):
	cs = list(itertools.product(range(J), range(P), range(S)))
	for n in range(27, 0, -1):
		for pcs in itertools.combinations(cs, n):
			#print 'ok?: %r' % pcs
			if ok(pcs, K):
				#print 'ok'
				return pcs


for i, l in enumerate(d[1:]):
	print 'Case #%d:' % (i + 1),
	J, P, S, K = map(int, l.split())

	#def go(J, P, S, K):
	#	seen_jp = collections.defaultdict(int)
	#	seen_js = collections.defaultdict(int)
	#	seen_ps = collections.defaultdict(int)
	#	r = []
	#	for j in range(J):
	#		for p in range(P):
	#			for s in range(S):
	#				if seen_jp[(j, p)] < K and seen_js[(j, s)] < K and seen_ps[(p, s)] < K:
	#					seen_jp[(j, p)] += 1
	#					seen_js[(j, s)] += 1
	#					seen_ps[(p, s)] += 1
	#					r.append((j, p, s))
	#	return r

	#xr = {}
	#xr['JPS'] = go(J, P, S, K)
	#xr['JSP'] = go(J, S, P, K)
	#xr['PJS'] = go(P, J, S, K)
	#xr['PSJ'] = go(P, S, J, K)
	#xr['SJP'] = go(S, J, P, K)
	#xr['SPJ'] = go(S, P, J, K)

	###print xr
	#assert map(len, xr.values()) == [len(xr['JPS'])] * 6

	#r = xr['JPS']

	sr = slow(J, P, S, K)# if i not in [27, 39, 51, 79] else None

	r = sr

	#print l.strip(),'=',
	#sys.stdout.flush()
	print len(r)
	#print 'fast'
	for rr in r:
		print ' '.join(str(x + 1) for x in rr)
	#if sr:
	#	print 'slow'
	#	for rr in sr:
	#		print ' '.join(str(x + 1) for x in rr)

	#	#print sr
	#	assert len(r) == len(sr)
