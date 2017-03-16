#!/usr/bin/env python

FILE_NAME_BASE = 'A-large'
NUM_PROCESSES = 0

def parse(inp):
	numbers = tuple(int(x) for x in inp.readline().split())
	numCont = numbers[0]
	scores = numbers[1 : ]
	assert len(scores) == numCont
	return scores,

def solve(scores):
	total = sum(scores)

	sortedScores = sorted(scores)
	cumulative = 0
	for i in xrange(1, len(sortedScores)):
		cumulative += sortedScores[i - 1]
		nextScore = sortedScores[i]
		if cumulative + total < nextScore * i:
			unsafeCount = i
			break
	else:
		unsafeCount = len(sortedScores)
	safeLevel = float(sum(sortedScores[ : unsafeCount]) + total) / unsafeCount

	fractions = [max(safeLevel - score, 0) / total for score in scores]

	return ' '.join('%f' % (f * 100) for f in fractions)

if __name__ == '__main__':
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
