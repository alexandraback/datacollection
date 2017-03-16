import sys

casenum = 1
def doit(case):
    global casenum

    J = [int(x) for x in case.split(' ')[1:]]
    sumJ = sum(J)

    def get_score(i, y_i):
        return J[i] + sumJ * (y_i / 100.0)

    def guarantees(i, y_i):
        leftover = 100.0 - y_i
        curscore = get_score(i, y_i)

        for j in range(len(J)):
            if i == j:
                continue

            y_j = 100.0 * (curscore - J[j]) / sumJ

            if y_j <= leftover:
                if y_j > 0:
                    leftover -= y_j
            else:
                return True

        if leftover > 0:
            return False
        else:
            return True


    print 'Case #%d:' % (casenum),
    casenum += 1

    for i in range(len(J)):
        low = 0.0
        high = 100.0

        while (abs(low - high) > 10**-11):
            mid = (low + high) / 2.0

            if guarantees(i, mid):
                high = mid
            else:
                low = mid

        print '%.6f' % low,

    print '\n',

raw = [x.strip() for x in sys.stdin.readlines()]
ZZZ = int(raw[0])
data = raw[1:]
for case in range(ZZZ):
    doit(data[case])
