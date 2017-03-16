n = int(raw_input())
for ii in xrange(n):
    raw_input()
    bf = map(lambda x: x-1, map(int, raw_input().split()))
    m = {}
    bchain = [-1 for i in range(len(bf))]

    def getchain(i, s):
        if i in s:
            return -1000000
        if bchain[i] == -1:
            s = set(s)
            s.add(i)
            if i in m:
                bchain[i] = max([getchain(x, s) for x in m[i]]) + 1
            else:
                bchain[i] = 0
        return bchain[i]

    for i, v in enumerate(bf):
        if v in m:
            m[v].append(i)
        else:
            m[v] = [i]
    best = 0
    for i in xrange(len(bf)):
        if i == bf[bf[i]] and bf[i] > i:
            ch = getchain(i, set([bf[i]]))
            if ch > 0:
                best += ch
            ch = getchain(bf[i], set([i]))
            if ch > 0:
                best += ch
            best += 2
            
    for i in xrange(len(bf)):
        cur = i
        first = cur
        s = set([cur])
        while bf[cur] not in s:
            cur = bf[cur]
            s.add(cur)
        if bf[cur] == first:
            best = max([len(s), best])
    print "Case #%d: %d" % (ii+1, best)