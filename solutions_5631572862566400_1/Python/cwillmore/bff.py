import sys
from collections import defaultdict

fp = open(sys.argv[1])
def readline():
    return fp.readline().strip()

# N is up to 1000
# each kid has 1 bff... only kids with degree greater than 2 will be bffs of
# multiple kids.
# so degree-1 kids can be excluded
# will cycle necessarily be directed? yes: suppose that a kid in the cycle is
# bff of two kids. then there must be some other kid in cycle that has 2 bffs,
# but that doesn't work.
# so just look for longest cycle
# ... wait, nm, it's possible for there to be gap in circle, multiple gaps
# even. not every edge in circle has to be bff edge
#
# 1 <-> 2 <- 3 . 4 -> 1
# 
# ok so if there's a gap, then segment must be of form 1 -> 2 <-> 3 <- 4

def classify(bffs, i):
    j = i
    seen = set()
    while True:
        if j in seen:
            if bffs[bffs[j]] == j:
                return ('tail', len(seen) - 2, (j, bffs[j]))
            elif j == i:
                return ('cycle', len(seen))
            else:
                return None
        seen.add(j)
        j = bffs[j]

def solve(bffs):
    longest_cycle = 0
    tails = {}
    for i in xrange(len(bffs)):
        l = classify(bffs, i)
        if l is None:
            continue
        if l[0] == 'cycle':
            longest_cycle = max(longest_cycle, l[1])
        elif l[0] == 'tail':
            tail_len = l[1]
            p1, p2 = l[2]
            tails[p1, p2] = max(tails.get((p1, p2), 0), tail_len)
    # figure out max tails put together
    tails_total = 0
    for ((p1, p2), tail_len) in tails.iteritems():
        assert p1 != p2
        if p1 < p2 or (p2, p1) not in tails:
            tails_total += 2
        tails_total += tail_len
    return max(longest_cycle, tails_total)

if __name__ == '__main__':
    num_cases = int(readline())
    for i in xrange(num_cases):
        readline() # discard bff count
        bffs = [int(n) - 1 for n in readline().split()]
        print "Case #%d: %s" % (i + 1, solve(bffs))
