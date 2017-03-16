T = int(raw_input())

for case in xrange(1,T+1):
    n = int(raw_input())
    m = (2*n)-1

    res = []

    for l in xrange(m):
        numbers = map(int,raw_input().split())

        for number in numbers:
            if number in res:
                res.remove(number)
            else:
                res.append(number)
    res.sort()
    result = " ".join("%d" % c for c in res)

    print "Case #%d: %s" % (case, result)
