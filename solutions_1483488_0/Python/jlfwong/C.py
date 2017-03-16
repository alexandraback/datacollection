casenum = 1
def doit(case):
    global casenum

    A, B = [int(x) for x in case.split(' ')]

    counter = 0

    for n in xrange(A, B + 1):
        perms = set([n])

        for i in range(1, len(str(n))):
            m = int(str(n)[i:] + str(n)[:i])

            if len(str(n)) != len(str(m)):
                continue

            if m in perms:
                continue

            perms.add(m)

            if A <= n < m <= B:
                counter += 1

    print 'Case #%d: %d' % (casenum, counter)
    casenum += 1

raw = [x.strip() for x in open('C-small-attempt1.in').readlines()]
ZZZ = int(raw[0])
data = raw[1:]
for case in range(ZZZ):
    doit(data[case])
