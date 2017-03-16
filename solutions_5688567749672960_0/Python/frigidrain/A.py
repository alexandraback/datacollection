import fileinput
import math
from collections import deque

def flip(n): 
    res = 0
    while(n > 0):
        digit = n%10
        res = res * 10 + digit
        n /= 10
    return res

def solve(n):

    res = 0
    while n > 19:

        # print n

        if n % 10 == 0:
            n -= 1
            res += 1
            continue

        length = len(str(n))
        secondhalf = n % (10**(length/2))
        # print secondhalf
        take = secondhalf - 1
        res += take
        n -= take
        
        # reverse if it helps
        rev = flip(n)
        if rev < n:
            n = rev
            res += 1

        # print n
        take = n % (10**(length - 1))
        res += take + 2
        n -= take + 2

    return res + n

f = fileinput.input()
T = int(f.readline())

for t in range(T):
    n = int(f.readline())
    solve(n)
    print "Case #{0}: {1}".format(t + 1, solve(n))
