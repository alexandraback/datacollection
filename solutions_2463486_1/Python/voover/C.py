#!/usr/bin/env python
fairandsquare = []
def check(s):
    x = int(s) * int(s)
    xs = str(x)
    if xs == xs[::-1]:
        fairandsquare.append(x)

for i in range(1,10**5):
    a = str(i)
    b = a[::-1]
    check(a + b)
    for j in range(0,10):
        check(a + str(j) + b)    

for i in range(1,10):
    check(str(i))
        
fairandsquare = sorted(fairandsquare)

def get(a,b):
    result = 0
    for t in fairandsquare:
        if (t >= a) and (t <= b):
            result += 1
    return result

T = input()
for i in range(1,T+1):
    (a,b) = map(int, raw_input().split())
    print 'Case #{0}: {1}'.format(i,get(a,b))
