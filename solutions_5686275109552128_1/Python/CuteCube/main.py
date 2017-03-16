#!/usr/bin/env python

def main():
	fin = open('input.txt', 'r')

	total_T = int(fin.readline())

	for T in xrange(1, total_T + 1):
		D = int(fin.readline().rstrip('\n'))
		P = map(int, fin.readline().rstrip('\n').split())
		P = sorted(P)

		r = max(P)
		for t in xrange(1, max(P) + 1):
			rr = sum((x-1)/t for x in P) + t
			r = min(rr, r)


		print 'Case #{}: {}'.format(T, r)



if __name__ == '__main__':
	main()