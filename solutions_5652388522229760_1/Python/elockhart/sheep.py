import sys
fi = sys.stdin
import numpy as np

def readint():
    return int(fi.readline())

def sol(N):
    if N == 0: return "INSOMNIA"
    seen = set()
    last = 0
    while len(seen) < 10:
        last = last + N
        seen |= set(str(last))
    return str(last)

T = readint()
for I in range(T):
    N = readint()
    print("Case #" + str(1+I) + ": " + sol(N))


