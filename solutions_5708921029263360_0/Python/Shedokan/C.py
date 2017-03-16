# -*- coding: utf-8 -*-
#
# Copyright 2013 Eric Shtivelberg
#

import sys
from collections import defaultdict

practice = False

problem = 'C-small-attempt1'

lines = '''4
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1'''.split('\n')

if not practice:
	# Open the input file
	input_file_name = problem + '.in'
	input_file = open(input_file_name)
	lines = map(str.strip, input_file.readlines())
	input_file.close()

	print 'Closed input file...'

def read_line(): return lines.pop(0)
def read_parts(): return lines.pop(0).split(' ')
def read_int(): return int(lines.pop(0))
def read_ints(): return map(int, lines.pop(0).split(' '))
def read_float(): return int(lines.pop(0))
def read_floats(): return map(float, lines.pop(0).split(' '))


# Write the output
if not practice:
	output_file_name = problem + '.out'
	output_file = open(output_file_name, 'w')
else:
	output_file = sys.stdout

########## Contest Specific ##########

# The output list
output = []

T = read_int()

for t in range(1, T+1):
	J, P, S, K = read_ints()

	J_P = defaultdict(int)
	J_S = defaultdict(int)
	P_S = defaultdict(int)

	outfits = []
	for j in xrange(J):
		for p in xrange(P):
			for s in xrange(S):
				j_p = (j, p) if p > j else (p, j)
				j_s = (j, s) if s > j else (s, j)
				p_s = (p, s) if s > p else (s, p)
				if J_P[j_p] == K or J_S[j_s] == K or P_S[p_s] == K:
					continue

				J_P[j_p] += 1
				J_S[j_s] += 1
				P_S[p_s] += 1
				# print j, s, J_S[(j, s)]
				# print p, s, P_S[(j, s)]

				# print j+1, p+1, s+1
				outfits.append('{} {} {}'.format(j+1, p+1, s+1))

	output.append('{}\n{}'.format(len(outfits), '\n'.join(outfits)))


########## Contest Specific End ##########

cases = ['Case #{}: {}'.format(i+1, output[i]) for i in range(len(output))]
output_file.write('\n'.join(cases))

if not practice:
	output_file.close()
	print 'Closed output file...'
