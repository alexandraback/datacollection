from itertools import product
from itertools import permutations
from copy import deepcopy

T = input()

for qw in xrange(1, T+1):
	print "Case #%d: " % qw,

	J, P, S, K = [int(x) for x in raw_input().split(" ")]

	prod = product(range(1,J+1), range(1,P+1), range(1,S+1))

	mlen = 0
	mposs = []
	i = 0
	for poss in permutations(prod):
		outp = []
		matrix = [[0 for x in xrange(J+P+S)] for x in xrange(J+P+S)]

		for c in poss:
			if K not in [matrix[c[0]-1][c[1]+J-1],matrix[c[0]-1][c[2]+J+P-1],matrix[c[1]+J-1][c[2]+J+P-1]]:
				outp.append(c)
				matrix[c[0]-1][c[1]+J-1] += 1
				matrix[c[0]-1][c[2]+J+P-1] += 1
				matrix[c[1]+J-1][c[2]+J+P-1] += 1
		if len(outp) > mlen:
			mlen = len(outp)
			mposs = deepcopy(outp)
		i+=1
		if i >= 50000:
			break
	outp = mposs


	print "%d" % len(outp)
	for x in outp:
		print " ".join([str(a) for a in x])