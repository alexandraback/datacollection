
from bigfloat import *

facttable = [1]

factmax = 1
for n in xrange(1, 1000):
    factmax *= n
    facttable.append(factmax)
assert facttable[3] == 6

def fact(n):
    return facttable[n]

def absolute(n):
    s = 0
    for i in xrange(0, 10 ** 6):
        s += 4 * i + 1
        if s > n:
            break
    return i, s - (4 * i + 1)

def solve(h, remain, x, y):
    d = (int(abs(x)) + y) / 2
    #print 'distance:', d, 'stackheight:', h
    if d < h:
        return 1.0
    if d > h:
        return 0.0
    if x == 0:
        return 0.0
    cy = y + 1 # required count to be selected
    #print 'required selection:', cy, '/', remain
    tot = 2 ** remain
    cot = tot
    for z in xrange(0, cy):
        v = fact(remain) / (fact(remain - z) * fact(z))
        cot -= v
        #print 'remove fact', remain, '/ fact', remain - z, ' as ', v
    #print 'tot:', tot, 'cot:', cot
    return 1.0 * cot / tot

if __name__ == '__main__':
    case_count = input()
    for xx in xrange(0, case_count):
        n, x, y = map(int, raw_input().split(' '))
        h, consumed = absolute(n)
        remain = n - consumed
        #print 'n, x, y, h, c, r:', n, x, y, h, consumed, remain
        rate = solve(h, remain, x, y)
        print 'Case #%d:' % (xx + 1), rate
        #print '----'
