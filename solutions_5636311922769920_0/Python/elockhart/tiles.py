import sys
fi = sys.stdin
import numpy as np

def readint():
    return int(fi.readline())

def readints():
    return [int(X) for X in fi.readline().split()]

def idx(b, K):
    r = 0
    for B in b:
        r = r*K + B
    return 1+r

def sol(K,C,S):
    if C*S < K: return "IMPOSSIBLE"
    b = list(range(K)) + [0]*((C-K%C)%C)
    b = np.reshape(b, (-1,C))
    return " ".join([str(idx(B,K)) for B in b])

T = readint()
for I in range(T):
    K,C,S = readints()
    print("Case #" + str(1+I) + ": " + sol(K,C,S))


