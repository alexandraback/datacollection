import sys
from collections import defaultdict

def missingList(lists):
    # Each soldier appears in two lists. So if k soldiers have height H,
    # H will appear 2k times -- an even number. Unless H is in the missing list...
    counts = defaultdict(int)
    for line in lists:
        for h in line:
            counts[h] += 1
    odds = [h for h, cnt in counts.iteritems() if cnt % 2 == 1]
    return sorted(odds)

def _doMain():
    inp = sys.stdin
    ncases = int(inp.readline())
    for cs in range(1, ncases+1):
        N = int(inp.readline())
        lists = []
        for i in xrange(2*N-1):
            lists.append([int(part) for part in inp.readline().split()])
        print "Case #%d: %s" % (cs, ' '.join(str(h) for h in missingList(lists)))

if __name__ == '__main__':
    _doMain()
