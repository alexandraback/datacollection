def solve_case(L):
    n, s = L.split()
    n = int(n)
    s = [int(c) for c in s]
    t = 0
    m = 0
    for i,si in enumerate(s):
        if t < i:
            m = max(i-t, m)
        t += si
    return m

def parse(f):
    ncase = int(f.readline())
    for i in range(ncase):
        print "Case #%d:"%(i+1),
        print solve_case(f.readline())

import sys
parse(sys.stdin)
