import sys

from collections import defaultdict

def is_valid(o, f):

    first = set([t.split()[0] for t in o])
    second = set([t.split()[1] for t in o])

    for t in f:
        f, s = t.split()
        if f not in first or s not in second:
            return False

    return True

T = int(raw_input())

for tc in xrange(1, T + 1):
    N = int(raw_input())
    topics = []
    for x in xrange(N):
        topics.append(raw_input().strip())

    first = [t.split()[0] for t in topics]
    second = [t.split()[1] for t in topics]


    fc = defaultdict(lambda : 0)
    sc = defaultdict(lambda : 0)

    for f in  first:
        fc[f] += 1

    for s in  second:
        sc[f] += 1

    ans = 0

    original = []
    fakes = []

    for t in topics:
        f, s = t.split()
        if fc[f] == 1 or sc[f] == 1:
            original.append(t)
        else:
            fakes.append(t)

    ans = 0

    for x in xrange(2 ** len(fakes)):
        marked = []
        check  = []
        for y in xrange(len(fakes)):
            if x & (2 ** y):
                marked.append(fakes[y])
            else:
                check.append(fakes[y])

        if ans < len(check) and is_valid(original + marked, fakes):
            ans = len(check)

    print "Case #%d: %d" % (tc, ans)
