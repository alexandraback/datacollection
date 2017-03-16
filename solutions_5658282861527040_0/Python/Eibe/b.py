#! /usr/bin/env python


# python 2.7
#usage: cat input | this_program > output

from __future__ import division
import sys
import math


if __name__ == "__main__"	:
	num_testcases = int(sys.stdin.readline())
	for case in range(1, num_testcases + 1):
		A, B, K = map(int, sys.stdin.readline().split())
		s = set(range(K))
		cnt = 0
		for a in range(A):
			for b in range(B):
				if a & b in s:
					cnt += 1
		print "Case #%i: %i" %(case, cnt)
