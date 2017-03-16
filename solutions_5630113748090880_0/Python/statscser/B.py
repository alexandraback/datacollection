out = open('outputB_s.txt', 'w')
with open('B-small-attempt1.in', 'r') as f:
	T = int(f.readline())
	for i in range(1, T+1):
		out.write('Case #%s: ' % i)
		N = int(f.readline())
		count = {}
		for j in range(2*N-1):
			nums = f.readline().strip().split()
			for k in nums:
				k = int(k)
				count[k] = count.get(k, 0) + 1

		res = []
		for num in count:
			if count[num] % 2 != 0:
				res += [num]
		res = sorted(res)
		ans = ''
		for k in range(len(res)):
			ans = ans + str(res[k]) + ' '
		ans = ans.strip()

		out.write('%s\n' % ans)

out.close()
