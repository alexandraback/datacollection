
import math

def testcase(tc):
    print 'Case #%s:' % tc

    (d, n, a) = raw_input().split()

    d = float(d)
    n = int(n)
    a = int(a)

    t = [0]*n
    x = [0]*n
    for i in range(n):
        ts, xs = raw_input().split()
        t[i] = float(ts)
        x[i] = float(xs)

    acc = [float(s) for s in raw_input().split()]

    for a in acc:
        res = math.sqrt(2 * d / a)
        if n > 1:
            m = x[1] / t[1]
            t_ovr = ( m + math.sqrt(m**2 + 2*a*x[0]) ) / a
            if t_ovr < res:
                res = t[1] * (d - x[0]) / (x[1] - x[0])
        print res

def main():
    t = int( raw_input() )
    for i in range(t):
        testcase(i+1)

if __name__ == '__main__':
    main()
