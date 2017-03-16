import sys


def getline():
    return sys.stdin.readline().strip()

getints = lambda: map(int, getline().split(' '))

cases, = getints()

def required_adds(a, mote):
    if a <= 1:
        return a, None
    count = 0
    while a <= mote:
        a += a - 1
        count += 1
    return a, count




for case in xrange(cases):
    A, n = getints()
    motes = sorted(getints())

    cur_best = 101

    def best(a, m, edits):
        while m < n:
            if a > motes[m]:
                a += motes[m]
                m += 1
            else:
                new_a, count =  required_adds(a, motes[m])
                if count == None:
                    edits += n - m
                    break
                else:
                    other_best = best(new_a, m, edits + count)
                    if other_best >= (edits + n - m):
                        edits += n - m
                        break
                    return other_best
        return edits

    edits = best(A, 0, 0)
    # print a, n, motes

    # print a, n, motes, edits

    print "Case #{case}: {result}".format(case=case + 1, result=edits)
