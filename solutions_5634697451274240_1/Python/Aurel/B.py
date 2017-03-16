T = int(raw_input())
for testId in range(T):
    v = [a == '+' for a in  raw_input()[::-1]]

    res = 0
    l = len(v)
    target = True
    needsFlip = False
    for i in xrange(l):
        if v[i] != target:
            needsFlip = True
        elif needsFlip:
            res += 1
            target = not target
    if needsFlip:
        res += 1

    print "Case #{:d}: {:d}".format(testId+1, res)
