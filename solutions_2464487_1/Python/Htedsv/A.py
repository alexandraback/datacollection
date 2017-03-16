import math
T = 0
for x in open('data.in').readlines():
    T += 1
    if T == 1: continue
    inp = x.split(' ')
    r = int(inp[0])
    t = int(inp[1])
    s = 0
    left, right = 1, 1000000000
    while left+1 < right:
        mid = (left+right)/2
        if (r+r+2*mid-1)*mid <= t: 
            left = mid
        else:
            right = mid
    print 'Case #%d: %d'%(T-1, left)




