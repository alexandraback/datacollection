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

def make_mat(B,x):
    first = [1] * (B)
    res = []
    b = 1
    for i in range(B):
        first[i] = 0
        first[B-1] = (x & b)//b
        res.append(first[:])
        b*=2
    return [''.join(map(str,r)) for r in res]

def sol1(B,M):
    if M>2**(B-2):
        return "IMPOSSIBLE"
    elif M==2**(B-2):
        res = make_mat(B,M*2-1)
    else:
        res = make_mat(B,M*2)
    return "POSSIBLE\n" + '\n'.join(res)


if IS_LOCAL:
    inp = iter("""3
5 8
2 1
4 20
""".split('\n'))
    # inp = iter(map(str,[6, "2 3 2", "1 1 1", "2 1 1", "2 1 2", "3 2 3", "100 9 50"]))
    # inp = open("A-small-attempt0.in")
    inp = sys.stdin
else:
    inp = sys.stdin

T ,= read_ints(inp)
# T=1
mm = 0
for t in range(T):
    B,M =read_ints(inp)
    x = sol1(B,M)
    # if i>=mm:
    #     print(N,i,x)
    #     mm=i
    print("Case #%d: %s" % (t+1,x) )
