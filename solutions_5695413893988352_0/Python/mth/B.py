#!/usr/bin/env python

FILE_NAME_BASE = 'B-small-attempt0'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

import re

def parse(inp):
	c, j = (x for x in inp.readline().split())
	assert len(c) == len(j)
	return c, j

def validScores(pattern):
	regexp = re.compile(pattern.replace('?', '.'))
	formatstr = '%0' + str(len(pattern)) + 'd'
	for score in xrange(10 ** len(pattern)):
		if regexp.match(formatstr % score):
			yield score

def solve(c, j):
	cScores = list(validScores(c))
	jScores = list(validScores(j))
	#print c, cScores
	#print j, jScores

	diffs = [
		(abs(sc - sj), sc, sj)
		for sc in cScores
		for sj in jScores
		]

	formatstr = '%0' + str(len(c)) + 'd'
	return (formatstr + ' ' + formatstr) % min(diffs)[1:]

def main():
	import sys
	sys.setrecursionlimit(RECURSION_LIMIT)

	import resource
	soft, hard = resource.getrlimit(resource.RLIMIT_AS)
	resource.setrlimit(resource.RLIMIT_AS, (MEM_LIMIT_GB * 1024 ** 3, hard))

	with open(FILE_NAME_BASE + '.in', 'r') as inp:
		numCases = int(inp.readline())
		inputs = [parse(inp) for _ in xrange(numCases)]

	if NUM_PROCESSES == 0:
		runners = [lambda inp=inp: apply(solve, inp) for inp in inputs]
	else:
		from multiprocessing import Pool
		from signal import SIGINT, SIG_IGN, signal
		pool = Pool(NUM_PROCESSES, signal, (SIGINT, SIG_IGN))
		runners = [pool.apply_async(solve, inp).get for inp in inputs]
		pool.close()

	caseFmt = '%' + str(len(str(numCases))) + 'd'
	progressFmt = '[%s/%s] %%s\n' % (caseFmt, caseFmt)
	with open(FILE_NAME_BASE + '.out', 'w') as out:
		for case, runner in enumerate(runners, 1):
			result = runner()
			out.write('Case #%d: %s\n' % (case, result))
			out.flush()
			sys.stderr.write(progressFmt % (case, numCases, result))

if __name__ == '__main__':
	main()
