#!/usr/bin/env python
# -*- coding: utf-8 -*-
_cayley = \
'''
	1 	1 	−1 	i 	−i 	j 	−j 	k 	−k
	−1 	−1 	1 	−i 	i 	−j 	j 	−k 	k
	i 	i 	−i 	−1 	1 	k 	−k 	−j 	j
	−i 	−i 	i 	1 	−1 	−k 	k 	j 	−j
	j 	j 	−j 	−k 	k 	−1 	1 	i 	−i
	−j 	−j 	j 	k 	−k 	1 	−1 	−i 	i
	k 	k 	−k 	j 	−j 	−i 	i 	−1 	1
	−k 	−k 	k 	−j 	j 	i 	−i 	1 	−1
'''
def _init():
	global mult
	global inv
	global sym
	sym = []
	rows = []
	inv = {}
	for i, row in enumerate(_cayley.strip().split('\n')):
		row = row.split()
		inv[row[0]] = i
		sym.append(row[0])
		rows.append(row[1:])
	mult = [[None] * len(rows) for _ in rows]
	for x, row in enumerate(rows):
		for y, z_sym in enumerate(row):
			z = inv[z_sym]
			mult[x][y] = z
_init()
def qmul(x, y):
	return mult[x][y]
def qconst(s):
	return reduce(qmul, map(inv.__getitem__, s))
def qpow(b, e, _1=qconst('1')):
	assert e >= 0
	if e:
		x = qpow(mult[b][b], e / 2)
		if e % 2:
			x = mult[b][x]
		return x
	return _1
def solve(a, x, _1=qconst('1'), _i=qconst('i'), _ij=qconst('ij'), _ijk=qconst('ijk')):
	if qpow(reduce(qmul, a), x) != _ijk:
		return False
	# A * a + a[:B] where 0 <= A < x, 0 <= B <= len(a)
	state_mid = _i, False
	state_fin = _ij, True
	got_i = False
	pre = _1, got_i
	reach = [pre]
	reach_set = set(reach)
	for val in a:
		pre = mult[pre[0]][val], got_i
		# BEGIN
		#print sym[pre[0]],
		if pre in reach_set:
			continue
		reach_set.add(pre)
		reach.append(pre)
		if pre == state_fin:
			return True
		if pre == state_mid:
			got_i = True
		# END
	prod = pre[0]
	assert prod == reduce(qmul, a)
	for _ in xrange(x - 1):
		old_key = (len(reach), got_i)
		# TODO start where we left off
		for i, pre in enumerate(list(reach)):
			pre = mult[prod][pre[0]], got_i
			# BEGIN
			#print sym[pre[0]],
			if pre in reach_set:
				continue
			reach_set.add(pre)
			reach.append(pre)
			if pre == state_fin:
				return True
			if pre == state_mid:
				got_i = True
			# END
		if old_key == (len(reach), got_i):
			break
	#print a, ', '.join(map(sym.__getitem__, reach))
	return False
def solve_brute(a, x, _1=qconst('1'), _i=qconst('i'), _ij=qconst('ij'), _ijk=qconst('ijk')):
	if qpow(reduce(qmul, a), x) != _ijk:
		return False
	# A * a + a[:B] where 0 <= A < x, 0 <= B <= len(a)
	pre = _1
	got_i = False
	for val in a * x:
		pre = mult[pre][val]
		if got_i and pre == _ij:
			return True
		if pre == _i:
			got_i = True
	return False
def main():
	for t in xrange(1, 1 + int(raw_input())):
		print 'Case #%d:' % t,
		l, x = map(int, raw_input().split())
		a = map(inv.__getitem__, raw_input().strip())
		assert solve(a, x) == solve_brute(a, x)
		print 'YES' if solve(a, x) else 'NO'
if __name__ == '__main__':
	main()
