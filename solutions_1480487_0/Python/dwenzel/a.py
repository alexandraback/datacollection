#!/usr/bin/env python
import math

def process_file(file):
	fsock = open(file)
	text = fsock.read()
	fsock.close()
	lines = text.split('\n')
	return lines


def process_lines(lines):
	ans = []
	first = True
	for line in lines:
		if first == True:
			first = False
		else:
			if line != '':
				case = {}
				N = -1
				s = []
				for num in line.split(' '):
					if N == -1:
						N = int(num)
					else:
						s.append(int(num))
				case['N'] = N
				case['s'] = s
				ans.append(case)
	return ans

def process_case(line):
	N = line['N']
	s = line['s']
	total = 0.0
	ans = []
	for score in s:
		total += score
	unsafe = 0
	unsafeTotal = 0
	for score in s:
		if score <= 2 * total / N:
			unsafeTotal += score
			unsafe += 1
	finalTotal = unsafeTotal + total
	finalGoal = finalTotal / unsafe
	#print finalTotal
	#print finalGoal
	#print unsafe
	for score in s:
		if score > 2 * total / N:
			ans.append(str(0))
		else:
			ans.append(str(100 * (finalGoal - score) / total))
	return ' '.join(ans)

if __name__ == "__main__":
	import sys
	filename = sys.argv[1]
	lines = process_file(filename)
	lines = process_lines(lines)
	c = 0
	for line in lines:
		#print line
		c += 1
		print "Case #%d: %s" % (c, process_case(line))