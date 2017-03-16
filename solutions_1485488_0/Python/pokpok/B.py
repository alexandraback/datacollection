#!/usr/bin/env python
"""
Invoke as:      ./B.py B small 0

Include the B in the arguments because it is just a part of a file name and to
make the arguments compatible with submitting.

Author: Paul Koppen
Website: http://paulkoppen.com/
"""
from heapq import *


# state = (time spent, falling, waterlevel, position, old positions)
#       = (t, f, H, pos, expos)


def heuristic(state, N, M):
	# time taken so far + minimal time to reach exit = optimistic total time
	# for equal estimates, favour non-falling water
	t, f, H, pos, expos = state
	x, y                = pos
	return (t+(N-y)+(M-x),f)

def expandto(ceilings, floors, state, newpos):
	t, f, H, pos, expos = state
	x, y                = pos
	xi, yi              = newpos
	
	d1 = ceilings[y][x] - floors[yi][xi]
	if d1 < 50: return None
	d2 = ceilings[yi][xi] - floors[yi][xi]
	if d2 < 50: return None
	d3 = ceilings[yi][xi] - floors[y][x]
	if d3 < 50: return None
	
	d4  = ceilings[yi][xi] - H
	dH  = min(0, (d4 - 50))
	if dH == 0 and not f:
		dt = 0
	else:
		f   = 1						# since we needed to wait, the water is falling
		dt1 = -dH / 10.				# time to wait
		d6  = H + dH - floors[y][x]
		dt2 = 10 if d6 < 20 else 1	# time to kayak
		dt  = dt1 + dt2
		dH  = -dt * 10
	
	newstate = (t+dt, f, H+dH, newpos, (pos,)+expos)
	return newstate

	
def expand(ceilings, floors, state):
	N, M                = len(ceilings), len(ceilings[0])
	t, f, H, pos, expos = state
	x, y                = pos

	# move to new square immediately: is fast (+1s) if water level >= 20cm, otherwise slow (+10s)
	# why wait to move to new square? If water level needs to lower to enter that square.
	
	# check current ceiling - next floor >= 50cm
	# check next ceiling - next floor    >= 50cm
	# check next ceiling - current floor >= 50cm
	
	# check next ceiling - water level >= 50cm  --> this is the earliest I can enter and so determines dt_1
	#     !!! if dt_1 <= 0 and the water level is not falling, the step will cost me 0 !!!
	# then see if the waterlevel at that time will be >= 20cm --> if so, dt = dt_1 + 1, else dt = dt_1 + 10
	
	# but first check new position will be on the board
	newstates = []
	if x < M-1 and (x+1,y) not in expos:
		newstates.append(expandto(ceilings, floors, state, (x+1,y)))
	if x > 0 and (x-1,y) not in expos:
		newstates.append(expandto(ceilings, floors, state, (x-1,y)))
	if y < N-1 and (x,y+1) not in expos:
		newstates.append(expandto(ceilings, floors, state, (x,y+1)))
	if y > 0 and (x,y-1) not in expos:
		newstates.append(expandto(ceilings, floors, state, (x,y-1)))
	
	return [s for s in newstates if s]

		
def solve(H, N, M, C, F):
	""" inputs vary between different challenges, so adapt.
	output must be an iterable of strings, even if the answer is one string
	"""
	state0 = (0, 0, H, (0,0), ())
	pool   = []
	heappush(pool, (heuristic(state0,N,M),state0))
	while len(pool):
		heur,state = heappop(pool)
		if state[3] == (M-1,N-1):
			return ('%.06f' % state[0],)
		for newstate in expand(C, F, state):
			heappush(pool, (heuristic(newstate,N,M),newstate))
	return ("IMPOSSIBLE",)


def challenges(T, lines):
	""" yield challenge parameters one set at a time
	there are T challenges
	lines is an iterator over the input file, producing tokenized lines
	"""
	# note this passes each token as a separate argument to solve()
	for i in xrange(T):
		print "Challenge %d" % (i+1)
		H,N,M = map(int, lines.next())
		C     = tuple(tuple(map(int, lines.next())) for j in xrange(N))
		F     = tuple(tuple(map(int, lines.next())) for j in xrange(N))
		yield (H, N, M, C, F)



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
