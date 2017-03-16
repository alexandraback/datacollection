"""2013 code jam qualifying round problem D: treasure chest.

The lexigraphical order seems to lead itself to a graph search.  An
initial straightforward implementation would be to do DFS.  However,
the running time can quickly become exponential.

Observation: two states are equivelant if the same vector of keys have
been used and are in hand.  Take the lexographically first one.  Using
this, it might prune sufficiently to make search viable.  BFS might
work, but DFS might also work.

Graph connection properities could be used to detect some impossable
cases, but aren't obvious to use how to detect all, so punt for now.
"""

import unittest
import operator
import collections
import sys

maxProbIdx=201

class State(object):
    """Represent key and path state."""
    def __init__(self):
        self.kHave = [0] * maxProbIdx
        self.kUsed = [0] * maxProbIdx
        self.path = []  # Could consider queue here
        self.opened = [False] * maxProbIdx
    def setOpenedFromPath(self):
        for p in self.path:
            self.opened[p] = True
    def haveOpened(self, indexFrom1):
        return self.opened[indexFrom1]
    def isKeyVectorEqual(self, x):
        "Return true on identical key vectors."
        return (self.kHave == x.kHave) and (self.kUsed == x.kUsed)
    def addKeyList(self, keyList):
        "Assumes keyList is list of integers."
        for k in keyList:
            self.kHave[k] = self.kHave[k] + 1
    def isPathLessThan(self, x):
        # Should only be comparing when same length
        assert(len(self.path) == len(x.path))
        for i in xrange(len(self.path)):
            if self.path[i] != x.path[i]:
                return self.path[i] < x.path[i]
        # Shouldn't ever see same path twice
        assert(False)
    def getAvailableKeyList(self):
        "Get a list of available keys"
        # Might consider maintaining at same time as initial access
        q = collections.deque()
        for i in xrange(maxProbIdx):
            if self.kHave[i] > self.kUsed[i]:
                q.append(i)
        return list(q)
    def getHashRep(self):
        "Get pair for dictionary insertion"
        return ((tuple(self.kHave),tuple(self.kUsed)),tuple(self.path))
    def loadFromHashRep(self, hashKey, hashVal):
        self.kHave = list(hashKey[0])
        self.kUsed = list(hashKey[1])
        self.path = list(hashVal)
        self.setOpenedFromPath()
    def getCanOpen(self, chests):
        q = collections.deque()
        keys = self.getAvailableKeyList()
        for k in keys:
            for c in chests.opens[k]:
                if not self.haveOpened(c):
                    q.append(c)
        t = list(q)
        t.sort()
        return t
    def getAfterOpen(self, chestNumToOpen, chests):
        c = chestNumToOpen # indexed from 1
        x = State()
        x.kHave = list(self.kHave)
        for k in chests.getGivesList(c):
            x.kHave[k] = x.kHave[k] + 1
        x.kUsed = list(self.kUsed)
        k = chests.getNeedsKey(c)
        x.kUsed[k] = x.kUsed[k] + 1
        x.path = self.path + [c]
        x.opened = list(self.opened)
        x.opened[c] = True
        return x
class TestStateRep(unittest.TestCase):
    def test_basic(self):
        x = State()
        y = State()
        x.addKeyList([1,2])
        y.addKeyList([2,3])
        self.assertFalse(x.isKeyVectorEqual(y))
        x.path = [1,3]
        y.path = [1,2]
        self.assertTrue(y.isPathLessThan(x))
        self.assertFalse(x.isPathLessThan(y))
        x.kUsed[1] = 1
        self.assertEqual(x.getAvailableKeyList(), [2])
        r = x.getHashRep()
        z = State()
        z.loadFromHashRep(r[0],r[1])
        self.assertEqual(x.kHave, z.kHave)

class Chest(object):
    def __init__(self, chestStrLine):
        a = chestStrLine.split()
        (self.need, k) = map(int, a[:2])
        self.gives = map(int, a[2:(2+k)])
class Chests(object):
    def __init__(self, chestStrs):
        self.a = map(Chest, chestStrs) # note off by one for index
        self.numChests = len(chestStrs)
        self.opens = [[]] * maxProbIdx
        #print self.opens
        for i in xrange(self.numChests):
            n = self.a[i].need
            #print i,n
            self.opens[n] = self.opens[n] + [(i+1)]
    def getChest(self, indexFrom1):
        return self.a[indexFrom1 - 1]
    def getGivesList(self, indexFrom1):
        return self.getChest(indexFrom1).gives
    def getNeedsKey(self, indexFrom1):
        return self.getChest(indexFrom1).need

def doDfs(stateToExplore, chests, done):
    s = stateToExplore
    #print "Exploring", s.path
    #print "  kHave ", s.kHave[:5]
    #print "  kUsed ", s.kUsed[:5]
    #print "  opened", s.opened[:5]
    if len(s.path) == chests.numChests:
        return s
    todo = s.getCanOpen(chests)
    for c in todo:
        x = s.getAfterOpen(c, chests)
        r = x.getHashRep()
        if done.has_key(r[0]):
            continue
        y = doDfs(x, chests, done)
        if y != False:
            return y
    r = s.getHashRep()
    done[r[0]] = r[1]
    return False

def solveIt(initKeyList, chestStrs):
    chests = Chests(chestStrs)
    initialState = State()
    initialState.addKeyList(initKeyList)
    done = {}
    x = doDfs(initialState, chests, done)
    if x == False:
        return "IMPOSSIBLE"
    else:
        return " ".join(map(lambda i: "%d" % i, x.path))
    return "bogus"

def solveProblems(filename):
    f = open(filename, "r")
    l = f.readlines()
    f.close()
    l = map(lambda x: x[:-1], l)
    numCases = int(l[0])
    l = l[1:]
    for i in xrange(numCases):
        print >> sys.stderr, "Computing case %d" % (i + 1)
        (k,n) = map(int, l[0].split()[:2])
        initKeyList = map(int, l[1].split()[:k])
        l = l[2:]
        chestStrs = l[:n]
        l = l[n:]
        print "Case #%d: %s" % ((i + 1),solveIt(initKeyList, chestStrs))

import getopt
def main():
    try:
        opts, args = getopt.gnu_getopt(sys.argv[1:], "th", ["test", "help"])
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        #usage()
        sys.exit(2)
    for o, a in opts:
        if o in {"-t" : True, "--test" : True}:
            sys.argv = ["foo"] #+ args
            unittest.main()
            return
        elif o in {"-h" : True, "--help" : True}:
            #usage()
            sys.exit()
        else:
            assert False, "unhandled option"
    solveProblems(args[0])
 
if __name__ == "__main__":
    main()

# In:  
# Out: 
