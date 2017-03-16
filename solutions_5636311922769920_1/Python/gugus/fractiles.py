#!/usr/bin/python

from __future__ import print_function
import sys

def solve(k, c, s):
	if (k==1):
		print(" 1", end='')
		return
		
	j = 0
	while (j*c < k):
		tmp = 1
		i = j*c
		while (i < min((j+1)*c, k)):
			tmp += i*(k**((j+1)*c-(i+1)))
			i += 1
		print(" %d" % (tmp), end='')
		j += 1
		

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
				solve(k, c, s)
				print('', sep='')


if __name__ == '__main__':
	main()
