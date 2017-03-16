#!/usr/bin/python
import sys
import numpy as np     # http://www.numpy.org/
import scipy           # http://scipy.org/
import networkx as nx  # https://networkx.github.io/
import sympy           # http://www.sympy.org

N = int(sys.stdin.readline().strip())

def solvable(X,R,C):

    if (R*C) % X != 0: return False  # Never can be OK
    if X==1: return True # Any X=1 is solvable, regardless of R and C
    if X==2: return True
    # X==1,X==2 are finished

    # Checked by hand
    if X==3:
	if (R,C) == (1,1): return False
	if (R,C) == (1,2): return False
	if (R,C) == (1,3): return False
	if (R,C) == (1,4): return False
	if (R,C) == (2,1): return False
	if (R,C) == (2,2): return False
	if (R,C) == (2,3): return True
	if (R,C) == (2,4): return False
	if (R,C) == (3,1): return False
	if (R,C) == (3,2): return True
	if (R,C) == (3,3): return True
	if (R,C) == (3,4): return True
	if (R,C) == (4,1): return False
	if (R,C) == (4,2): return False
	if (R,C) == (4,3): return True
	if (R,C) == (4,4): return False

    if X==4:
	if (R,C) == (1,1): return False
	if (R,C) == (1,2): return False
	if (R,C) == (1,3): return False
	if (R,C) == (1,4): return False
	if (R,C) == (2,1): return False
	if (R,C) == (2,2): return False
	if (R,C) == (2,3): return False
	if (R,C) == (2,4): return False
	if (R,C) == (3,1): return False
	if (R,C) == (3,2): return False
	if (R,C) == (3,3): return False
	if (R,C) == (3,4): return True
	if (R,C) == (4,1): return False
	if (R,C) == (4,2): return False
	if (R,C) == (4,3): return True
	if (R,C) == (4,4): return True

    assert(False)
    return True

for case in range(0, N):
    X,R,C = map(int, sys.stdin.readline().strip().split())

    solution = "GABRIEL" if solvable(X,R,C) else "RICHARD"
    print "Case #%i: %s" % (case + 1, solution)

