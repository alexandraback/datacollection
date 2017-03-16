#!/usr/bin/env python
# -*- coding: utf-8 -*-

import math

def solve(d, p):
	p = map(int, p.split())
	p.sort(reverse=True)

	best_time = p[0]
	for i in range(p[0] - 1, 0, -1):
		wait_time = 0
		for j in range(len(p)):
			if p[j] > i:
				wait_time += int(math.ceil(p[j] * 1.0 / i)) - 1
		best_time = min(best_time, wait_time + i)

	return best_time


if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(1, testcases+1):
        d = raw_input()
        p = raw_input()

        print("Case #%i: %s" % (caseNr, solve(d, p)))