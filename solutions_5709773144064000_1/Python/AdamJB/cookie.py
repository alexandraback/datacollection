#!/usr/bin/env python

def cookie(cookies, case):	
	c = cookies[0]
	f = cookies[1]
	x = cookies[2]

	cookiesPerSecond = 2.0

	totalTimeForCookiesFarm = 0.0
	# Start with worst case?
	lastTimeTotal = x / cookiesPerSecond
	
	while (1):
		# Increase last total time to buy farm
		totalTimeForCookiesFarm += c / cookiesPerSecond
		# Boost Speed after farm is bought
		cookiesPerSecond = cookiesPerSecond + f
		
		# See if we're getting slower or faster in producing cookies
		currentTotalTime = (x / cookiesPerSecond) + totalTimeForCookiesFarm
		if currentTotalTime < lastTimeTotal:
			lastTimeTotal = currentTotalTime
		else:
			break

	print("Case #%d: %.7f" % (case, lastTimeTotal))

	
numCases = int(input())

for case in range(0, numCases):
	cookies = [float(i) for i in raw_input().strip().split()]
	# print cookies
	cookie(cookies, case+1)
