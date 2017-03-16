# -*- coding: utf-8 -*-

# start of common segment

import sys

with open(sys.argv[1].strip()) as fp:
	INPUT_LINES = map(str.strip, fp.readlines())

# end of common segment

NCASES = int(INPUT_LINES[0])
del INPUT_LINES[0]

for CASE_N in xrange(1, NCASES+1):
	C, F, X = map(float, INPUT_LINES[0].split())
	del INPUT_LINES[0]

	mytime = 0.0 # exact time after starting game in the while loop
	myrate = 2.0 # initial rate
	
	while True:
		# run till the end
		time_to_go = X / myrate

		# buy another cookie
		time_if_buy = C / myrate + X / (myrate + F)

		if time_to_go > time_if_buy:
			mytime += C / myrate
			myrate += F
		else:
			mytime += time_to_go
			break;

	print("Case #%d: %.7f" % (CASE_N, mytime))
