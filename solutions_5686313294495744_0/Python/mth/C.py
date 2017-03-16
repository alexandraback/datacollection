#!/usr/bin/env python

FILE_NAME_BASE = 'C-small-attempt0'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

from collections import defaultdict

def parse(inp):
	n, = (int(x) for x in inp.readline().split())
	topics = []
	for i in xrange(n):
		topic = inp.readline().split()
		assert len(topic) == 2
		topics.append(topic)
	return topics,

def subsets(sequence):
	'''Iterates through all subsets of the given sequence.
	Each yielded element is a tuple containing a subset of the elements of
	the original sequence, in the same order as in the original sequence.
	'''
	sequence = tuple(sequence)
	size = len(sequence)
	def rec(s, i):
		if i == size:
			yield tuple(s)
		else:
			s.append(sequence[i])
			for sub in rec(s, i + 1):
				yield sub
			del s[-1]
			for sub in rec(s, i + 1):
				yield sub
	return rec([], 0)

def wordsToIndices(words):
	known = {}
	for word in words:
		idx = known.get(word)
		if idx is None:
			idx = len(known)
			known[word] = idx
		yield idx

def pairedWith(pairs):
	paired = defaultdict(list)
	for word1, word2 in pairs:
		paired[word1].append(word2)
	return dict(paired)

'''
On a sheet, all topics could be fake, except the ones where either the first or the second word is the earliest occurrence of that word.

#fakes = #topic - #unique
#unique = #new_first + #new_second - #new_both

Every word has to be used for the first time once, so that is constant across all possible sheets. Therefore the sheet with the most possible fakes is the sheet with the highest number of topics that introduces two new words at once.

In other words, we must find the size of the largest subset of topics for which both the first and the second word are unique among that subset.
'''

def solve(topicWords):
	#topics = (
		#list(wordsToIndices(topic[0] for topic in topicWords)),
		#list(wordsToIndices(topic[1] for topic in topicWords))
		#)
	topics = topicWords

	matches = (
		pairedWith(topics),
		pairedWith((w2, w1) for w1, w2 in topics)
		)

	maxDoubleIntro = 0
	for intro in subsets(topics):
		if len(set(topic[0] for topic in intro)) != len(intro):
			continue
		if len(set(topic[1] for topic in intro)) != len(intro):
			continue
		maxDoubleIntro = max(maxDoubleIntro, len(intro))

	return len(topics) - len(matches[0]) - len(matches[1]) + maxDoubleIntro

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
