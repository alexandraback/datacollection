n = int(raw_input())
for i in range(n):
	print "Case #%d:"%(i+1),
	cookie = raw_input().split()
	for j in range(3):
		cookie[j] = float(cookie[j])
	farm = cookie[0]
	increase = cookie[1]
	goal = cookie[2]
	
	rate = 2.0
	time = []
	while goal/rate > farm/rate + goal/(rate+increase):
		each = farm/rate
		time.append(each)
		rate = rate + increase
	time.append(goal/rate)
	print "%.7f"%(sum(time))
	