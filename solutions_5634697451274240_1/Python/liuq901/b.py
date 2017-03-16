import numpy as np

def calc(a):
    if a.all():
        return 0
    pos = a.shape[0]
    for i in xrange(pos - 1):
        if a[i] != a[i + 1]:
            pos = i + 1
            break
    a[:pos] = 1 - a[:pos]
    return calc(a) + 1

T = int(raw_input())
for t in xrange(T):
    s = raw_input()
    a = np.zeros(len(s))
    for i in xrange(len(s)):
        if s[i] == '+':
            a[i] = 1
    print 'Case #%d: %d' % (t + 1, calc(a))
