#!/usr/bin/python

import sys

MAX = 1000

def solve(n):
	l = set(list('1234567890'))
	i = 1
	while (len(l) != 0 and i < MAX+1):
		dig = set(list(str(i*n)))
		for d in dig:
			l.discard(d)
		i += 1
	return ((i-1)*n)


def main():
	with open(sys.argv[1], 'r') as f:
		t = int(f.readline())
		for i in xrange(t):
			n = int(f.readline())
			res = solve(n)
			if (res == MAX*n):
				print('Case #%d: INSOMNIA' % (i+1))
			else:
				print('Case #%d: %d' % (i+1, res))

if __name__ == '__main__':
	main()
