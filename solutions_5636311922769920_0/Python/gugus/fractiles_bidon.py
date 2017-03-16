#!/usr/bin/python

from __future__ import print_function
import sys

def main():
	with open(sys.argv[1], 'r') as f:
		t = int(f.readline())
		for i in xrange(t):
			line = f.readline()
			k, c, s = [int(num) for num in line.split()]
			if (s*c < k):
				print("Case #%d: IMPOSSIBLE" % (i+1))
			else:
				print("Case #%d:" % (i+1), end='')
				for j in xrange(1, s+1):
					print(" %d" % (j), sep='', end='')
				print('', sep='')


if __name__ == '__main__':
	main()

