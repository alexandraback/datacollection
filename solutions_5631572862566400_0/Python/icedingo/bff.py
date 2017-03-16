T = int(input())

class Pair(object):
    def __init__(self, a, b, ap, bp):
        self.a = a
        self.b = b
        self.ap = ap
        self.bp = bp

    def get_longest(self, pairs, rev, seen):
        #print('Getting longest for', self)
        alen = 0
        for p in self.ap:
            if p == self.b:
                continue
            seena = set()
            nex = [p]
            _alen = 0
            while nex:
                _alen += 1
                _nex = []
                for n in nex:
                    seena.add(n)
                    for c in rev[n]:
                        if c not in seena:
                            _nex.append(c)
                nex = _nex
            if _alen > alen:
                alen = _alen

        blen = 0
        for p in self.bp:
            if p == self.a:
                continue
            seenb = set()
            nex = [p]
            _blen = 0
            while nex:
                _blen += 1
                _nex = []
                for n in nex:
                    seenb.add(n)
                    for c in rev[n]:
                        if c not in seenb:
                            _nex.append(c)
                nex = _nex
            if _blen > blen:
                blen = _blen

        #print('  A chain', alen)
        #print('  B chain', blen)

        seen.add(self)
        submax = 0
        for p in pairs:
            #print('  Checking', p)
            if p in seen:
                #print('  -- NAH')
                continue
            _submax = p.get_longest(pairs, rev, seen)
            if _submax > submax:
                submax = _submax
        seen.remove(self)
        #print('ret!')
        if seen:
            return 2 + max(submax, alen, blen)
        else:
            return 2 + max(submax + alen, submax + blen, alen + blen)

    def __str__(self):
        return 'Pair<{}, {}>'.format(self.a, self.b)

for t in range(1, T+1):
    N = int(input())
    bffs = [int(i) - 1 for i in input().split()]
    rev = [[] for i in range(N)]
    for c, b in enumerate(bffs):
        rev[b].append(c)
    
    pairs = set()
    pairtuples = set()
    max_len = 0
    #print(bffs)
    for n in range(N):
        current = bffs[n]
        seen = set()
        while current not in seen:
            seen.add(current)
            #print(current, 'bff of', end = ' ')
            current = bffs[current]
            #print(current)
        if n not in seen:
            #print(n, 'not in cycle :(')
            continue
        lseen = len(seen)
        if lseen == 2:
            #print(seen, 'are a pair!')
            ptuple = tuple(sorted(seen))
            if ptuple not in pairtuples:
                a = seen.pop()
                b = seen.pop()
                pairs.add(Pair(a, b, rev[a], rev[b]))
                pairtuples.add(ptuple)
        if lseen > max_len:
            #print('new circle!', seen)
            max_len = lseen

    for p in pairs:
        plen = p.get_longest(pairs, rev, set())
        if plen > max_len:
            max_len = plen

    print('Case #{}: {}'.format(t, max_len))

