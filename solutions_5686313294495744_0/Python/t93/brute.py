def log(fmt, *args):
    #return
    print fmt % tuple(args)

caches = []

def reset():
    for c in caches:
        c.clear()

def cached(f):
    cache = {}
    caches.append(cache)
    def wrapper(*args):
        k = tuple(args)
        if k in cache:
            return cache[k]
        else:
            v = f(*args)
            cache[k] = v
            return v
    return wrapper

@cached
def solve(pairs):
    ans = 0
    best_pair = -1, -1
    for (p1, p2, p1e, p2e) in pairs:
        count = -1
        rest = set([])
        for (q1, q2, q1e, q2e) in pairs:
            if p1e and q1 == p1:
                #assert q1e
                q1e = False
            #if not p1e and q1 == p1:
            #    assert not q1e
            if p2e and q2 == p2:
                #assert q2e
                q2e = False
            #if not p2e and q2 == p2:
            #    assert not q2e
            if q1e or q2e:
                rest.add((q1, q2, q1e, q2e))
            else:
                count += 1
        count += solve(frozenset(rest))
        ans = max(ans, count)
    return ans

def main():
    ts = int(raw_input())
    for ti in xrange(ts):
        reset()
        n = int(raw_input())
        pairs = frozenset([tuple(raw_input().split()) + (True,  True) for i in xrange(n)])
        ans = solve(pairs)
        print "Case #%d: %d" % (ti + 1, ans)

main()
