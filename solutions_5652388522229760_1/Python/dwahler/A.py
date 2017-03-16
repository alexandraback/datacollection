import sys

def solve(N):
	if N == 0:
		return "INSOMNIA"

	digits = set()
	current = 0
	while len(digits) < 10:
		current += N
		digits |= set(str(current))

	return str(current)

T = int(raw_input())

for testCase in xrange(1, T+1):
	N = int(raw_input())
	result = solve(N)
	print "Case #%d: %s" % (testCase, result)
