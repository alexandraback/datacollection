# 

import math
import Queue
import copy

def solve(n, size, sizes):
	if len(sizes) == 0:
		return n

	while len(sizes) > 0 and size > sizes[0]:
		size += sizes[0]
		# print 'come', sizes[0], 'e fica:', size
		sizes = sizes[1:]

	if len(sizes) == 0:
		return n

	ss2 = solve(n+1, size, sizes[1:])

	if size > 1:
		ss1 = solve(n+1, size+size-1, sizes)
		# print ss1
	else:
		ss1 = ss2

	# print 'return:', n + len(sizes), ss
	# return min(n + len(sizes), solve(nc, size, sizes[1:]))
	return min(ss1, ss2)

def main():
	# fp = open('a.in')
	# fp = open('A-small-attempt3.in')
	fp = open('A-large.in')

	for case in xrange(int(fp.readline())):
		print case
		
		a, n = map(int, fp.readline().split())

		sizes = sorted(map(int, fp.readline().split()))
	
		if a == 1:
			result = len(sizes)
		else:
			result = solve(0, a, sizes)

		print 'Case #{0}: {1}'.format(case+1, result)

		# break

if __name__ == "__main__":
	main()
