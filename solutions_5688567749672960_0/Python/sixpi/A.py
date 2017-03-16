#!/usr/bin/env python
import cPickle as pickle
import sys

"""To generate MIN_PATH, use:

MIN_PATH = {}
def make_path(N):
    x = N+1
    y = int(str(N)[::-1])
    MIN_PATH[x] = min(MIN_PATH[N]+1, MIN_PATH.get(x, 10**7))
    MIN_PATH[y] = min(MIN_PATH[N]+1, MIN_PATH.get(y, 10**7))
"""

MIN_PATH = pickle.load( open( "small_min_path.pickle", "rb" ) )
T = int(next(sys.stdin))

for i, l in enumerate(sys.stdin):
    N = int(l)

    print("Case #{0}: {1}".format(i+1, MIN_PATH[N]))
