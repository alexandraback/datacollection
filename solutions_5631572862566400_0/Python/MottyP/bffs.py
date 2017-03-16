import sys

OUT = 'out'
CYCLE = 'cycle'
LEADING = 'leading'
PAIR = 'pair'

def _findPairs(friend, judgement):
    for x in xrange(len(friend)):
        y = friend[x]
        if x == friend[y]:
            judgement[x] = judgement[y] = PAIR

def _measure(start, friend, judgement):
    curr = start
    prev = []
    prevSet = set()
    if judgement[curr] is not None:
        return
    while True:
        jud = judgement[curr]
        if jud is None and curr in prevSet:
            # The first item that belongs to a cycle
            where = prev.index(curr)
            for p in prev[:where]:
                judgement[p] = OUT
            val = (CYCLE, len(prev) - where)
            for p in prev[where:]:
                judgement[p] = val
            return
        if jud is None:
            prev.append(curr)
            prevSet.add(curr)
            curr = friend[curr]
            continue
        if jud == OUT or isinstance(jud, tuple) and jud[0] == CYCLE:
            for p in prev:
                judgement[p] = OUT
                return
        if jud == PAIR:
            target = curr
            length = 0
            break
        if isinstance(jud, tuple) and jud[0] == LEADING:
            _, target, length = jud
            break
    lenp = len(prev)
    for i, p in enumerate(prev):
        judgement[p] = (LEADING, target, length+lenp-i)

def largestCircle(friend):
    N = len(friend)
    judgement = [None] * N
    _findPairs(friend, judgement)
    for start in xrange(N):
        _measure(start, friend, judgement)

    cycleSizes = [j[1] for j in judgement if isinstance(j, tuple) and j[0] == CYCLE]
    cycleSizes.append(0)
    maxCycle = max(cycleSizes)

    # For each pair-member, find the longest path that leads to it.
    maxLeading = {ind: 0 for ind in xrange(N) if judgement[ind] == PAIR}
    numPairMembers = len(maxLeading)
    for j in judgement:
        if isinstance(j, tuple) and j[0] == LEADING:
            _, target, length = j
            maxLeading[target] = max(maxLeading[target], length)
    mostLeading = sum(maxLeading.values())
    return max(maxCycle, numPairMembers + mostLeading)

def _doMain():
    inp = sys.stdin
    ncases = int(inp.readline())
    for cs in range(1, ncases+1):
        N = int(inp.readline())
        friend = [int(part) - 1 for part in inp.readline().split()]
        assert len(friend) == N
        print "Case #%d: %d" % (cs, largestCircle(friend))

if __name__ == '__main__':
    _doMain()
