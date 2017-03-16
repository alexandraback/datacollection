import sys

sys.setrecursionlimit(2000)

def testcases(filename):
    with open(filename) as f:
        ncases = int(f.readline())
        for case in range(ncases):
            size, nmotes = map(int, f.readline().strip().split())
            motes = tuple(sorted(map(int, f.readline().strip().split()), reverse=True))
            yield (size, motes)

cache = {}
def solve(mote, sizes):
    global cache
    if mote == 1:
        return len(sizes)
    while sizes and sizes[-1] < mote:
        mote += sizes[-1]
        sizes = sizes[:-1]
    if not sizes:
        return 0

    if (mote, sizes) not in cache:
        cache[(mote, sizes)] = min(solve(mote + mote-1, sizes[:]), solve(mote, sizes[:-1])) + 1
    return cache[(mote, sizes)]


filename = sys.argv[1]
for k, case in enumerate(testcases(filename), 1):
    cache = {}
    ops = solve(*case)
    print "Case #{0}: {1}".format(k, ops)
