T = input()
for t in range(1, T + 1):
	n, S = raw_input().split()
	p = 0
	ans = 0
	for i in range(0, int(n) + 1):
		if S[i] != '0':
			if i > p:
				ans += i - p
				p = i
			p += int(S[i])
	print "Case #%d: %d" % (t, ans)