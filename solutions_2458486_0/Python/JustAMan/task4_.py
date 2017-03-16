'''
Problem D. Treasure
Solution by vassnlit@gmail.com
'''

import collections

chestKeys = {
    1: 1,
    2: 1,
    3: 2,
    4: 3,
}

chests = {
    1: [],
    2: [1, 3],
    3: [],
    4: [2],
}

keys = [1]

class FoundSolution(Exception):
    pass
def solve():
    haveKeys = {key: 0 for key in (set(chestKeys.itervalues()) | set(keys) | set(sum(chests.values(),[])))}
    for key in keys:
        haveKeys[key] += 1
    visited = set()
    openSeq = []
    chestNums = sorted(chests.iterkeys())
    chestSet = set(chests.iterkeys())
    chestKeyCount = {} # {chestNum: {} for (chestNum, chestKeys) in chests.iteritems()}
    for chestNum, keysInChest in chests.iteritems():
        chestKeyCount[chestNum] = {}
        for key in set(keysInChest):
            chestKeyCount[chestNum][key] = keysInChest.count(key)

    def canOpenAll(current = set()):
        myVisited = visited | current
        neededKeys, possibleKeys = {}, {}
        for chestNum, key in chestKeys.iteritems():
            if chestNum not in myVisited:
                neededKeys[key] = neededKeys.get(key, 0) + 1
        for chestNum, chest in chests.iteritems():
            if chestNum not in myVisited:
                for key in chest:
                    possibleKeys[key] = possibleKeys.get(key, 0) + 1
        for key, count in haveKeys.iteritems():
            possibleKeys[key] = possibleKeys.get(key, 0) + count
        for neededKey, neededCount in neededKeys.iteritems():
            if possibleKeys.get(neededKey, 0) < neededCount:
                return False
        return True

    def delve(N):
        for key in chests[N]:
            haveKeys[key] += 1
        visited.add(N)
        openSeq.append(N)
        if len(openSeq) == len(chests):
            raise FoundSolution
        for n in chestNums:
            if n not in visited:
                key = chestKeys[n]
                haveKeys[key] -= 1
                if haveKeys[key] == 0:
                    #doDelve = True
                    #if 1.0 * len(openSeq) / len(chests) < 0.33:
                    #    doDelve = canOpenAll(set([n]))
                    #if doDelve:
                    if key not in chests[n] and (1.0 * len(openSeq) / len(chests) < 0.7):
                        neededKeys = set(chestKeys[ch] for ch in (chestSet - visited - set([n])))
                        if key not in neededKeys:
                            delve(n)
                        else:
                            for chestNum in (chestSet - visited - set([n])):
                                if chestKeys[chestNum] != key and key in chests[chestNum]:
                                    delve(n)
                                    break
                    else:
                        delve(n)
                elif haveKeys[key] > 0:
                    delve(n)
                haveKeys[key] += 1

        visited.remove(N)
        openSeq.remove(N)
        for key in chests[N]:
            haveKeys[key] -= 1

    def startDelve(N):
        key = chestKeys[N]
        haveKeys[key] -= 1
        if haveKeys[key] >= 0:
            delve(N)
        haveKeys[key] += 1

    # sanity check: it is possible to gather keys needed for all chests at all?
    if not canOpenAll():
        return 'IMPOSSIBLE'

    for n in chestNums:
        try:
            startDelve(n)
        except FoundSolution:
            return ' '.join(str(x) for x in openSeq)
    return 'IMPOSSIBLE'

def main():
    global chestKeys, chests, keys
    import sys
    with open(sys.argv[1], 'r') as inp:
        T = int(inp.readline().strip())
        for t in xrange(T):
            K, N = [int(x) for x in inp.readline().strip().split()]
            keys = [int(k) for k in inp.readline().strip().split()]
            chestKeys.clear()
            chests.clear()
            for n in xrange(1,N+1):
                data = [int(k) for k in inp.readline().strip().split()]
                chestKeys[n] = data[0]
                chests[n] = data[2:]
            #if t+1==12:
            # import pdb;pdb.set_trace()
            print 'Case #%d: %s' % (t+1, solve())

if __name__ == '__main__':
    main()