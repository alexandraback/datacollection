def solve(P, Q):
	n = 0
	rq = Q
	while rq % 2 == 0:
		n += 1
		rq = rq / 2

	if n == 0 or P % rq != 0:
		return None

	p = P / rq
	q = Q / rq

	while p % 2 == 0 and q % 2 == 0:
		p = p / 2
		q = q / 2

	# print '*** ', p, q

	for i in range(1, 41):
		if p * (2 ** i) >= q:
			return i

	return None


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
	P, Q = [int(w) for w in f.readline().strip().split('/')]
	res = solve(P, Q)
	if res is None:
		res = "impossible"
	print 'Case #%s: %s' % (t, res)
