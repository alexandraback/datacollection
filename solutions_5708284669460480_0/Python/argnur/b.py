#!/usr/bin/env python
# -*- coding: utf-8 -*-

def solve(case, k, l):
	count = {}
	K, L, S = map(int, case.split())
	for letter in list(k):
		if letter in count:
			count[letter] += 1
		else:
			count[letter] = 1

	chance = 1.0
	for letter in list(l):
		if letter in count:
			chance *= count[letter] * 1.0 / K
		else:
			chance = -1
			break
	if chance == -1:
		return 0.0

	for i in range(1, L+1):
		m = l[:i]
		good = True
		for j in range(1, max(2, L / i)):
			if m.find(l[j*i:(j+1)*i]) == -1:
				good = False
				break
		if good:
			break

	bananas = (S - L) / len(m) + 1
	return bananas - bananas * chance


if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(1, testcases+1):
        case = raw_input()
        k = raw_input()
        l = raw_input()
        print("Case #%i: %s" % (caseNr, solve(case, k, l)))