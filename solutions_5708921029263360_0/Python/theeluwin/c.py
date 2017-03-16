# -*- coding: utf-8 -*-

from collections import defaultdict


def comb2str(comb):
	return ' '.join([str(item) for item in comb])


def solve(J, P, S, K):
	jph = defaultdict(lambda: 0)
	jsh = defaultdict(lambda: 0)
	psh = defaultdict(lambda: 0)
	combinations = []
	for j in range(1, J + 1):
		for p in range(1, P + 1):
			for s in range(1, S + 1):
				jp = comb2str([j, p])
				js = comb2str([j, s])
				ps = comb2str([p, s])
				if jph[jp] < K and jsh[js] < K and psh[ps] < K:
					combinations.append(comb2str([j, p, s]))
					jph[jp] += 1
					jsh[js] += 1
					psh[ps] += 1
	return '{}\n{}'.format(len(combinations), '\n'.join(combinations))


if __name__ == '__main__':
	outfile = open('c.out', 'w')
	T = int(input())
	for t in range(1, T + 1):
		J, P, S, K = [int(i) for i in input().split(' ')]
		ans = solve(J, P, S, K)
		outfile.write("Case #{}: {}\n".format(t, ans))
