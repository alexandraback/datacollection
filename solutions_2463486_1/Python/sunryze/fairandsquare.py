# fairandsquare

import re
import sys

## {{{ http://code.activestate.com/recipes/577821/ (r1)
def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y
## end of http://code.activestate.com/recipes/577821/ }}}

def nextpal(n):
    if n < 10: 
        return (n+1 if n<9 else 11)
    s = str(n)
    h = s[:len(s)/2]
    if len(s) % 2 == 0:
        p = long(h+h[::-1])
        if p > n:
            return p
        else:
            h2 = str(long(h) + 1)
            if len(h2) > len(h): # 99...9 case
                return 10**len(s)+1
            return long(h2+h2[::-1])
    else:
        c = s[len(s)/2]
        p = long(h+c+h[::-1])
        if p > n:
            return p
        else:
            h2 = str(long(h+c) + 1)
            if len(h2) > len(h) + 1: # 99...9 case
                return 10**len(s)+1
            return long(h2+h2[:-1][::-1])


def fairandsquare(filename):
    def ispal(n):
        s = str(n)
        return s == s[::-1]
    with open(filename) as f_in:
        total = int(f_in.readline())
        for i in range(total):
            a, b = map(long, f_in.readline().strip().split(' '))
            # Count number of fair and square numbers >= a, <= b
            ra = isqrt(a)
            rb = isqrt(b)
            j = ra - 1
            count = 0
            while j <= rb:
                j = nextpal(j)
                if ispal(j*j) and j*j >= a and j*j <= b:
                    count += 1
            print 'Case #{0}: {1}'.format(i+1, count)
            
if __name__ == "__main__":
    fairandsquare(sys.argv[1])
