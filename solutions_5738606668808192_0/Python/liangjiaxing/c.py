import itertools
re = int(raw_input())

for cas in range(re):
	print "Case #%d:" % (cas + 1)
	cnt = 0
	N, J = map(int, raw_input().split())
	org = '1' + '0'*(N-2) + '1'
	ans = [org]
	for i in range(2, N-1, 2):
		for j in range(1, N-1, 2):
			v = list(org)
			v[i] = '1'
			v[j] = '1'
			ans.append(''.join(v))

	for i in ans[:J]:
		print i,
		for j in range(3, 12):
			print j,
		print
