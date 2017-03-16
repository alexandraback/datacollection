import sys
import math

def rl():
    return sys.stdin.readline().strip()

def main():
    T = int(rl())
    cons = set('bcdfghjklmnpqrstvwxyz')
    for i in range(1, T+1):
        L, n = rl().split()
        n = int(n)
        total = 0
        prev = 0
        for j in range(len(L)-n+1):
            if all(c in cons for c in L[j:j+n]):
                total += (j-prev+1)*(len(L)-j-n+1)
                prev = j+1
        print 'Case #%d: %s' % (i, total)

if __name__ == '__main__':
    main()
