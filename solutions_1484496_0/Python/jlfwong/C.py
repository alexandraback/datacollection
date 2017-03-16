import sys
from itertools import combinations, chain

casenum = 1
def doit(case):
    global casenum

    nums = [int(x) for x in case.split(' ')[1:]]
    #nums  = [1,2,3]

    combs = list(chain(*[list(combinations(nums, i)) for i in range(1, len(nums))]))

    hist = {}

    print 'Case #%d:' % (casenum)
    casenum += 1

    for comb in combs:
        s = sum(comb)

        if s in hist:
            comb1 = comb
            comb2 = hist[s]

            print ' '.join([str(x) for x in comb1])
            print ' '.join([str(x) for x in comb2])
            return
        else:
            hist[s] = comb

    print 'Impossible'

raw = [x.strip() for x in sys.stdin.readlines()]
ZZZ = int(raw[0])
data = raw[1:]
for case in range(ZZZ):
    doit(data[case])
