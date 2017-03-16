"""2013 qual round problem C: fair and square.

Let's solve case of upto 10^14 first, then look at other strat for
10^100."""

import unittest
import operator
import collections
import sys

def isPal(x):
    s = "%d" % x
    m = (len(s)/2) + 1
    for i in xrange(m):
        if s[i] != s[len(s)-1-i]:
            return False
    return True
class TestIsPal(unittest.TestCase):
    def test_basic(self):
        for i in [1,2,3,4,11,22,121,111,123321,12321]:
            self.assertTrue(isPal(i))
        for i in [12, 122, 42, 123421]:
            self.assertFalse(isPal(i))

def buildPalTable(end=10**7):
    "Table of just paladromes"
    q = collections.deque()
    for i in xrange(1,(end+1)):
        if isPal(i):
            q.append(i)
    return list(q)
def buildPalPalTable(end=10**7):
    """Table of pal entries which when squared give paladromes. 
    end = last number to square."""
    q = collections.deque()
    for i in xrange(1,(end+1)):
        if isPal(i) and isPal(i * i):
            q.append(i)
    return list(q)
palPalTable=buildPalPalTable(10**7)
#print palPalTable
#print len(palPalTable)
# Only 39 entries in table, so linear scan should be fine

def solveIt(n,m):
    k = 0
    for p in palPalTable:
        x = p * p
        if x < n:
            continue
        if x > m:
            break
        k = k + 1
    return k

def solveProblems(filename):
    f = open(filename, "r")
    l = f.readlines()
    f.close()
    l = map(lambda x: x[:-1], l)
    numCases = int(l[0])
    l = l[1:]
    for i in xrange(numCases):
        print >> sys.stderr, "Computing case %d" % (i + 1)
        (n,m) = map(long, l[i].split()[:2])
        print "Case #%d: %d" % ((i + 1),solveIt(n,m))

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

# In:  6:55
# Out: 
