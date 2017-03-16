def solve():
    c, f, x = map(float, raw_input().split())
    r = int(x/c)
    d = [c/(2+i*f) for i in xrange(r+1)]
    for i in xrange(1, len(d)):
        d[i] += d[i-1]
    for i in xrange(len(d)):
        d[i] += x/(2+(i+1)*f)
    return min(d + [x/2.0])

def main():
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%s: %.7f' % (i, solve())

if __name__ == '__main__':
    main()
