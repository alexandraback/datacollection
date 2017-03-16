#!/usr/bin/python3

T = int(input())

for case in range(1, T + 1):
    C, D, V = map(int, input().split())
    den = map(int, input().split())   
    denoms = set() 
    for c in den:
        olddenoms = denoms.copy()
        for d in olddenoms: denoms.add(c + d)
        denoms.add(c)    
    ans = 0
    for v in range(1, V+1):
        if not (v in denoms):
            ans += 1
            olddenoms = denoms.copy()
            for c in olddenoms: denoms.add(c + v)
            denoms.add(v)
    print("Case #%d: %d" % (case, ans))
