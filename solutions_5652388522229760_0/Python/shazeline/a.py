

def q(num):
	orig_N = num
	N = num

	seen_digs = set()
	seen_nums = set()

	i = 1
	ans = 'INSOMNIA'

	while True:
		# print N, seen_nums, seen_digs
		if N in seen_nums:
			break
		strn = str(N)
		digs = set(x for x in str(N))
		seen_digs |= digs
		seen_nums.add(N)
		if len(seen_digs) == 10:
			ans = N
			break
		N += orig_N

	return ans

tot = input()
for i in range(tot):
	num = input()
	ans = q(num)
	print 'CASE #%s: %s' % (i+1, ans)