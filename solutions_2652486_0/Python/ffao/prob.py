import copy
N = 3
M = 5
R = 100

def fac(n):
    r = 1
    while n:
        r *= n
        n -= 1
    return r

def gen(number, sum):
    if number == 1:
        yield [sum]
        return

    for x in xrange(sum+1):
        for y in gen(number-1, sum-x):
            yield y + [x]

prod = {}
occ = {}

def product(l):
    x = 1
    for x in l: r*=x
    return x
    
def calc(l):
    r = fac(len(l))
    for x in l:
        r /= fac(x)
    return r

def to_list(cnt):
    r = []
    i = 2
    for x in cnt:
        r.extend([i] * x)
        i += 1
    return tuple(r)

def prodsubs(l, pr):
    if not l:
        if pr not in prod: prod[pr] = {}
        prod[pr][lst] = prod[pr].get(lst,0) + 1

    else:
        prodsubs(l[1:], pr)
        prodsubs(l[1:], pr*l[0])

for cnt in gen(M-1, N):
    lst = to_list(cnt)
    occ[lst] = calc(cnt)
    prodsubs(lst, 1)

print "Case #1:"
raw_input()
raw_input()
for x in xrange(R):
    subs = map(int,raw_input().split())
    t = copy.copy(prod[subs[0]])
    for k in subs[1:]:
        for s in t:
            t[s] *= prod[k].get(s, 0)

    for s in t:
        t[s] *= occ[s]

    l = list(t.keys())
    l.sort(key=lambda x:t[x])
    print "".join(map(str,l[-1]))
