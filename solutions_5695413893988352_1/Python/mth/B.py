#!/usr/bin/env python

FILE_NAME_BASE = 'B-large'
NUM_PROCESSES = 4
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
	numDigits = len(c)
	best = [(10 ** numDigits, None, None)]
	def rec(i, sc, sj):
		if i == numDigits:
			best[0] = min(best[0], (abs(sc - sj), sc, sj))
		else:
			pc = c[i]
			pj = j[i]
			if pc == '?' and pj == '?':
				if sc < sj:
					rec(i + 1, sc * 10 + 9, sj * 10)
				elif sc > sj:
					rec(i + 1, sc * 10, sj * 10 + 9)
				else:
					rec(i + 1, sc * 10, sj * 10)
					rec(i + 1, sc * 10, sj * 10 + 1)
					rec(i + 1, sc * 10 + 1, sj * 10)
			elif pc == '?':
				dj = int(pj)
				if sc < sj:
					rec(i + 1, sc * 10 + 9, sj * 10 + dj)
				elif sc > sj:
					rec(i + 1, sc * 10 + 0, sj * 10 + dj)
				else:
					if dj > 0:
						rec(i + 1, sc * 10 + dj - 1, sj * 10 + dj)
					rec(i + 1, sc * 10 + dj, sj * 10 + dj)
					if dj < 9:
						rec(i + 1, sc * 10 + dj + 1, sj * 10 + dj)
			elif pj == '?':
				dc = int(pc)
				if sc < sj:
					rec(i + 1, sc * 10 + dc, sj * 10 + 0)
				elif sc > sj:
					rec(i + 1, sc * 10 + dc, sj * 10 + 9)
				else:
					if dc > 0:
						rec(i + 1, sc * 10 + dc, sj * 10 + dc - 1)
					rec(i + 1, sc * 10 + dc, sj * 10 + dc)
					if dc < 9:
						rec(i + 1, sc * 10 + dc, sj * 10 + dc + 1)
			else:
				dc = int(pc)
				dj = int(pj)
				rec(i + 1, sc * 10 + dc, sj * 10 + dj)
	rec(0, 0, 0)

	#for sc in cScores:
		#for sj in jScores:
			#diffs.append((abs(sc - sj), sc, sj))

	formatstr = '%0' + str(numDigits) + 'd'
	return (formatstr + ' ' + formatstr) % best[0][1:]

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
