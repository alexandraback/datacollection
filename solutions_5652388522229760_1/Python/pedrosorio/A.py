def get_digs(n):
	return set([c for c in str(n)])

def solve(n):
	if n == 0:
		return "INSOMNIA"
	digs = get_digs(n)
	v = n	
	while len(digs) != 10:
		v += n
		digs |= get_digs(v)
	return v	

T = int(raw_input())
for case in range(1, T+1):
	N = int(raw_input())
	print "Case #{}: {}".format(case, str(solve(N)))