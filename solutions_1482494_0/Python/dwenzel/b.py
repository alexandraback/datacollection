#!/usr/bin/env python
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
	case = {}
	for line in lines:
		if first == True:
			first = False
		elif line == '':
			case['l'] = l
			ans.append(case)
			return ans
		elif len(line.split(' ')) == 1:
			if len(case) > 0:
				case['l'] = l
				ans.append(case)
			case = {}
			N = -1
			l = []
			for num in line.split(' '):
				if N == -1:
					N = int(num)
			case['N'] = N
			problemFirst = False
		else:
			count = 0
			for num in line.split(' '):
				if count == 0:
					x = int(num)
					count += 1
				else:
					y = int(num)
			l.append([x, y])

def process_case(line):
	N = line['N']
	l = line['l']
	curStars = 0
	completedLevels = 0
	numSteps = 0
	while completedLevels < N:
		s = step(curStars, l)
		if s[0] == 0:
			return "Too Bad"
		else:
			numSteps += 1
			curStars += s[0]
			index = s[1]
			l[index[0]][index[1]] = -1
			if index[1] == 1:
				l[index[0]][0] = -1
				completedLevels += 1
	return numSteps

def step(curStars, levels):
	improve = 0
	index = [-1, -1]
	maxSecond = -1
	for i in range(len(levels)):
		level = levels[i]
		if curStars >= level[1] and level[1] >= 0:
			index = [i, 1]
			if level[0] == -1:
				improve = 1
			else:
				return (2, index)
		elif curStars >= level[0] and level[0] >= 0 and index[1] != 1:
			if level[1] > maxSecond:
				improve = 1
				index = [i, 0]
				maxSecond = level[1]
	return (improve, index)

if __name__ == "__main__":
	import sys
	filename = sys.argv[1]
	lines = process_file(filename)
	lines = process_lines(lines)
	c = 0
	for line in lines:
		c += 1
		print "Case #%d: %s" % (c, process_case(line))