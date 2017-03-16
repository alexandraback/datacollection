import sys

T = int(sys.stdin.readline())

def rec(sizes, A, n):
	if len(sizes) == 0:
		return n
	elif A == 1:
		return len(sizes)

	for i in range(0, len(sizes)):
		if sizes[i] >= A:
			removeRest = n + len(sizes[i:])
			addPill = rec(sizes[i:], 2*A - 1, n + 1)

			return min(removeRest, addPill)
		else:
			A += sizes[i]
			
	return n

for i in range(1, T+1):
	A, N = map(int, sys.stdin.readline().split())

	sizes = map(int, sys.stdin.readline().split())
	sizes.sort()

	print("Case #%s: %s" % (i, rec(sizes, A, 0)))
