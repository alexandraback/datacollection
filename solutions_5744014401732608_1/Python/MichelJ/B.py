"""
Code Jam 2016 Round 1C 2016
Problem B. Slides!
"""

from __future__ import print_function
import sys
import StringIO
from functools import partial
from autolog import logfunction

msg = partial(print, file=sys.stderr)

#===========================================================================

import numpy as np
from itertools import izip

def compute(net, B):
    count = np.zeros((B), dtype=np.int32)
    count[B-1] = 1
    for s in xrange(B-2, -1, -1):
        for t in xrange(s+1, B):
            if net[s,t] == 1:
                count[s] += count[t]
    return count

def doit(B, M):
    msg(B, M)
    N = B-1
    if M > 2**(N-1):
        return "IMPOSSIBLE"
    net = np.zeros((B,B), dtype=np.int32)
    logM1 = len(bin(M-1)) - 2
    if M==1:
        logM1 = 0
    for i in xrange(N - logM1,N):
        net[i,i+1:] = 1
    bits = bin(M-1)[-1:1:-1]
    msg(bits)
    for i, bit in enumerate(bits):
        if bit=="1":
            net[0,N - i - 1] = 1
    net[0, N] = 1
    msg(net)
    count = compute(net, B)
    msg(count)
    if count[0] != M:
        msg("*** Wrong! ***")
    out = "\n".join("".join(str(net[i,j]) for j in xrange(B)) for i in xrange(B))
    return "POSSIBLE\n" + out


sample = """3
5 4
2 1
4 20
"""

test = """1
3
1 2 3
2 3 5
3 5 6
2 3 4
1 2 3
"""

def samp():
    main(sample)

#===========================================================================

def stripnl(s):
    if s[-1]=="\n":
        return s[:-1]
    return s

def main(data = None):
    if data is None:
        f = sys.stdin
    else:
        f = StringIO.StringIO(data)
    nt = int(f.readline())
    for tc in xrange(1, nt+1):
        B, M = map(int, stripnl(f.readline()).split(" "))
        res = doit(B, M)
        msg( "Case #%d: %s" % (tc, res) )
        print( "Case #%d: %s" % (tc, res) )

main()
