for t in xrange(input()):
    print "Case #%d:"%(t+1),
    j, p, s, k = map(int, raw_input().split())

    ans = []
    if s < k:
        # brute force
        for x in xrange(1, j+1):
            for y in xrange(1, p+1):
                for z in xrange(1, s+1):
                    ans.append(" ".join(map(str, [x, y, z])))
    else:
        make = lambda x, y: [[0]*y for i in xrange(x)]
        jp = make(j, p)
        js = make(j, s)
        ps = make(p, s)
        for x in xrange(j):
            for y in xrange(p):
                if jp[x][y] >= k:
                    continue
                for z in xrange(s):
                    if jp[x][y] >= k:
                        break
                    if js[x][z] >= k or ps[y][z] >= k:
                        continue
                    jp[x][y] += 1
                    js[x][z] += 1
                    ps[y][z] += 1
                    ans.append(" ".join(map(str, [x+1, y+1, z+1])))
    print len(ans)
    for e in ans:
        print e

