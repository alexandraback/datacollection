# -*- coding: utf-8 -*-
#
# Copyright 2013 Eric Shtivelberg
#

import sys

practice = False

problem = 'A-large'

lines = '''4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER'''.split('\n')

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

digit_s = ('ZERO', 'SIX', 'FOUR', 'TWO', 'THREE', 'ONE', 'FIVE', 'SEVEN', 'EIGHT', 'NINE')
digit_map = {'ZERO': 0, 'ONE': 1, 'TWO': 2, 'THREE': 3, 'FOUR': 4, 'FIVE': 5, 'SIX': 6, 'SEVEN': 7, 'EIGHT': 8, 'NINE': 9}

def get_digits(S):
	digits = []
	for ds in digit_s:
		while all(l in S for l in ds):
			digits.append(digit_map[ds])
			for l in ds:
				S = S.replace(l, '', 1)

	assert not S
	return sorted(digits)

T = read_int()
for t in range(1, T+1):
	S = read_line()

	output.append(''.join(map(str, get_digits(S))))


########## Contest Specific End ##########

cases = ['Case #{}: {}'.format(i+1, output[i]) for i in range(len(output))]
output_file.write('\n'.join(cases))

if not practice:
	output_file.close()
	print 'Closed output file...'
