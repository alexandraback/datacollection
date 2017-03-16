#!/usr/bin/python

from time import time
from sys import argv, stdin, stderr

def multimap(a):
	b = {}
	for i in a:
		b[i] = b.get(i, 0)+1
	return b

class Chest:
	def __init__(self, (line, i) ):
		line = map(int, line.split())
		self.lock = line[0]
		self.i = i+1
		self.flag = 2**i
		self.keys = multimap(line[2:])


def has_key(a, k):
	return a.get(k,0) > 0

def new_keys(one, two, used):
	out = dict(one)
	for i, v in two.items():
		out[i] = out.get(i, 0) + v
	out[used] -= 1
	return out

test_count = int(stdin.readline())
for test_no in xrange(1,test_count+1):
	K, N = map(int, stdin.readline().split())

	keys = map(int, stdin.readline().split())
	keys = multimap(keys)

	chests = [ (stdin.readline(),i) for i in xrange(N) ]
	chests = map( Chest, chests )

	states = set()

	def search( keys, state, answer=[] ):
		if state == 2**N-1:
			return answer
		if state in states:
			return None
		states.add(state)

		for chest in chests:
			if (state&chest.flag) == 0 and has_key(keys, chest.lock):
				nkeys = new_keys(keys, chest.keys, chest.lock)
				ret = search( nkeys, state|chest.flag, answer + [chest.i] )
				if ret:
					return ret

		return None

	answer = search(keys, 0)
	if answer == None:
		print "Case #%d: IMPOSSIBLE" % test_no
	else:
		print "Case #%d: %s" % (test_no, ' '.join(map(str,answer)))
