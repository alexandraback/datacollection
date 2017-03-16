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


def sol1(S):
    sides = [0 if x=="-" else 1 for x in S]
    acc = 0
    flip = 0
    for x in sides[::-1]:
        if not x^flip:
            acc+=1
            flip = 1-flip
    return acc

if IS_LOCAL:
    # inp = iter(map(str,[5, "+++-", "--+-", "-++-", "-", "-+", "+-", "+++", "--+-"]))
    inp = sys.stdin
    # inp = open("B-small-attempt0.in")
else:
    inp = sys.stdin

T ,= read_ints(inp)
# T=1
mm = 0
for t in range(T):
    S =next(inp).strip()
    x = sol1(S)
    # if i>=mm:
    #     print(N,i,x)
    #     mm=i
    print("Case #%d: %s" % (t+1,x) )
