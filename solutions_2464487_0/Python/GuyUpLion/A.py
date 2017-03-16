from math import *

T = eval(input())
for tc in range(1, T + 1) :
    R, t = map(int, input().split(' '))
    l, r = 1, int(1e18)

    while l < r :
        x = (l + r + 1) // 2
        if (2 * R + 2 * x - 1) * x <= t :
            l = x
        else :
            r = x - 1

    print('Case #%d: %d' % (tc, l))
    
