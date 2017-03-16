import sys
from random import randint

from collections import Counter,deque
from itertools import combinations

IS_LOCAL = False
try:
    import os
    IS_LOCAL = os.getenv("AGLAE") == "nondual" and os.getenv("SIDONIE") == "improbable"
except:
    pass

def read_ints(inp = sys.stdin):
    return list(map(int,next(inp).strip().split()))

def brute(seq):
    return 0

def sol1(N):
    # tackle known case
    # !! warning Only tested for N<=10**7
    known = {0:(0,"INSOMNIA"), 2:(44,90)}
    if N in known:
        return known[N]
    mul = 1
    for k in range(6):
        if mul*125 == N:
            return (71,mul*9000)
        mul*=10

    # semi-naive for general case
    cc = Counter()
    x = N
    for i in range(45): # worst general case
        cc.update(str(x))
        if len(cc)==10:
            break
        x+=N
    else:
        return 0,"INSOMNIA"
    return i,x

if IS_LOCAL:
    # inp = iter(map(str,[1000000] + [x for x in range(100) if x not in {20}])) # {0,125,1250,12500,125000}]))
    inp = iter(map(str,[5, 0, 1, 2, 11, 1692]))
    inp = open("A-small-attempt0.in")
else:
    inp = sys.stdin

T ,= read_ints(inp)
# T=1
mm = 0
for t in range(T):
    N, =read_ints(inp)
    i, x = sol1(N)
    # if i>=mm:
    #     print(N,i,x)
    #     mm=i
    print("Case #%d: %s" % (t+1,x) )
