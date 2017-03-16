#!/usr/bin/env python

from collections import deque

def main():
	fin = open('input.txt', 'r')

	total_T = int(fin.readline())

	for T in xrange(1, total_T + 1):
		X, R, C = map(int, fin.readline().rstrip('\n').split())
		# print X, R, C

		resolve(X, R, C, T)

	# print '\n\n\ntest:\n'

	# for x in xrange(1, 21):
	# 	for y in xrange(1, 21):
	# 		for z in xrange(1, 21):
	# 			print x, y, z
	# 			resolve(x, y, z, (x, y, z))




		# print 'Case #{}: {} {}'.format(T, S2, S1)

def resolve(X, R, C, T):
	if R*C % X != 0 or X > R*C:
		print 'Case #{}: RICHARD'.format(T)
		return
	if X > max(R, C):
		print 'Case #{}: RICHARD'.format(T)
		return
	if X > R + C - 1:
		print 'Case #{}: RICHARD'.format(T)
		return
	if X > min(R, C)*2:
		print 'Case #{}: RICHARD'.format(T)
		return
	if X >= 7:		
		print 'Case #{}: RICHARD'.format(T)
		return
	if X == 4 and min(R, C) == 2:
		print 'Case #{}: RICHARD'.format(T)
		return
	if X == 6 and min(R, C) == 3 and max(R, C) >= 6:
		print 'Case #{}: RICHARD'.format(T)
		return
	if X < 2*min(R, C):
		print 'Case #{}: GABRIEL'.format(T)
		return
	if X <= 2:
		print 'Case #{}: GABRIEL'.format(T)
		return

	raise Exception(X, R, C)
	# print 'Case #{}: GABRIEL'.format(T)

if __name__ == '__main__':
	main()