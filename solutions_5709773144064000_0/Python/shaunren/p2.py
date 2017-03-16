#!/usr/bin/python3 -SOO
for case in range(1,int(input())+1):
    c,f,x = map(float,input().strip().split())
    t,r = 0.0,2.0
    best = x/2
    while t<best:
        t += c/r
        r += f
        best = min(best, t + x/r)
        #print(t,r)
        
    print('Case #%d:'%case, '%.7f'%best)
