__author__ = 'alei'

import sys

r,t = None,None

sys.stdin = open('alarge.in')
sys.stdout = open('a.out',"w")


def solv(f, to):
    mid = (f+to)/2
    ev = 2*mid*mid + mid*(2*r-1)
    if ev==t: return mid
    else:
        if ev<t:
            m2 = mid+1
            fn = 2*m2*m2 + m2*(2*r-1)
            if fn>t: return mid
            else: return solv(mid,to)
        else:
            return solv(f,mid)


cases = int(sys.stdin.readline())
for i in range(cases):
    r, t = sys.stdin.readline().split()
    r = long(r)
    t = long(t)
    ans = solv(0,t)
    sys.stdout.write("Case #{0}: {1}\n".format(i+1,ans))
sys.stdout.close()