
es = set([2**i for i in xrange(1, 41)])

def cal(x, y, c):
    if x*2 >= y:
        return c
    return cal(2*x, y, c+1)

def gcd(x, y):
    if x % y == 0:
        return y
    return gcd(y, x%y)

def solve():
    x, y = map(int, raw_input().split('/'))
    g = gcd(y, x)
    x /= g
    y /= g
    if y not in es:
        return 'impossible'
    return cal(x, y, 1)

def main():
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%s: %s' % (i, solve())

if __name__ == '__main__':
    main()
