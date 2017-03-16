#!/usr/bin/env python

FILE_NAME_BASE = 'B-small-attempt0'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	maxE, regain, numAct = (int(x) for x in inp.readline().split())
	activities = tuple(int(x) for x in inp.readline().split())
	assert len(activities) == numAct
	return maxE, regain, activities

def solve(maxE, regain, activities):
	state = { maxE: 0 }
	for act in activities:
		newState = {}
		for energy, gain in state.iteritems():
			for spend in xrange(0, energy + 1):
				newEnergy = min(energy - spend + regain, maxE)
				newGain = gain + spend * act
				oldBest = newState.get(newEnergy, -1)
				if newGain > oldBest:
					newState[newEnergy] = newGain
		state = newState
	return max(state.itervalues())

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
