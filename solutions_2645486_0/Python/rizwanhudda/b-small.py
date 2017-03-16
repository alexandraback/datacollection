cache = { }


def max_gain(cidx, e):
	if cidx == N:
		return 0
	if (cidx, e) in cache:
		return cache[(cidx, e)]
	ans = 0
	for e_ca in range(0, e+1):
		ans = max(ans, \
				max_gain(cidx+1, min(e - e_ca + R, E)) + e_ca*v[cidx])
	cache[(cidx, e)] = ans
	return ans

T = input()
for case_no in range(1, T+1):
	E, R, N = map(int, raw_input().split())
	v = map(int, raw_input().split())
	cache = {}
	print 'Case #%i: %i' % (case_no, max_gain(0,E))