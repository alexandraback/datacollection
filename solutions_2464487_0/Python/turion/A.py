#! /usr/bin/python
# -*- coding: utf-8 -*-

import codejammer # https://bitbucket.org/turion/codejammer
codejammer.set_level(codejammer.DEBUG)

#import math
import decimal
decimal.getcontext().prec = 100

def solve_case(case):
	r, t = map(decimal.Decimal, case.split(" "))
	#n = math.sqrt(t/2+(r/2-1/4)**2) - (r/2-1/4)
	n = (t/2+(r/2-decimal.Decimal("0.25"))**2).sqrt() - (r/2-decimal.Decimal("0.25"))
	#codejammer.debug(n)
	#codejammer.debug(2*n**2 + n * (2*r-1))
	#codejammer.debug(n)
	return int(n)

test_in = """5
1 9
1 10
3 40
1 1000000000000000000
10000000000000000 1000000000000000000"""

test_solution = """Case #1: 1
Case #2: 2
Case #3: 3
Case #4: 707106780
Case #5: 49"""

codejammer.test_jam(test_in, test_solution, solve_case)
codejammer.jam("A",solve_case)
