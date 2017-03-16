# 

import math
import Queue
import copy

def solve(name, n):
	start = 0
	i = 0
	r = 0
	result = 0

	while i < len(name):
		if name[i] not in 'aeiou':
			r += 1
			if r >= n:
				# print i+1,n,start,(i+1-n-start+1),(len(name)-i)
				result += (i+1-n-start+1)*(len(name)-i)
				start = i-n+2
		else:
			r = 0

		i += 1

	return result

def main():
	# fp = open('a.in')
	fp = open('A-small-attempt2.in')
	# fp = open('A-large.in')
	# fp = open('A-small-practice.in')
	# fp = open('A-large-practice.in')

	for case in xrange(int(fp.readline())):
		name, n = fp.readline().split()
		n = int(n)

		# print name, n

		result = solve(name, n)

		print 'Case #{0}: {1}'.format(case+1, result)

if __name__ == "__main__":
	main()
