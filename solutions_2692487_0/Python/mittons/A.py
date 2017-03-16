import sys

inp = sys.stdin

T = int(inp.readline())

for testCase in xrange(1, T+1):
    A, N = map(lambda x: int(x), inp.readline().split(" "))
    motes = map(lambda x: int(x), inp.readline().split(" "))

    if A == 1:
        solution = len(motes)
    else:
        motes.sort()

        curr = A

        bestByRemoving = len(motes)
        bestByAdding = 0

        i = 0
        while i != len(motes):
            if motes[i] < curr:
                curr += motes[i]
                i += 1
            else:
                bestByRemoving = min((bestByAdding + len(motes) - i), bestByRemoving)
                bestByAdding += 1
                curr = 2*curr - 1 #danger?
        
        solution = min(bestByAdding, bestByRemoving)

    print "Case #{}: {}".format(testCase, solution)
