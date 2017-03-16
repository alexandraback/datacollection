import sys





t = int(sys.stdin.readline())

for case in range(1, t+1):
	
	C, F, X  = map(float, sys.stdin.readline().split())

	min_complete_time = X / 2.0
	delay = 0
	rate  = 2

	#
	while True:
		delay += C/rate
		rate  += F
		complete_time = delay + X/rate

		if min_complete_time < complete_time:
			break 

		min_complete_time = complete_time

	print "Case #{0}: {1}".format(case, min_complete_time)
	
