from math import sqrt, floor

from sys import setrecursionlimit

setrecursionlimit(2000)

f = open('B-large.in', 'r')

T = int(f.readline())

test = lambda n: n * (2 * n - 1)

perm = lambda n, k: 1 if k == 0 else n * perm(n - 1, k - 1)
binom = lambda n, k: perm(n, k) / perm(k, k)

def prob(m, k, h):
	if k > m:
		return 0.0
	elif m >= h + k:
		return 1.0
	else:
		ans = 0
		while k <= m:
			ans += binom(m, k)
			k += 1
		ans = ans / pow(2, m)
		return ans

for i in range(T):
	N, x, y = map(int, f.readline().split())

	h, y1 = floor((1 + sqrt(8 * N + 1)) / 4), (abs(x) + y) // 2

	while test(h + 1) < N:
		h += 1

	while test(h) > N:
		h -= 1

	if h > y1:
		ans = 1.0
	elif h < y1 or x == 0:
		ans = 0.0
	else:
		ans = prob(N - test(y1), y + 1, 2*h)

	print(("Case #" + str(i + 1) + ": " + str(ans)))
