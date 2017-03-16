
T = input()
for i in range(T):
	K,C,S = map(int, raw_input().split())
	if C == 1:
		ans = '1'
	if K == 1:
		ans = '1'
	else:
		ans = ' '.join(map(str, range(1,K+1)))
	print 'Case #%s: %s' % (i+1, ans)
