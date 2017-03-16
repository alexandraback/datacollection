T = int(raw_input())
for case in range(T):
	gives = 2
	time_for_build = 0
	C, F, X = map(float, raw_input().split())
	total = X / gives
	while True:
		time_for_build += C / gives
		gives += F
		my_total = time_for_build + X / gives
		if my_total < total:
			total = my_total
		else:
			break
	print "Case #" + str(case+1) + ":", "%.7f" % total