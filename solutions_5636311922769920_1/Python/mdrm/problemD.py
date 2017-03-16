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

def pos(seq, K):
    return sum(a*(K**i) for i,a in enumerate(seq))+1

def sol1(K, C, S):
    res = []
    i = 0
    for _ in range(S):
        if i+C>K:
            seq=list(range(i,K)) + [0]*(i+C-K)
        else:
            seq=range(i,i+C)
        res.append(pos(seq,K))
        i+=C
        if i>=K:
            break
    else:
        return "IMPOSSIBLE"

    return " ".join(map(str,res))

if IS_LOCAL:
    # inp = iter(map(str,[6, "2 3 2", "1 1 1", "2 1 1", "2 1 2", "3 2 3", "100 9 50"]))
    # inp = open("A-small-attempt0.in")
    inp = sys.stdin
else:
    inp = sys.stdin

T ,= read_ints(inp)
# T=1
mm = 0
for t in range(T):
    K,C,S =read_ints(inp)
    x = sol1(K,C,S)
    # if i>=mm:
    #     print(N,i,x)
    #     mm=i
    print("Case #%d: %s" % (t+1,x) )
