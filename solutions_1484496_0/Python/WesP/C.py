import sys
import itertools

T = int(sys.stdin.readline())

def findmatch(nums, N):
    sums = {}

    for foo in nums:
        sums[foo] = [foo]

    for i in xrange(2, N):
        for set in itertools.combinations(nums, i):
            s = sum(set)
            if s in sums:
                return (set, sums[s])
            else:
                sums[s] = set

    return ([], [])

for i in xrange(T):
    line = sys.stdin.readline().split()
    N, nums = int(line[0]), line[1:]
    nums = map(int, nums)

    (set1, set2) = findmatch(nums, N)

    outstr = ""

    if len(set1) == 0:
        outstr = "Impossible"
    else:
        outstr = "%s\n%s" % (" ".join(str(x) for x in set1), " ".join(str(x) for x in set2))

    print "Case #%d:\n%s" % (i+1, outstr)

