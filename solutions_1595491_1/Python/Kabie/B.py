#!/usr/bin/env python
# -*- coding: utf-8 -*=

NS = {}
for i in range(31):
    d,m = divmod(i,3)
    s = min(10, i,  d + (2 if m==2 else 1))
    n = min(10, i,  d + (1 if m else 0))
    NS[i]= n, s

def solve(S, p, t):
    t = list(map(NS.get, t))
    x = 0
    for n, s in t:
        if n>=p:
            x+=1
        elif s>=p and S:
            x+=1
            S-=1
    return x

if __name__ == '__main__':

    OUT = open('B-large.out','w')
    IN = open('B-large.in').__next__
    T = range(1, int(IN())+1)
    for case in T:
        N, S, p, *t =map(int, IN().split())
        result = solve(S, p, t)
        print("Case #{}: {}".format(case, result), file=OUT)
        print("Case #{}: {}:{}".format(case, result, [S,p,t]))
