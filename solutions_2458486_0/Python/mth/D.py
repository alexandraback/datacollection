#!/usr/bin/env python

from collections import defaultdict

FILE_NAME_BASE = 'D-small-attempt0'
NUM_PROCESSES = 4
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	numInitKeys, numChests = (int(x) for x in inp.readline().split())
	initKeys = tuple(int(x) - 1 for x in inp.readline().split())
	assert len(initKeys) == numInitKeys
	chests = []
	for _ in xrange(numChests):
		chest = tuple(int(x) for x in inp.readline().split())
		toOpen = chest[0] - 1
		assert 0 <= toOpen < 200, toOpen
		numKeysInChest = chest[1]
		keysInChest = tuple(x - 1 for x in chest[2 : ])
		assert len(keysInChest) == numKeysInChest
		chests.append((toOpen, keysInChest))
	return initKeys, tuple(chests)

def solve(initKeys, chests):
	print '=' * 10
	print initKeys
	for i, (toOpen, keys) in enumerate(chests):
		print '%d: %d -> %s' % (i, toOpen, keys)

	#openedBy = defaultdict(list)
	#for i, (toOpen, keys) in enumerate(chests):
		#openedBy[toOpen].append(i)
	#print openedBy

	#def canOpen(keys):
		#return tuple(
			#i
			#for i, (toOpen, newKeys) in enumerate(chests)
			#if toOpen in keys
			#)
	#initCanOpen = canOpen(initKeys)
	#print initCanOpen

	beenThere = set()
	allOpen = (1 << len(chests)) - 1
	def search(opened, keys):
		if opened == allOpen:
			return ()
		if opened in beenThere:
			return None
		else:
			beenThere.add(opened)
		for i, (toOpen, newKeys) in enumerate(chests):
			if (opened & (1 << i)) == 0 and toOpen in keys:
				recKeys = list(keys)
				recKeys.remove(toOpen)
				recKeys += newKeys
				rec = search(opened | (1 << i), recKeys)
				if rec is not None:
					return (i, ) + rec
		return None

	solution = search(0, initKeys)

	if solution is None:
		return 'IMPOSSIBLE'
	else:
		return ' '.join('%d' % (c + 1) for c in solution)

def main():
	import sys
	sys.setrecursionlimit(RECURSION_LIMIT)

	import resource
	soft, hard = resource.getrlimit(resource.RLIMIT_AS)
	resource.setrlimit(resource.RLIMIT_AS, (MEM_LIMIT_GB * 1024 ** 3, hard))

	inp = open(FILE_NAME_BASE + '.in', 'r')
	numCases = int(inp.readline())
	if NUM_PROCESSES == 0:
		results = [
			solve(*parse(inp))
			for _ in range(numCases)
			]
	else:
		from multiprocessing import Pool
		pool = Pool(NUM_PROCESSES)
		results = [
			pool.apply_async(solve, parse(inp))
			for _ in range(numCases)
			]
	inp.close()
	out = open(FILE_NAME_BASE + '.out', 'w')
	for case, result in enumerate(results):
		value = result if NUM_PROCESSES == 0 else result.get()
		out.write('Case #%d: %s\n' % (case + 1, value))
		out.flush()
	out.close()

if __name__ == '__main__':
	main()
