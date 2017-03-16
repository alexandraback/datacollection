import sys

casenum = 1
def doit(case):
    global casenum

    X, Y = [int(x) for x in case.split(' ')]

    ans = ""

    i = 1
    curx = 0
    cury = 0

    # print >> sys.stderr, 'TARGET (%d, %d)' % (X, Y)

    # Get to the correct X position
    while abs(curx - X) * 2 > i:
        if curx > X:
            ans += 'W'
            curx -= i
        else:
            ans += 'E'
            curx += i
        i += 1

        # print >> sys.stderr, '(%d, %d)' % (curx, cury)

    while curx != X:
        if curx > X:
            ans += 'EW'
            curx -= 1
        else:
            ans += 'WE'
            curx += 1
        i += 2

        # print >> sys.stderr, '(%d, %d)' % (curx, cury)

    # Get to the correct Y position
    while abs(cury - Y) * 2 > i:
        if cury > Y:
            ans += 'S'
            cury -= i
        else:
            ans += 'N'
            cury += i
        i += 1

        # print >> sys.stderr, '(%d, %d)' % (curx, cury)

    while cury != Y:
        if cury > Y:
            ans += 'NS'
            cury -= 1
        else:
            ans += 'SN'
            cury += 1
        i += 2

        # print >> sys.stderr, '(%d, %d)' % (curx, cury)

    if len(ans) > 500:
        print "FAIL"
        sys.exit(1)

    print 'Case #%d: %s' % (casenum, ans)
    casenum += 1

raw = [x.strip() for x in sys.stdin.readlines()]
ZZZ = int(raw[0])
data = raw[1:]
for case in range(ZZZ):
    doit(data[case])
