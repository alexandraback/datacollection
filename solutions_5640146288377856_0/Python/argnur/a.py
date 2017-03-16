#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math

def solve(case):
	r, c, w = map(int, case.split())
	score = (c / w) * r + w - 1
	if c % w > 0:
		score += 1
	return score


if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(1, testcases+1):
        case = raw_input()
        print("Case #%i: %s" % (caseNr, solve(case)))