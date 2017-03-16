#!/usr/bin/env python2
"""
Invoke as:      ./C.py C small 0

Include the C in the arguments because it is just a part of a file name and to
make the arguments compatible with submitting.

Author: Paul Koppen
Website: http://paulkoppen.com/
"""


def rotations(n, m):
	""" find all unique rotations r of n (including n) s.t. n <= r <= m
	we return them sorted
	"""
	s  = str(n)
	l  = len(s)
	ss = s + s
	r0 = (int(ss[i:i+l]) for i in xrange(l))
	r1 = (r for r in r0 if r >= n and r <= m)
	r2 = sorted(set(r1))
	return r2

def solve(A, B):
	""" inputs vary between different challenges, so adapt.
	output must be an iterable of strings, even if the answer is one string
	"""
	# A and B are integers
	# Store "x choose 2" results precomputed, with B <= 2,000,000 the maximum
	# number of rotations, x = len(r), is 7
	# We could also have precomputed all 2m rings, but because T <= 50, this
	# doesn't really make sense.
	xchoose2 = [0,0,1,3,6,10,15]
	y       = 0
	visited = dict()
	for n in xrange(A, B):
		if n in visited:
			continue
		r  = rotations(n, B)
		y += xchoose2[len(r)]
		visited.update((ri,1) for ri in r)
	return (str(y),)


def challenges(T, lines):
	""" yield challenge parameters one set at a time
	there are T challenges
	lines is an iterator over the input file, producing tokenized lines
	"""
	# note this passes each token as a separate argument to solve()
	for i in xrange(T):
		yield map(int, lines.next())



#================================================================= DEFAULT SETUP
def main(fnamein, fnameout, fnamesol=''):
	""" Solve the set of problems defined in a file.
	If solution file exists verify output.
	"""
	
	"""
	Open up the input file and set up a simple line parser
	"""
	# T challenges (test cases), possibly more lines
	fin        = open(fnamein)
	T          = int(fin.next())
	lines      = (l.rstrip('\r\n').split(' ') for l in fin)
	
	"""
	Read and parse the challenges one by one, compute the answer and write to
	file
	"""
	answers    = (solve(*ch) for ch in challenges(T, lines))
	with open(fnameout, 'w') as fout:
		fout.writelines('Case #%d: %s\n' % (i+1, ' '.join(ans))    \
					for i,ans in enumerate(answers))
	fin.close()
	
	"""
	If a solution file exists, verify the produced answer
	"""
	try:
		with open(fnamesol) as fsol:
			sol = fsol.read().rstrip('\r\n')
		with open(fnameout) as fout:
			out = fout.read().rstrip('\r\n')
	except IOError:
		pass
	else:
		if sol == out:
			print 'Correct: Good Job!'
		else:
			print 'Incorrect: Wrong Answer'


if __name__ == '__main__':
	import sys
	params = tuple(sys.argv[1:4])
	fnamein    = '%s-%s-%s.in'  % params
	fnameout   = '%s-%s-%s.out' % params
	fnamesol   = '%s-%s-%s.sol' % params
	main(fnamein, fnameout, fnamesol)
	print 'done.'
