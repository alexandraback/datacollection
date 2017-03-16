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
	n = r1(int)
	nblock = rv(float)
	kblock = rv(float)
	return n, nblock, kblock



# Solve individual instance
def solve(n, nblock, kblock):
	nblock = zip(nblock, 'n' * n)
	kblock = zip(kblock, 'k' * n)
	unused, players = zip(*sorted(nblock + kblock, reverse=True))
	print players
	def opt_war((kens, tot), player):
		if player == 'k':
			return (kens+1, tot)
		else:
			if kens > 0:
				return (kens-1, tot-1)
			return (0, tot)
	ret_war = reduce(opt_war, players, (0,n))[1]
	def opt_dwar((naos, tot), player):
		if player == 'n':
			return (naos+1, tot)
		else:
			if naos > 0:
				return (naos-1, tot+1)
			return (0, tot)
	ret_dwar = reduce(opt_dwar, players, (0,0))[1]
	
	return '%i %i' %(ret_dwar, ret_war)



def _run_main():
	# Config
	global FC_IN
	s_let = 'D'
	s_run = 2
	
	if s_run == 0:
		fc_in = open('infile.in', 'r')
	elif s_run == 1:
		fc_in = open('Z:\Users\John Cornwell\Downloads\%s-small-attempt0.in' % s_let, 'r')
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
		s_line = 'Case #%i: %s' % (i, str(ret))
		print s_line
		fc_out.write(s_line + '\n')
		
		
if __name__ == '__main__':
	_run_main()