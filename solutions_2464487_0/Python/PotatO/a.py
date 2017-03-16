from decimal import *
def a(r, t):
    r = Decimal(r)
    t = Decimal(t)
    getcontext().prec = 50
    return int((1-2*r+(pow((2*r-1),2)+8*t).sqrt())/4)

if __name__ == '__main__':
    f = open('a-small.in')
    o = open('a-small.out', 'w')
    n = int(f.readline())
    for i in range(n):
        r, t = [int(c) for c in f.readline().split(' ')]
        o.write('Case #%d: %d\n' % (i+1, a(r, t)))
    o.close()
    f.close()

