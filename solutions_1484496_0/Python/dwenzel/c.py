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
	sum = {}
	f = lambda x: [[y for j, y in enumerate(set(x)) if (i >> j) & 1] for i in range(2**len(set(x)))]
	subsets = f(s)
	for subset in subsets:
		total = 0
		str_subset = []
		for n in subset:
			total += n
			str_subset.append(str(n))
		if sum.has_key(total):
			return '\n' +  ' '.join(sum[total]) + '\n' + ' '.join(str_subset)
		else:
			sum[total] = str_subset
	return '\nImpossible'

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