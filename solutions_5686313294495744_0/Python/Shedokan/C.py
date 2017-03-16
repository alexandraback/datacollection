# -*- coding: utf-8 -*-
#
# Copyright 2013 Eric Shtivelberg
#

import sys

practice = False

problem = 'C-small-attempt0'

lines = '''3
4
HYDROCARBON COMBUSTION
QUAIL BEHAVIOR
QUAIL COMBUSTION
HYDROCARBON QUAIL
3
CODE JAM
SPACE JAM
PEARL JAM
2
INTERGALACTIC PLANETARY
PLANETARY INTERGALACTIC'''.split('\n')

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

def sort_topics(topics):
	topics = list(topics)
	part1s = [t[0] for t in topics]
	part2s = [t[1] for t in topics]
	for i in range(1, len(topics)):
		value = topics[i]
		p1, p2 = value

		p = i
		while p > 0 and p1 not in part1s[p-1:i] and p2 not in part2s[p-1:i]:
			# print p, topics[p-1], topics[p-1:i]
			topics[p] = topics[p-1]
			part1s[p], part2s[p] = topics[p-1]
			p -= 1

		topics[p] = value
		part1s[p], part2s[p] = value

	return topics

# The output list
output = []

T = read_int()
for t in range(1, T+1):
	N = read_int()
	topics = [tuple(read_parts()) for n in xrange(N)]

	old_topics = topics
	for i in xrange(10):
		topics = sort_topics(topics)
		if topics == old_topics:
			break

	part1s = [t[0] for t in topics]
	part2s = [t[1] for t in topics]

	fake = 0
	for i in xrange(len(topics)-1, -1, -1):
		p1, p2 = topics[i]
		if p1 in part1s[:i] and p2 in part2s[:i]:
			fake += 1

	output.append(str(fake))


########## Contest Specific End ##########

cases = ['Case #{}: {}'.format(i+1, output[i]) for i in range(len(output))]
output_file.write('\n'.join(cases))

if not practice:
	output_file.close()
	print 'Closed output file...'
