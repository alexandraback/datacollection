#!/usr/bin/env python

from collections import Counter

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		J,P,S,K = map(int, f.readline().rstrip('\n').split())
		res = list(helper(J, P, S, K))





		print 'Case #{}: {}'.format(T, len(res))
		for r in res:
			print r

def helper(J, P, S, K):
	police = Counter()
	for j in xrange(1, J+1):
		for p in xrange(1, P+1):
			for s in xrange(1, S+1):
				if police[('JP', j, p)] >= K:
					continue
				elif police[('JS', j, s)] >= K:
					continue
				elif police[('PS', p, s)] >= K:
					continue
				else:
					police[('JP', j, p)] += 1
					police[('JS', j, s)] += 1
					police[('PS', p, s)] += 1
					yield '{} {} {}'.format(j, p, s)
					



if __name__ == '__main__':
	main()