#!/usr/bin/env python
import math
def main():
    f = open('input.txt', 'r')
    total_T = int(f.readline())
    #print total_T
    for T in xrange(1,total_T+1):
        r,t = f.readline().split()
        r = long(r)
        t=long(t)

        # 2k^2 + (2r - 1)k - t = 0
        b = 2*r -1.0
        a = 2.0
        c = -t
        k = (-b + math.sqrt(b*b - 4*a*c))/2/a

        # k = 1
        k = long(k)
        while not (need(k ,r) <= t and need(k+1, r) > t):
            if need(k, r) < t:
                k += 1
            else:
                #k = max(long(k/2)+1, long(k*0.75))
                k -= 1




        print "Case #{}: {}".format(T, long(k))

def need(k,r):
    return 2*k*k + (2*r-1)*k 

if __name__ == '__main__':
    main()