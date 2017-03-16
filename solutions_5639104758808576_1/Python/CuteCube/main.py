#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1, total_T + 1):
		Smax, Sn = f.readline().rstrip('\n').split()
		Smax = int(Smax)

		F = 0
		A = int(Sn[0])
		for x in xrange(1, Smax + 1):
			if A < x:
				F += x - A
				A = x + int(Sn[x])
			else:
				A += int(Sn[x])

		
		print 'Case #{}: {}'.format(T, F)

		

if __name__ == '__main__':
	main()