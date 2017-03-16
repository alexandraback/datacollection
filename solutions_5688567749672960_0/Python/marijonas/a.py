from collections import deque
import sys

def rv(n):
    q = 0
    while n:
        q = q * 10 + (n % 10)
        n /= 10
    return q

def go(n):
    found = set([1])
    di = {}
    q = deque([(1, 1)])
    #prev = {}
    while len(di) < n:
        v, d = q.popleft()
        if v <= n:
            di[v] = d
        for new in [v+1, rv(v)]:
            if new not in found:
                found.add(new)
                q.append((new, d+1))
                #prev[new] = v
    '''while v in prev:
        print v,
        if v != prev[v] + 1:
            print '^',
        v = prev[v]
    print v'''
    return zip(*sorted(di.items()))[1]

u = go(10**6)
t = int(sys.stdin.readline())
for i in xrange(1, t+1):
    x = int(sys.stdin.readline())
    print 'Case #%d: %d' % (i, u[x-1])
