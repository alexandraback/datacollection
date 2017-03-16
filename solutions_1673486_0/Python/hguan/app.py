import sys

def do_case(k):
    f = sys.stdin
    line = f.readline()
    n = int(line.split(' ')[0])
    l = int(line.split(' ')[1])
    line = f.readline()
    p = map(lambda x:float(x), line.strip().split(' '))
    q = [1]
    for i in xrange(1, n + 1):
        r = q[i - 1] * p[i - 1]
        q.append(r)
    e1 = q[n] * (l + 1) + (1 - q[n]) * (l + 1 + l + 1) - n
    e2 = []
    for i in xrange(1, n + 1):
        r = q[n - i] * (l + 1 + 2 * i) + (1 - q[n - i]) * (l + 1 + 2 * i + l + 1) - n
        e2.append(r)
    e3 = 1 + l + 1
    print 'Case #%d: %.6f' % (k, min(e1, min(e2), e3))

def main():
    f = sys.stdin
    line = f.readline()
    T = int(line.strip())
    for i in xrange(T):
        do_case(i + 1)


if __name__ == '__main__':
    main()
