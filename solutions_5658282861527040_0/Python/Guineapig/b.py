def solve(A, B, K):
	count = 0
	for a in range(A):
		for b in range(B):
			if a & b < K:
				count += 1
	return count


################################################################################


def read_ints(f):
	return [int(w) for w in f.readline().strip().split()]

def read_int(f):
	return int(f.readline().strip())


from sys import argv, setrecursionlimit

# setrecursionlimit(2200)

f = open(argv[1])

T = read_int(f);

for t in range(1, T+1):
	A, B, K = read_ints(f)
	res = solve(A, B, K)
	print 'Case #%s: %s' % (t, res)
