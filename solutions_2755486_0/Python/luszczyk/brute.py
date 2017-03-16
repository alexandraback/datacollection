#!/usr/bin/env python2

from itertools import count

def read_ints():
	return map(int, raw_input().strip().split())

T, = read_ints()

def aa(t):
	global attacks
	global last_attack

	if t[1] == 0:
		return

	if t[0] in attacks:
		attacks[t[0]].append(t)
	else:
		attacks[t[0]] = [ t ]

	if t[0] > last_attack:
		last_attack = t[0]

def strong_enough(w, e, s):
	for v in xrange(w, e):
		if v not in wall or wall[v] < s:
			return False
	return True

def raise_to(s, w, e):
	global wall

	for v in xrange(w, e):
		if v not in wall:
			wall[v] = s
		else:
			wall[v] = max(s,wall[v])

def ca(t):
	d, n, w, e, s, dd, dp, ds = t

	aa((d+dd, n-1, w+dp, e+dp, s+ds, dd, dp, ds))
	
	return 0 if strong_enough(w, e, s) else 1

def ra(t):
	d, n, w, e, s, dd, dp, ds = t
	raise_to(s, w, e)

	

for cur_test in xrange(T):
	attacks = dict()
	wall = dict()
	last_attack = 0

	N, = read_ints()

	for tn in range(N):
		t = read_ints()

		aa(t)

	res = 0

	for i in count(0):
		if i > last_attack:
			break
		if not i in attacks:
			continue 

		for t in attacks[i]:
			res += ca(t)
		for t in attacks[i]:
			ra(t)

#		print 'day {} res {}'.format(i, res)

	print 'Case #{}: {}'.format(cur_test+1, res)
