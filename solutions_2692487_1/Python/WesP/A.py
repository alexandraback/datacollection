import sys

T = int(sys.stdin.readline())

def determineOps(A, otherMotes, ix, numMotes):
    #print "***Starting***"
    while ix < numMotes and otherMotes[ix] < A:
        #print "{%d} eats [%d] to grow to {%d}" % (A, otherMotes[ix], A + otherMotes[ix])
        A += otherMotes[ix]
        ix += 1

    if ix == numMotes:
        #print "Ate everything"
        return 0

    delOps = numMotes - ix

    addOps = 0

    if A == 1:
        #print "Not big enough to eat anything"
        return numMotes - ix

    #print "{%d} can't eat [%d]" % (A, otherMotes[ix])

    while A <= otherMotes[ix]:
        #print "Inserting [%d], A grows to {%d}" % (A - 1, A + A - 1)
        A += A - 1
        addOps += 1

    if addOps >= delOps:
        #print "Deleting rest of motes instead: %d deleted" % delOps
        return delOps

    addOps += determineOps(A, otherMotes, ix, numMotes)

    if addOps >= delOps:
        #print "Deleting rest of motes instead, considering all: %d deleted" % delOps
        return delOps

    return addOps

for i in xrange(T):
    A, numMotes = sys.stdin.readline().strip().split()
    A = int(A)
    numMotes = int(numMotes)

    otherMotes = sys.stdin.readline().strip().split()
    otherMotes = [int(x) for x in otherMotes]

    otherMotes.sort()

    ops = determineOps(A, otherMotes, 0, numMotes)

    print "Case #%d: %d" % (i+1, ops)


