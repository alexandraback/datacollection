t = int(raw_input())

from collections import Counter
import itertools
def solve(x):
	ct = Counter(itertools.chain.from_iterable(x))

	ks = []
	for k,v in ct.items():
		if v%2==1:
			ks.append(k)

	return ' '.join(map(str,sorted(ks)))


for i in range(t):
	n = int(raw_input())
	xs = [[int(x) for x in raw_input().split()] for _ in range(2*n-1)]
	print 'Case #{}: {}'.format(i+1,solve(xs))




