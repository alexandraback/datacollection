import sys
# https://pypi.python.org/pypi/bintrees/2.0.2
from bintrees import FastAVLTree

def construct(src = None):
    return FastAVLTree(src)

def push(S, i, x):
    if i not in S:
        S[i] = 0
    S[i] += x

def isempty(S):
    return len(S) == 0

def maxkey(S):
    return S.max_key()

def popmax(S):
    x = maxkey(S)
    Sx = S[x]
    del S[x]
    return (x, Sx)

T = int(sys.stdin.readline())
for _c in range(T):
    D = int(sys.stdin.readline())
    line = sys.stdin.readline().strip()
    P = map(int, line.split(" "))
    Smaster = construct()
    for x in P:
        push(Smaster, x, 1)

    mintime = maxkey(Smaster)

    for eattime in xrange(1, maxkey(Smaster) + 1):
        S = construct(Smaster)
        n = 0
        while maxkey(S) > eattime:
            (x, Sx) = popmax(S)
            push(S, eattime, Sx*(x/eattime))
            n += Sx*(x/eattime - 1)
            if x % eattime != 0:
                push(S, x % eattime, Sx)
                n += Sx
        mintime = min(mintime, n + maxkey(S))
        #print S, n + maxkey(S)
    print "Case #%d: %d" % (_c + 1, mintime)
