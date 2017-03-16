def G(prefs):
    pmap = {i+1: p for i, p in enumerate(prefs)}
    r = len(set(prefs))
    for x in set(prefs):
        c = 0
        for k, v in pmap.iteritems():
            if x == v:
                c += 1
        if c > 1:
            r -= 1
    return r

def g(prefs):
    pmap = {i+1: p for i, p in enumerate(prefs)}
    r = 0
    best = None
    for k in pmap.iterkeys():
        chain = []
        chain.append(k)
        chain.append(pmap[k])
        prev = pmap[k]
        while True:
            n = pmap[prev]
            if n in chain:
                flag = True
                for j in pmap.iterkeys():
                    if j in chain:
                        continue
                    if pmap[j] == prev:
                        chain.append(j)
                        prev =j
                        flag = False
                if flag:
                    break
            else:
                chain.append(n)
                prev = n
            last_linked = 1
            for i, link in enumerate(chain):
                if pmap[link] == chain[i-1] or pmap[link] == chain[(i+1) % len(chain)]:
                    continue
                else:
                    last_linked = 0
                    break
            if (len(chain)-(1-last_linked)) > r:
                r = len(chain)
                best = chain
    return max(1, len(best or []))


h = open('c_out.txt', 'w')
f1 = 'test.txt'
f2 = 'csmall.in'

with open(f2, 'r') as f:
    T = int(f.readline())
    i = 0
    while i < T:
        N = int(f.readline())
        prefs = [int(x) for x in f.readline().strip().split()]
        r = g(prefs)
        print 'Case #%s: %s' %(i+1, r)
        h.write('Case #%s: %s\n' %(i+1, r))
        i += 1

