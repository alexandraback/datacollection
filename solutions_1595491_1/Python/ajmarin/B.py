cnt, t = 1, int(input())
while cnt <= t:
	args = list(map(int, input().split()))
	n, s, z = args[:3]
	scores = args[3:]
	r = sum(1 for x in scores if x > 3*(z - 1)) + min(s, sum(1 for x in scores if x > 1 and x < 29 and x >= 3*z - 4 and x <= 3*(z - 1)))
	print('Case #%d: %d' % (cnt, r))
	cnt += 1
	