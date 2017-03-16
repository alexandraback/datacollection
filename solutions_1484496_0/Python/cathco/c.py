import itertools
import sys

def doMadness(S):
    sums = {}
    for i in range(len(S)):
        for comb in itertools.combinations(S, i+1):
            s = sum(comb)
            if not s in sums:
                sums[s] = comb
            else:
                print str(comb)[1:-1].replace(',', '')
                print str(sums[s])[1:-1].replace(',', '')
                return
    print 'impossible'

T = int(sys.stdin.readline())

for i in range(T):
    S = map(int, sys.stdin.readline().strip().split(' ')[1:])
    print 'Case #%i:' % (i + 1)
    doMadness(S)
