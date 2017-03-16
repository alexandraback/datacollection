'''
Created on Mar 11, 2014

@author: John Cornwell
'''
import operator,math,string,itertools,fractions,heapq,collections,re,array,bisect,random
from fractions import gcd
def lcm(a, b):
	return a * b / gcd(a, b)
FC_IN = None
def r1(fc):
	return fc(FC_IN.readline()[:-1])
def rv(fc):
	return map(fc, FC_IN.readline()[:-1].split())

# Called before solving any functions
def init(i_num, fc_in):
	return
	


# Parse next set of arguments
def parse_next(fc_in):
	return rv(int)



# Solve individual instance
def solve(R, C, M):
	
	free = R*C - M
	print '%ix%i, %i mines, %i free' %(R,C,M, free)
	
	if R == 1:
		s_ret = 'c'
		s_ret += ''.join((free-1) * '.')
		s_ret += ''.join((M) * '*')
		return s_ret
	if C == 1:
		s_ret = 'c\n'
		s_ret += ''.join((free-1) * '.\n')
		s_ret += ''.join((M) * '*\n')
		return s_ret[:-1]
	
	if free == 1:
		s_ret = ''
		for i in range(R):
			for j in range(C):
					s_ret += '*'
			s_ret += '\n'
		
		s_ret = 'c' + s_ret[1:]
		return s_ret[:-1]
	
	if free < 4:
		return 'Impossible'
	
	last = min(R, free / 2)
	if free - (last * 2) == 1:
		last -= 1
	if last < 2:
		return 'Impossible'
	
	heights = [last, last]
	free -= last * 2
	for i in range(2, C):
		if free <= last:
			heights.append(free)
		elif free == R+1:
			heights.append(R-1)
		else:
			heights.append(R)
		free -= heights[-1]
		if heights[-1] == 1:
			return 'Impossible'
		if heights[-1] > heights[-2]:
			return 'Impossible'
	
	if free != 0:
		return 'Impossible'
	
	print free, heights
	
	s_ret = ''
	for i in range(R):
		for j in range(C):
			if heights[j] > i:
				s_ret += '.'
			else:
				s_ret += '*'
		s_ret += '\n'
	
	s_ret = 'c' + s_ret[1:]
	
	
	return s_ret[:-1]



def _run_main():
	# Config
	global FC_IN
	s_let = 'C'
	s_run = 2
	
	if s_run == 0:
		fc_in = open('infile.in', 'r')
	elif s_run == 1:
		fc_in = open('Z:\Users\John Cornwell\Downloads\%s-small-attempt10.in' % s_let, 'r')
	else:
		fc_in = open('Z:\Users\John Cornwell\Downloads\%s-large.in' % s_let, 'r')
	fc_out = open('out.txt', 'w')
	FC_IN = fc_in
	i_num = int(fc_in.readline())
	init(i_num, fc_in)
	
	# Pare and solve test cases
	for i in range(1, i_num+1):
		args = parse_next(fc_in)
		ret = solve(*args)
		s_line = 'Case #%i:\n%s' % (i, str(ret))
		print s_line
		fc_out.write(s_line + '\n')
		
		
if __name__ == '__main__':
	_run_main()