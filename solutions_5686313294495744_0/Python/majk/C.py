from collections import *

T=int(input())
for t in range(T):
    N=int(input())
    F,S=[],[]
    for _ in range(N):
        f,s=input().split()
        F.append(f)
        S.append(s)
    FC=len(set(F))
    SC=len(set(S))
    B=0
    for i in range(2**(max(FC,SC))-1,2**N):
        FX,SX=set(),set()
        R=0
        I=0
        while i > 0:
            if i % 2 == 1:
                FX.add(F[I])
                SX.add(S[I])
                R += 1
            i //= 2
            I += 1
            if len(FX) == FC and len(SX) == SC:
                B=max(B,N-R)
    print("Case #%d: %d" % (t+1, B))

