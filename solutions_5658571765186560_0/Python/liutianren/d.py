#!/usr/bin/python

import sys
import numpy as np


def solve(X,R,C):
	R,C = sorted([R,C])
	if X >= 7: 
		return False
	if R*C % X != 0:
		return False
	if X > 2*R:
		return False
	if X > 2*C:
		return False
	if X in {1,2,3}:
		return True
	if X == 4:
		if R <= 2:
			return False
		else:
			return True
	# if X == 3:

	# return True

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		X,R,C = map(int, sys.stdin.readline().split())
		print "Case #{}: {}".format(t+1, 'GABRIEL' if solve(X,R,C) else 'RICHARD')