# -*- coding: utf-8 -*-
#
# Copyright 2013 Eric Shtivelberg
#

import sys

practice = False

problem = 'B-small-attempt3'

lines = '''4
1? 2?
??0 ??6
1? 2?
?2? ??3
? ?
?5 ?0'''.split('\n')

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

def num(S):
	return long(S.replace('?', '0'))


T = read_int()
for t in range(1, T+1):
	C, J = read_parts()

	print C, J
	C_num, J_num = num(C), num(J)
	diff = abs(C_num - J_num)
	l = len(C)
	for i in xrange(l):
		if C[i] != '?' and J[i] != '?':
			continue

		power = 10**(l-i-1)
		C_to_power = C_num - C_num % power
		J_to_power = J_num - J_num % power

		if C[i] == '?' and J[i] == '?':
			if diff <= power*0.5:
				C = C.replace('?', '0', 1)
				J = J.replace('?', '0', 1)
				continue

			best_diff = diff
			best_n = 0
			best_C = True
			for n in xrange(1, 10):
				new_diff = abs(C_num - J_num - n*power)
				if new_diff < best_diff:
					best_diff = diff
					best_n = n
					best_C = False

				new_diff = abs(C_num + n*power - J_num)
				if new_diff >= best_diff:
					continue

				best_diff = new_diff
				best_n = n
				best_C = True

			if not best_C:
				J_num += best_n*power
				J = J.replace('?', str(best_n), 1)
				C = C.replace('?', '0', 1)
			else:
				C_num += best_n*power
				C = C.replace('?', str(best_n), 1)
				J = J.replace('?', '0', 1)
				
			new_diff = abs(C_num - J_num)
			# print C, J
			assert new_diff <= diff, (new_diff, diff)

			diff = abs(C_num - J_num)
			continue

		best_x = 0
		best_diff = diff
		if C[i] == '?':
			x = int(J[i])

			if C_to_power < J_to_power:
				# if i+1 < l and J[i+1] == '?':
					# best_x = x
				# else:
				for x in xrange(x+1 if x < 9 else 9, x-2 if x > 0 else x-1, -1):
					new_diff = abs(C_num + x*power - J_num)
					print 'x=', x, new_diff
					print new_diff, C_num+x*power, J_num
					if new_diff <= best_diff:
						best_x = x
						best_diff = new_diff

				if not best_x:
					best_x = x
				# assert best_x

			C = C.replace('?', str(best_x), 1)
			C_num += best_x*power

			new_diff = abs(C_num - J_num)
			assert new_diff <= diff, (new_diff, diff)
		else:
			x = int(C[i])

			if J_to_power <= C_to_power:
				# if i+1 < l and C[i+1] == '?':
					# best_x = x
				# else:
				for x in xrange(x+1 if x < 9 else 9, x-2 if x > 0 else x-1, -1):
					# print 'x=', x
					new_diff = abs(C_num - J_num - x*power)
					# print new_diff, C_num, J_num+x*power
					if new_diff <= best_diff:
						best_x = x
						best_diff = new_diff

				if not best_x:
					best_x = x
				# assert best_x

			J = J.replace('?', str(best_x), 1)
			J_num += best_x*power

			new_diff = abs(C_num - J_num)
			assert new_diff <= diff, (new_diff, diff)
			# print abs(J_num - C_num)

		new_diff = abs(C_num - J_num)
		assert new_diff <= diff, (new_diff, diff)
		diff = new_diff

	if '?' in C or '?' in J:
		print diff, C, J, C_num, J_num
		assert False

	output.append('{} {}'.format(C, J))


########## Contest Specific End ##########

cases = ['Case #{}: {}'.format(i+1, output[i]) for i in range(len(output))]
output_file.write('\n'.join(cases))

if not practice:
	output_file.close()
	print 'Closed output file...'
