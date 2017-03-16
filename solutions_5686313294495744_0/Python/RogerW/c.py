def main():
    t = int(raw_input())  # read a line with a single integer
    for caseIdx in xrange(1, t + 1):
        N = int(raw_input())

        pairs = []
        for i in xrange(N):
            pair = raw_input().strip().split()
            pairs.append(pair)

        ans = solve(pairs)

        print "Case #{}: {}".format(caseIdx, ans)

def solve(pairs):
    w1ToPair = dict()
    w2ToPair = dict()

    w1s = set()
    w2s = set()

    for i in xrange(len(pairs)):
        w1, w2 = pairs[i]

        w1s.add(w1)
        w2s.add(w2)

        if w1 in w1ToPair:
            w1ToPair[w1].append(i)
        else:
            w1ToPair[w1] = [i]
        if w2 in w2ToPair:
            w2ToPair[w2].append(i)
        else:
            w2ToPair[w2] = [i]
    #
    # print
    # print pairs
    # print 'w1s',w1s
    # print 'w2s',w2s
    # print w1ToPair
    # print w2ToPair

    mustOriginalPairs = set()

    for w1, pairIdxs in w1ToPair.iteritems():
        if len(pairIdxs) == 1:
            mustOriginalPairs.add(pairIdxs[0])

    for w2, pairIdxs in w2ToPair.iteritems():
        if len(pairIdxs) == 1:
            mustOriginalPairs.add(pairIdxs[0])

    # print 'mustOriginalPairs', mustOriginalPairs

    # check if all words fakable
    fakableW1s = set()
    fakableW2s = set()

    for pairIdx in mustOriginalPairs:
        w1, w2 = pairs[pairIdx]
        fakableW1s.add(w1)
        fakableW2s.add(w2)

    notFakableW1s = w1s - fakableW1s
    notFakableW2s = w2s - fakableW2s
    #
    # print 'fakableW1s', fakableW1s
    # print 'fakableW2s', fakableW2s
    # print 'notFakableW1s', notFakableW1s
    # print 'notFakableW2s', notFakableW2s

    # if all words fakable, return
    if len(notFakableW1s) == 0 and len(notFakableW2s) == 0:
        return len(pairs) - len(mustOriginalPairs)

    # if still some words not fakable, try to search
    # find minimum original pairs
    # BFS

    # possibleOriginalPairs
    POPs = [ ({}, set(notFakableW1s), set(notFakableW2s)) ]
    # node = ( {1,2,3}, notFakableW1s, notFakableW2s )
    while True:
        newPOPs = []
        for node in POPs:
            # print node

            assumedOriPairs, nFW1s, nFW2s = node
            # assumedOriPairs = set(node[0])
            # nFW1s = set(node[1])
            # nFW2s = set(node[2])

            if len(nFW1s) == 0 and len(nFW2s) == 0:
                # print "oriPairs", mustOriginalPairs, assumedOriPairs
                return len(pairs) - len(mustOriginalPairs) - len(assumedOriPairs)

            # add new node and update
            if len(nFW1s) > 0:
                wordToFake = nFW1s.pop()
                pairIdxs = w1ToPair[wordToFake]
                for pairIdx in pairIdxs:
                    w1, w2 = pairs[pairIdx]

                    newAssumedOriPairs = set(assumedOriPairs)
                    newNFW1s = set(nFW1s)
                    newNFW2s = set(nFW2s)

                    newAssumedOriPairs.add(pairIdx)
                    # newNFW1s.discard(w1)
                    newNFW2s.discard(w2)
                    newNode = (newAssumedOriPairs, newNFW1s, newNFW2s)

                    newPOPs.append(newNode)

            # add new node and update
            elif len(nFW2s) > 0:
                wordToFake = nFW2s.pop()
                pairIdxs = w2ToPair[wordToFake]
                for pairIdx in pairIdxs:
                    w1, w2 = pairs[pairIdx]

                    newAssumedOriPairs = set(assumedOriPairs)
                    newNFW1s = set(nFW1s)
                    newNFW2s = set(nFW2s)

                    newAssumedOriPairs.add(pairIdx)
                    newNFW1s.discard(w1)
                    # newNFW2s.discard(w2)
                    newNode = (newAssumedOriPairs, newNFW1s, newNFW2s)

                    newPOPs.append(newNode)
            else:
                print "error"

        POPs = newPOPs

    return "error"

# def findMinimumOriginalPairs(notFakableW1s, notFakableW2s):


# def checkAllWordsFakable(selectedPairs, ):
#     pass

if __name__ == '__main__':
    main()
