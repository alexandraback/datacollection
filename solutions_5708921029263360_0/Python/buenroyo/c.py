for t in xrange(1, int(raw_input()) + 1):
    (J, P, S, K) = map(int, raw_input().strip().split(' '))
    
    res = []

    JPs = {}
    JSs = {}
    PSs = {}

    for j in xrange(1, J + 1):
        for p in xrange(1, P + 1):
            for s in xrange(1, S + 1):
                jp = str(j) + str(p)
                js = str(j) + str(s)
                ps = str(p) + str(s)
                if jp not in JPs: JPs[jp] = 0
                if js not in JSs: JSs[js] = 0
                if ps not in PSs: PSs[ps] = 0
                if JPs[jp] == K: continue
                if JSs[js] == K: continue
                if PSs[ps] == K: continue
                JPs[jp] += 1
                JSs[js] += 1
                PSs[ps] += 1
                res.append(str(j) + " " + str(p) + " " + str(s))
    
    print "Case #%d: %d"% (t, len(res))
    for r in res:
        print r
