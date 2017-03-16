T = int(raw_input())
for case in range(1, T + 1):
	c, f, x = map(float, raw_input().split())
	
	ans = x / 2.0
	curTime = 0.0
	curEarn = 2.0

	while True:
		curTime += c / curEarn
		curEarn += f
		
		curAns = x / curEarn + curTime
		if curAns < ans:
			ans = curAns
		else:
			break
	
	print "Case #" + str(case) + ": " + str(ans)
