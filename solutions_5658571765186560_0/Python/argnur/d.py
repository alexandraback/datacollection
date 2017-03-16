#!/usr/bin/env python
# -*- coding: utf-8 -*-

def solve(case):
	x, r, c = map(int, case.split())

	if r * c % x != 0:
		return "RICHARD"

	if x > r and x > c:
		return "RICHARD"

	if min(x / 2 + 1, x - x/2) > min(r, c):
		return "RICHARD"

	if min(r, c) < 3 and x == 4:
		return "RICHARD"

	if x > 6:
		return "RICHARD"

	return "GABRIEL"


if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(1, testcases+1):
        case = raw_input()
        print("Case #%i: %s" % (caseNr, solve(case)))