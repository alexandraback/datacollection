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
	problemFirst = True
	for line in lines:
		if first == True:
			first = False
		elif line == '':
			return ans
		elif problemFirst:
			if line != '':
				case = {}
				A = -1
				B = -1
				for num in line.split(' '):
					if A == -1:
						A = int(num)
					elif B == -1:
						B = int(num)
				case['A'] = A
				case['B'] = B
				problemFirst = False
		else:
			p = []
			for num in line.split(' '):
				p.append(float(num))
			case['p'] = p
			ans.append(case)
			problemFirst = True
	return ans

def process_case(line):
	A = line['A']
	B = line['B']
	p = line['p']
	typeEnter = B + 2
	backspace = probBackspace(A, B, p)
	return min(typeEnter, backspace)

def probBackspace(A, B, p):
	bestBack = sys.maxint
	probThatFirstCorrect = 1
	for i in range(1, A + 1):
		numBack = A - i
		probThatFirstCorrect *= p[i - 1]
		keystrokesIfFirstCorrect = numBack + numBack + B - A + 1
		keystrokesIfNotCorrect = numBack + numBack + B - A + 1 + B + 1
		back = probThatFirstCorrect * keystrokesIfFirstCorrect + (1 - probThatFirstCorrect) * keystrokesIfNotCorrect
		if back < bestBack:
			bestBack = back
	return bestBack

if __name__ == "__main__":
	import sys
	filename = sys.argv[1]
	lines = process_file(filename)
	lines = process_lines(lines)
	c = 0
	for line in lines:
		c += 1
		print "Case #%d: %s" % (c, process_case(line))