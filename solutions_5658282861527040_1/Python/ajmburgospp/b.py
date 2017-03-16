from functools import wraps

t = int(raw_input())
sa = []
sb = []
sk = []

def conv(x):
    ls = []
    while x:
        ls.append(x%2)
        x /= 2
    return ls

def memo(f):
    cache = {}
    @wraps(f)
    def g(*args):
        targs = tuple(args)
        if targs not in cache:
            cache[targs] = f(*args)
        return cache[targs]
    return g

cache = {}
maxlen = None
def F(n, da, db):
    if n < 0:
        return 1
    targs = (n, da, db)
    if targs not in cache:
        nda = sa[n] == 1 or da
        ndb = sb[n] == 1 or db
        cache[targs] = 0
        if sk[n] == 1:
            # If we set sa[n] = 0 and sb[n] = 0
            cache[targs] += C(n-1, nda, ndb)
            # sa = 1, sb = 0
            if sa[n] == 1 or da:
                cache[targs] += C(n-1, da, ndb)
            # sa = 0, sb = 1
            if sb[n] == 1 or db:
                cache[targs] += C(n-1, nda, db)
            # all to 1
            if (sa[n] == 1 or da) and (sb[n] == 1 or db):
                cache[targs] += F(n-1, da, db)
        else:
            # All 0
            cache[targs] += F(n-1, nda, ndb)
            # sa = 1, sb = 0
            if sa[n] == 1 or da:
                cache[targs] += F(n-1, da, ndb)
            # sa = 0, sb = 1
            if sb[n] == 1 or db:
                cache[targs] += F(n-1, nda, db)
    return cache[targs]

def C(n, da, db):
    if n < 0:
        return 1
    ca, cb = 0, 0
    for i in xrange(n, -1, -1):
        ca = 2*ca + sa[i]
        cb = 2*cb + sb[i]
    if da:
        ca = 2**(n+1)-1
    if db:
        cb = 2**(n+1)-1
    return (ca+1)*(cb+1)



for kei in xrange(t):
    cache = {}
    sa, sb, sk = [conv(int(x)-1) for x in raw_input().split()]
    maxlen = max(len(x) for x in [sa, sb, sk])
    for l in [sa, sb, sk]:
        while len(l) < maxlen:
            l.append(0)
    print 'Case #%d: %d' % (kei+1, F(maxlen-1, False, False))
    



