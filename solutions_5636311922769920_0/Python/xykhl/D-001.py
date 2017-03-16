#! /usr/bin/env pypy
#
# small dataset: K = S (i.e. upper bound cases, if you get me..)

import sys

n = int(sys.stdin.readline().strip())

def solve(a):
    K, C, S = a
    step = K ** (C-1)
    pos = 1
    for i in xrange(K):
        sys.stdout.write(" " + str(pos))
        pos += step
    sys.stdout.write("\n")
    
for i in range(n):
    line = sys.stdin.readline().strip()
    a = [ int(x) for x in line.split(" ") ]
    sys.stdout.write("Case #{}:".format(i+1))
    solve(a)

