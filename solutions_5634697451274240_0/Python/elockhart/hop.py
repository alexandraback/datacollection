import sys
fi = sys.stdin

def readint():
    return int(fi.readline())

def seq(S):
    return sum(1 if S[I] != S[I-1] else 0 for I in range(1,len(S)))

def f(S):
    i = 1 if S[0] == '+' else 0
    fc = seq(S)
    if fc%2 == i: fc += 1
    return fc

T = readint()
for C in range(T):
    S = fi.readline().strip()
    print("Case #" + str(1+C) + ": " + str(f(S)))

