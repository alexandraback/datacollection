import math
import sys

def main():
    N = sys.stdin.readline()
    N = int(N)
    for c in xrange(1,N+1):
        l = sys.stdin.readline()
        r, t = [long(x) for x in tuple(l.strip().split(' ')[:2])]
        A = 2
        B = 2 * r - 1
        C = -t
        count = (math.sqrt(B*B-4*A*C) - B) / (2*A)
        count = long(count) + 1
        while 1:
            tt = 2 * count * count + (2 * r - 1) * count
#            print tt, t
            if tt > t: 
                count-=1
            else: break
        print "Case #%d: %d"% (c, count)

if __name__ == '__main__':
    main()

