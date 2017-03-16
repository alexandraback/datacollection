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
	probs = getProbs(p)
	typeEnter = B + 2
	backspace = float('inf')
	for numBack in range(A):
		back = probBackspace(A, B, probs, numBack)
		if back < backspace:
			backspace = back
	return min(typeEnter, backspace)

def getProbs(p):
	probs = []
	if len(p) == 1:
		probs = [p[0], 1 - p[0]]
	elif len(p) == 2:
		probs = [p[0] * p[1], p[0] * (1 - p[1]), (1 - p[0]) * p[1], (1 - p[0]) * (1 - p[1])]
	elif len(p) == 3:
		probs = [
			p[0] * p[1] * p[2],
			p[0] * p[1] * (1 - p[2]),
			p[0] * (1 - p[1]) * p[2],
			p[0] * (1 - p[1]) * (1 - p[2]),
			(1 - p[0]) * p[1] * p[2],
			(1 - p[0]) * p[1] * (1 - p[2]),
			(1 - p[0]) * (1 - p[1]) * p[2],
			(1 - p[0]) * (1 - p[1]) * (1 - p[2])]
	return probs

def probBackspace(A, B, probs, numBack):
	keystrokes = []
	result = 0
	for i in range(len(probs)):
		if i == 0:
			numBackspacesNeeded = 0
		else:
			numBackspacesNeeded = math.floor(math.log(i, 2)) + 1
		if numBack < numBackspacesNeeded:
			keystrokes.append(numBack + numBack + B - A + 1 + B + 1)
		else:
			keystrokes.append(numBack + numBack + B - A + 1)
	for i in range(len(probs)):
		result += probs[i] * keystrokes[i]
	return result	


if __name__ == "__main__":
	import sys
	filename = sys.argv[1]
	lines = process_file(filename)
	lines = process_lines(lines)
	c = 0
	for line in lines:
		c += 1
		print "Case #%d: %s" % (c, process_case(line))