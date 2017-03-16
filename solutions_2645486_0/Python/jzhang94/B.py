import sys

T = int(sys.stdin.readline())

def gain(maxE, E, R, N, v, i, base_gain, memo):
	key = (E, i, base_gain)
	if key in memo:
		return memo[key]
	if i == N:
		return base_gain
	max_ = 0
	max_j = 0
	for j in range(E+1):
		spend_j = gain(maxE, min(maxE, E - j + R), R, N, v, i + 1, base_gain + j * v[i], memo)
		if spend_j > max_:
			max_ = spend_j
			max_j = j
	memo[key] = max_
	return max_

for i in range(1, T+1):
	E, R, N = [int(x) for x in sys.stdin.readline().split()]
	v = [int(x) for x in sys.stdin.readline().split()]
	memo = {}
	print "Case #" + str(i) + ": " + str(gain(E, E, R, N, v, 0, 0, memo))
