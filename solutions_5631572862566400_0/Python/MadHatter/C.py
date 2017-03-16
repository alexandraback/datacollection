__author__ = 'dkopiychenko'


from itertools import chain, combinations

def power_set(l):
    return chain.from_iterable(combinations(l, r) for r in range(len(l),0,-1))

def ch(p,x,l,d):
    r = set([p])
    ny = p
    while True:
        y = ny
        ny = l[y-1]
        r.add(ny)
        if l[ny-1] == y:
            return r,0
        if l[ny-1] == p:
            return r,1
        if l[ny-1] in r:
            return r,2


def check(x,l):
    d = {p:[] for p in x}
    for p in x:
        y = l[p-1]
        if y not in d: return False
        d[y].append(p)
    for k,v in d.items():
        if len(v) > 2: return False
        if len(v) == 2:
            if l[k-1] not in v: return False
    for p in x:
        r,b = ch(p,x,l,d)
        if b == 1:
            if len(r) < len(x): return False
            else: return True
    return True

def solve(n,l):
    for x in power_set(list(xrange(1,n+1))):
        if check(x,l):
            #print x
            return len(x)
    return 0


t = int(raw_input())
for i in xrange(t):
    n = int(raw_input().strip())
    l = map(int,raw_input().strip().split())
    print 'Case #' + str(i+1) + ': ' + str(solve(n,l))