import sys
import math
import decimal

T = int(sys.stdin.readline())

for i in range(T):

    x, y = map(int, sys.stdin.readline().strip().split(' '))
    ans = ''

    if x > 0:
        ans += 'WE' * x
    elif x < 0:
        ans += 'EW' * (-x)

    if y > 0:
        ans += 'SN' * y
    else:
        ans += 'NS' * (-y)

    
    print "Case #" + str(i+1) + ": " + ans

