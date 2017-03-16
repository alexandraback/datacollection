from collections import deque

def fun(x):
    total = len(x)*2
    d = deque([(0, 0, frozenset([]))])
    cache = set()
    while True:
        if not d:
            return 'Too Bad'
        stars, turns, done = d.pop()
        if done in cache:
            continue
        else:
            cache.add(done)
        for i, (a,b) in enumerate(x):
            if (i,1) not in done:
                if stars >= b:
                    get = 1 if (i,0) in done else 2
                    if stars+get == total: return turns+1
                    s = set(done)
                    s.add((i,1))
                    s = frozenset(s)
                    d.appendleft((stars+get, turns+1, s))
                elif stars >= a and ((i,0) not in done):
                    s = set(done)
                    s.add((i,0))
                    s = frozenset(s)
                    d.appendleft((stars+1, turns+1, s))
        del done


            
    return x

tests = int(raw_input())

for i in xrange(tests):
    n = int(raw_input())
    t = [tuple(map(int, raw_input().split(' '))) for j in xrange(n)]


    print 'Case #%s: %s'%(i+1, fun(t))
