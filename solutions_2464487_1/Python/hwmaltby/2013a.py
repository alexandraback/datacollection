from math import sqrt, floor, ceil

f = open('A-large.in', 'r')

T = int(f.readline())

test = lambda n, r, t: (2*r - 3) * n + 2 * n * (n + 1) <= t

for i in range(T):
	r, t = map(int, f.readline().split())

	ans = floor(0.25 * (sqrt(8 * t + (2 * r - 1) * (2 * r - 1)) - (2 * r - 1)))

	while test(ans + 1, r, t):
		ans += 1

	while not test(ans, r, t):
		ans -= 1

	print("Case #" + str(i + 1) + ": " + str(ans))
