#! /usr/bin/env python
from itertools import count
from math import sqrt

fname = 'C-large'

fin = open(fname+'.in', 'r')
fout = open(fname+'.out', 'w')

# Goal pattern:
# _ _ _ _ . .
# _ _ _ _ . .
# _ _
# _ _
# . .
# . .

def buildpattern(C, R, empty):
	# for this function, C, R >= 3, 'empty' even & >= 4 or odd & >= 9
	x = [['*' for i in range(R)] for j in range(C)]
	empty -= 4
	x[0][0] = 'c'
	x[0][1] = '.'
	x[1][0] = '.'
	x[1][1] = '.'
	c = 2
	r = 2
	while empty > 1: # keep deducting blocks of 2
		if r < R and (C == c or c == r): # add another row
			x[0][r] = '.'
			x[1][r] = '.'
			r += 1
		elif c < C and (R == r or c == r - 1): #add another col
			x[c][0] = '.'
			x[c][1] = '.'
			c += 1
		else: # cannot add another pattern extension, start filling up
			break
		empty -= 2
	c = 2
	r = 2
	while empty > 0:
		if c == C:
			c = 2
			r += 1
		x[c][r] = '.'
		c += 1
		empty -= 1
	return '\n'.join([''.join(y for y in z) for z in zip(*x)])
	
def solve(fin):
	R, C, M = map(int, fin.readline().split())
	empty = R * C - M
	if M == 0:
		x = [['.' for i in range(R)] for j in range(C)]
		x[0][0] = 'c'
		return '\n'.join([''.join(y for y in z) for z in zip(*x)]) 
	if empty == 1: # empty == 0 does not exist
		x = [['*' for i in range(R)] for j in range(C)]
		x[0][0] = 'c'
		return '\n'.join([''.join(y for y in z) for z in zip(*x)]) 
	if R == 1: # special Case
		return 'c'+'.'*(empty-1)+'*'*M
	if C == 1: # special case
		return 'c\n'+'.\n'*(empty-1)+'*\n'*(M-1)+'*'
	if empty <= 3: # and C >= 2 and R >= 2, so M >= 1
		return 'Impossible'
	if R == 2 or C == 2: # special case
		if empty % 2 == 1:
			return 'Impossible'
		elif R == 2:
			return ('c'+'.'*(empty/2-1)+'*'*(M/2)+'\n'+
					'.'*(empty/2)+'*'*(M/2))
		elif C == 2:
			return 'c.\n'+'..\n'*(empty/2-1)+'**\n'*(M/2-1)+'**'
	# at this point C, R >= 3, 'empty' even & >= 4 or odd & >= 5
	if empty == 5 or empty == 7:
		return 'Impossible'
	# at this point C, R >= 3, 'empty' even & >= 4 or odd & >= 9
	return buildpattern(C, R, empty) 
	
T = int(fin.readline())

for i in xrange(1,T+1):
	fout.write("Case #"+str(i)+":\n"+str(solve(fin))+"\n")
fout.close()
fin.close()
