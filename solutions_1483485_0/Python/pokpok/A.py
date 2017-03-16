#!/usr/bin/env python2
"""
Invoke as:      ./A.py A small 0

Include the A in the arguments because it is just a part of a file name and to
make the arguments compatible with submitting.

Author: Paul Koppen
Website: http://paulkoppen.com/
"""
import string


# Learn translation from example given in the problem statement.
def learnbyexample(G, S, basis=dict()):
	import string
	mapping       = basis.copy()
	mapping.update((G[i],S[i]) for i in xrange(len(G)))
	mapfrom,mapto = zip(*mapping.items())
	missingfrom   = set(string.lowercase).difference(set(mapfrom))
	missingto     = set(string.lowercase).difference(set(mapto))
	mapfrom       = ''.join(mapfrom + tuple(missingfrom))
	mapto         = ''.join(mapto + tuple(missingto))
	return string.maketrans(''.join(mapfrom), ''.join(mapto))
EX_CIPHER = '''ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv'''
EX_PLAIN  = '''our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up'''
TRANS     = learnbyexample(EX_CIPHER, EX_PLAIN, dict(y='a',e='o',q='z'))



def solve(G):
	""" inputs vary between different challenges, so adapt.
	output must be an iterable of strings, even if the answer is one string
	"""
	S = G.translate(TRANS)
	return (S,)


def challenges(T, lines):
	""" yield challenge parameters one set at a time
	there are T challenges
	lines is an iterator over the input file, producing tokenized lines
	"""
	# note this passes each token as a separate argument to solve()
	#for i in xrange(T):
	#	yield lines.next()
	for i in xrange(T):
		yield (' '.join(lines.next()),)



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
