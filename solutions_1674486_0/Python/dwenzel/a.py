#!/usr/bin/env python
import math
from collections import deque

def process_file(file):
	fsock = open(file)
	text = fsock.read()
	fsock.close()
	lines = text.split('\n')
	return lines


def process_lines(lines):
	ans = []
	first = True
	N = -1
	n = 0
	s = {}
	for line in lines:
		if first == True:
			first = False
		elif N == -1:
			if line != '':
				case = {}
				N = -1
				s = {}
				for num in line.split(' '):
					if N == -1:
						N = int(num)
				case['N'] = N
				n = 1
			else:
				return ans
		elif len(s) < N:
			lineFirst = False
			for num in line.split(' '):
				if not lineFirst:
					lineFirst = True
				else:
					if not s.has_key(n):
						s[n] = []
					s[n].append(int(num))
			n += 1
			if n > N:
				case['s'] = s
				ans.append(case)
				N = -1
	return ans

def process_case(line):
	N = line['N']
	s = line['s']
	for key in s.keys():
		if hasDiamond(key, s):
			return 'Yes'
	return 'No'

def hasDiamond(key, s):
	visited = set()
	q = deque([])
	q.append(key)
	visited.add(key)
	while len(q) > 0:
		v = q.popleft()
		if s.has_key(v):
			neighbors = s[v]
			for n in neighbors:
				if n in visited:
					return True
				else:
					visited.add(n)
					q.append(n)
	return False

if __name__ == "__main__":
	import sys
	filename = sys.argv[1]
	lines = process_file(filename)
	lines = process_lines(lines)
	c = 0
	for line in lines:
		c += 1
		print "Case #%d: %s" % (c, process_case(line))