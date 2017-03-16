"""2013 code jam qualifier: lawnmower problem.

Point is that max height from a column gives the height that it was
cut at.  All others under the max height must be cut by the row pass.
Thus one check on the row height.  A second check is that there isn't
anything in the row higher than the forced row height."""

import unittest
import operator
import sys

def columnMax(lines, j):
    n = -1
    for t in lines:
        n = max(n, t[j])
    assert(n >= 0)
    return n
class TestColumnMax(unittest.TestCase):
    def test_basic(self):
        a = [[1,2,3],[4,5,6]]
        self.assertEqual(4, columnMax(a, 0))
        self.assertEqual(5, columnMax(a, 1))

def findRowCut(columnCuts, row):
    "Return None on no cut needed.  Otherwise, return min height needed."
    m = None
    for i in xrange(len(row)):
        x = row[i]
        y = columnCuts[i]
        assert(y >= x)
        if (y > x):
            if m == None:
                m = x
            else:
                m = min(m, x) # will make a second pass to double check
    return m
class TestFindRowCut(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(None, findRowCut([2,2], [2,2]))
        self.assertEqual(None, findRowCut([2,1], [2,1]))
        self.assertEqual(1, findRowCut([2,2], [2,1]))

def solveIt(n, m, intLines):
    # Find column cut heights
    columnCuts = map(lambda x: columnMax(intLines, x), xrange(len(intLines[0])))
    rowCuts = map(lambda r: findRowCut(columnCuts, r), intLines)
    #print n,m,intLines
    for j in xrange(len(intLines)):
        for i in xrange(len(intLines[0])):
            x = intLines[j][i]
            c = columnCuts[i]
            r = rowCuts[j]
            if r == None:
                if x != c:
                    return "NO"
            else:
                if (x != c) and (x != r):
                    return "NO"
                if (x > c) or (x > r):
                    return "NO"
    return "YES"

def solveProblems(filename):
    f = open(filename, "r")
    l = f.readlines()
    f.close()
    l = map(lambda x: x[:-1], l)
    numCases = int(l[0])
    l = l[1:]
    for i in xrange(numCases):
        print >> sys.stderr, "Computing case %d" % (i + 1)
        (n,m) = map(int, l[0].split()[:2])
        l = l[1:]
        rawLines = l[:n]
        l = l[n:]
        intLines = map(lambda t: map(int, t.split()[:m]), rawLines)
        print "Case #%d: %s" % ((i + 1),solveIt(n,m,intLines))

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
