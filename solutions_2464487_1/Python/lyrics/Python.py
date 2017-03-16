import sys

def main():
    cin = lambda: map(int, raw_input().split())
    T = int(raw_input())
    for i in xrange(T):
        [R, T] = cin()
        ans, l, r = 0, 0, T/(2*R)+100
        while l <= r:
            m = (l+r)/2
            used = m*(2*R+2*m-1)
            if used > T:
                r = m-1
            else:
                l = m+1
                ans = m
        print "Case #%d:" % (i+1),
        print ans

if __name__ == '__main__':
    f1 = open('aaa.in', 'r')
    f2 = open('aaa.out', 'w')
    sys.stdin = f1
    sys.stdout = f2
    main()
    f1.close()
    f2.close()
