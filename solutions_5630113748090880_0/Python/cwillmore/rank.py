import sys
from collections import Counter

fp = open(sys.argv[1])
def readline():
    return fp.readline().strip()

def solve(n, rows):
    counts = Counter(x for row in rows for x in row)
    missing = [x for (x, j) in counts.iteritems() if j % 2 != 0]
    missing.sort()
    return missing

if __name__ == '__main__':
    num_cases = int(readline())
    for i in xrange(num_cases):
        n = int(readline())
        rows = [map(int, readline().split()) for j in xrange(2 * n - 1)]
        sol = solve(n, rows)
        print "Case #%d: %s" % (i + 1, ' '.join(str(x) for x in sol))
