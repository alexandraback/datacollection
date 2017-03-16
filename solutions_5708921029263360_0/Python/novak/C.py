import numpy
import itertools

test_cases = int(raw_input())
for test_case in xrange(1, test_cases + 1):
	J, P, S, K = [int(x) for x in raw_input().split(' ')]

	outfit = numpy.ones((J, P, S))
	j_p = numpy.zeros((J, P)); j_p.fill(K)
	j_s = numpy.zeros((J, S)); j_s.fill(K)
	p_s = numpy.zeros((P, S)); p_s.fill(K)

	l = []

	while j_p.any() or j_s.any() or p_s.any() or outfit.any():
		old_len = len(l)

		for j, p, s in itertools.product(range(J), range(P), range(S)):
			if outfit[j][p][s] > 0 and j_p[j][p] > 0 and j_s[j][s] > 0 and p_s[p][s] > 0:
				outfit[j][p][s] -= 1
				j_p[j][p] -= 1
				j_s[j][s] -= 1
				p_s[p][s] -= 1

				l.append((j + 1, p + 1, s + 1))

		if len(l) == old_len:
			break

	print 'Case #{}: {}'.format(test_case, len(l))
	for j, p, s in l:
		print '{} {} {}'.format(j, p, s)