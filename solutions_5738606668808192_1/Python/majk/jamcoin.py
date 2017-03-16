import random
from math import sqrt

T=int(input())
N,J = map(int, input().split())

print('Case #1:')
for _ in range(J):
	v = random.randint(0, 2 ** (N//2-2))
	w = '11'
	for i in range(N//2-2):
		w += str(v % 2) + str(v % 2)
		v //= 2
	w += '11'
	proofs = range(3,12)
	print("%s %s" % (w, ' '.join(map(str, proofs))))
