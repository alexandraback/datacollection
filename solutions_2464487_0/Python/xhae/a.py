T = int(raw_input())
for i in range(T):
	print "Case #" + str(i + 1) + ":",
	inp = map(int, raw_input().split())
	s = 0
	e = inp[1]
	ans = 0
	while(True):
		mid = (s + e) / 2
		req = (2 * inp[0] + 1 + 2 * inp[0] + 1 + 4 * mid) * (mid + 1) / 2
		if(req <= inp[1]):
			s = ans = mid + 1
		else:
			e = mid
		if(s >= e):
			break
		
	print ans
