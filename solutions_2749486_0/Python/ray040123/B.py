xd = {1: 'WE', -1: 'EW', 0: ''}
yd = {1: 'SN', -1: 'NS', 0: ''}

def sgn(x):
    if x > 0: return 1
    elif x < 0: return -1
    else: return 0
def go(x, y):
    return xd[sgn(x)] * abs(x) + yd[sgn(y)] * abs(y)
tot = int(raw_input())
for t in xrange(tot):
    x, y = map(int, raw_input().split())
    print 'Case #%d: %s'%(t + 1, go(x, y))
