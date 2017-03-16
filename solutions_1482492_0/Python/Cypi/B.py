#! /usr/bin/python
# -*-coding:Utf-8 -*

from decimal import *

half = Decimal(0.5)

def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())

T_ = readint()
for t_ in range(T_):
    print 'Case #'+str(t_+1)+':',
    
    D, N, A_ = readarray(Decimal)
    N = int(round(N))
    A_ = int(round(A_))
    T = []
    X = []
    V = []
    for i in range(N):
        t, x = readarray(Decimal)
        T.append(t)
        X.append(x)
        if i > 0:
            V.append((X[i] - X[i-1]) / (T[i] - T[i-1]))
    A = readarray(Decimal)
    print
    
    i = N-1
    while i>=0 and X[i] > D:
        i -= 1
    if X[i] < D:
        N = i+2
        T[i+1] = (D - X[i]) / V[i] + T[i]
        X[i+1] = D
    else:
        N = i+1
    for a in A:
        dist = 0
        v = 0
        for i in range(N-1):
            t = T[i+1] - T[i]
            d = v*t + half*a*t*t
            if dist+d > X[i+1]:
                tmp = t - (2*(X[i+1]-dist-t*v)/a).sqrt()
                dist += v*(t-tmp)+(t-tmp)*(t-tmp)*a/2
                v += (t - tmp)*a
            else:
                dist += d
                v += a*t
        time = T[N-1]
        if dist < D:
            time += (-v+(v*v+2*a*(D-dist)).sqrt())/a
        elif dist > D:
            time -= (-v+(v*v-2*a*(dist-D)).sqrt())/a
        print time

