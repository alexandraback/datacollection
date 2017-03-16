'''
Created on Mar 11, 2014

@author: John Cornwell
'''
import operator,math,string,itertools,fractions,heapq,collections,re,array,bisect,random
from fractions import gcd
def lcm(a, b):
	return a * b / gcd(a, b)


# Called before solving any functions
def init(i_num, fc_in):
	return
	


# Parse next set of arguments
def parse_next(fc_in):
	return tuple(map(float, fc_in.readline().split()))



# Solve individual instance
def solve(C, F, X):
	ret = 1e100
	
	curtime = 0
	rate = 2.
	while True:
		new = curtime + X / rate
		if new > ret:
			break
		ret = new
		curtime += C / rate
		rate += F
	
	return ret



def _run_main():
	# Config
	s_let = 'B'
	s_run = 1
	
	if s_run == 0:
		fc_in = open('infile.in', 'r')
	elif s_run == 1:
		fc_in = open('Z:\Users\John Cornwell\Downloads\%s-small-attempt0.in' % s_let, 'r')
	else:
		fc_in = open('Z:\Users\John Cornwell\Downloads\%s-large-attempt0.in' % s_let, 'r')
	fc_out = open('out.txt', 'w')
	
	i_num = int(fc_in.readline())
	init(i_num, fc_in)
	
	# Pare and solve test cases
	for i in range(1, i_num+1):
		args = parse_next(fc_in)
		ret = solve(*args)
		s_line = 'Case #%i: %s' % (i, str(ret))
		print s_line
		fc_out.write(s_line + '\n')
		
		
if __name__ == '__main__':
	_run_main()