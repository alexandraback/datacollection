#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math
def rec(vid, ship):
	if vid == ship:
		return vid # if euql return length
	return int(vid / ship)  + (ship - 1 if vid % ship == 0 else ship)
	# left = 9999999999
	# right = 9999999999
	# hit = 99999999
	# if math.ceil(vid / 2) >= ship: 
	# 	left = rec(math.ceil(vid / 2), ship)
	# if math.floor(vid / 2) >= ship: 
	# 	right = rec(math.floor(vid / 2), ship)
	# hit = min(1 + ship, math.floor(vid / 2) + math.ceil(vid / 2))
	# return int(min(hit, left, right))
	
def solve(data):
	data = data.split(" ")
	R = int(data[0])
	C = int(data[1])
	W = int(data[2])
	return rec(C, W)
if __name__ == "__main__":
    testcases = input()
    data = [] 
    for caseNr in xrange(1, testcases+1):
        data = raw_input()
        print("Case #%i: %s" % (caseNr, solve(data)))

# 1 10 3 
