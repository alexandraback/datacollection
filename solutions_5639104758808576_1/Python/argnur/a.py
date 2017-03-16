#!/usr/bin/env python
# -*- coding: utf-8 -*-

def solve(case):
	smax, s = case.split()
	smax = int(smax)

	people = 0
	friends = 0
	for i in xrange(smax+1):
		invites = max(i-people, 0)
		people += invites + int(s[i])
		friends += invites
	return friends


if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(1, testcases+1):
        cipher = raw_input()
        print("Case #%i: %s" % (caseNr, solve(cipher)))