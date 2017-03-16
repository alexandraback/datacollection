#!/usr/bin/env python2

def read_ints():
	return map(int, raw_input().strip().split())

MAX_POS = 100

way = dict()

def is_cor(t):
	pos, s, j = t

	return abs(pos[0]) <= MAX_POS and abs(pos[1]) <= MAX_POS

rep = set()

def bfs():
	queue = [ ((0,0), '', 1) ]

	while len(queue) > 0:
		pos, s, j = queue.pop(0)
		x, y = pos

		global way
		way[pos] = s

		next = [ ((x, y+j), s+'N', j+1),
			 ((x, y-j), s+'S', j+1),
			 ((x+j, y), s+'E', j+1),
			 ((x-j, y), s+'W', j+1) ]

		for t in next:
			if is_cor(t) and t[0] not in rep:
				rep.add(t[0])
				queue.append(t)

bfs()
import sys
print  >>sys.stderr, 'ok'

T, = read_ints()

for cur_test in xrange(T):
	x, y = read_ints()

	res = way[(x,y)]

	print 'Case #{}: {}'.format(cur_test+1, res)
