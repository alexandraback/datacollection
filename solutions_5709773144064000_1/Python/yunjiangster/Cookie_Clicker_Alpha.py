import sys
problems=[]
for i,line in enumerate(sys.stdin):
    if i==0:    n = int(line.strip('\r\t\n '))
    else:
        problems.append(line.strip('\r\t\n '))
assert len(problems) == n
template='Case #%d: %.7f'
for i,p in enumerate(problems):
    [C,F,X] = [float(t) for t in p.split(' ')]
    t=0
    m=0
    r=2
    while m < X:
        nextbuy=(C-m)/r
        t2finish=(X-m)/r
        if t2finish < nextbuy: 
            m = X
            t += t2finish
        else:
            m = C
            t += nextbuy
            t2finishnobuy = (X-m)/r
            t2finishifbuy = X/(r+F) 
            if t2finishnobuy > t2finishifbuy:
                r+=F
                m = 0
            else:
                m=X
                t += t2finishnobuy
    print template%(i+1,t)
            
