import random
from math import sqrt

T=int(input())
N,J = map(int, input().split())

while J > 0:
	v = random.randint(0, 2 ** (N-2))
	w = '1' + str("{0:b}".format(v)).zfill(N-2) + '1'
	proofs = []
	for b in range(2,11):
		n=int(w,b)
		ok=False
		for q in range(2,int(sqrt(n))):
			if n % q == 0:
				proofs.append(q)
				ok = True
				break
		if not ok:
			break
	if ok:
		print("%s %s" % (w, ' '.join(map(str, proofs))))
		J -= 1
