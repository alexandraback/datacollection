#!/usr/bin/env python2
"""
Invoke as:      ./D.py D small 0

Include the D in the arguments because it is just a part of a file name and to
make the arguments compatible with submitting.

Author: Paul Koppen
Website: http://paulkoppen.com/
"""
import numpy as np
import math

def converthall(L):
	X = [(x,y) for y,l in enumerate(L) for x,c in enumerate(l) if c=='X']
	M = [(x,y) for y,l in enumerate(L) for x,c in enumerate(l) if c=='#']
	return (X, M)

def filterduplicates(P):
	def filterordered(pts):
		sign     = lambda n: -1 if n<0 else (0 if n==0 else 1)
		eqsign   = lambda (a,b),(c,d): sign(a)==sign(c) and sign(b)==sign(d)
		coincide = lambda v1,v2: np.cross(v1,v2)==0 and eqsign(v1,v2)
		return reduce(lambda a,b: a if coincide(a[-1],b) else a + [b], pts[1:], pts[:1])
		
		i   = 0
		a,b = pts[i]
		b   = float(b)
		while i<len(pts)-1:
			if (b==0 and pts[i+1][1]==0) or     \
						(b!=0 and a*(pts[i+1][1]/b)==pts[i+1][0]):
				del pts[i+1]
			else:
				i  += 1
				a,b = pts[i]
				b   = float(b)
		return pts
	pts = P[:]
	if len(pts) > 0:
		pts.sort(key=lambda (dx,dy):(math.atan2(dx,dy), dx, dy))
		pts = filterordered(pts)
		pts = pts[-1:] + pts[:-1]
		pts = filterordered(pts)
	return pts

def solve(H, W, D, L):
	""" inputs vary between different challenges, so adapt.
	output must be an iterable of strings, even if the answer is one string
	"""
	isself   = lambda (dx,dy): dx==0 and dy==0
	isinview = lambda (dx,dy): dx*dx + dy*dy <= D2 and not isself((dx,dy))
	
	D2   = D * D
	X,M  = converthall(L)
	X    = [(x-.5,y-.5) for x,y in X]
	H   -= 2
	W   -= 2
	x,y  = X[0]
	cmin = -D / (2*W)
	cmax = int(D + 2*x) / (2*W)
	rmin = -D / (2*H)
	rmax = int(D + 2*y) / (2*H)
	pts  = []
	debug = cmax == 25 and rmax == 25
	if debug: print 'DEBUG'
	# find all reflections
	for r in xrange(rmin, rmax+1):
		dy1 = 2*r*H
		dy2 = dy1 - int(2*y)
		for c in xrange(cmin, cmax+1):
			dx1 = 2*c*W
			dx2 = dx1 - int(2*x)
			pts.extend([(dx1,dy1),(dx1,dy2),(dx2,dy1),(dx2,dy2)])
	if debug: print len(pts)
	# filter out too distant points
	if debug: print 'filtering distant points...'
	pts  = filter(isinview, pts)
	if debug: print len(pts)
	# and filter out duplicates (reflection through self)
	if debug: print 'filtering duplicates...'
	pts = filterduplicates(pts)
	y   = len(pts)
	if debug: print y
	#f = open('test.out','a')
	#f.write(' '.join(map(lambda pt:'(%d,%d)'%pt,pts)) + '\n')
	#f.close()
	return (str(y),)


def challenges(T, lines):
	""" yield challenge parameters one set at a time
	there are T challenges
	lines is an iterator over the input file, producing tokenized lines
	"""
	# note this passes each token as a separate argument to solve()
	#for i in xrange(T):
	#	yield lines.next()
	for i in xrange(T):
		H,W,D = map(int, lines.next())
		L     = [lines.next()[0] for j in xrange(H)]
		print 'test %d' % i
		yield (H, W, D, L)



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
