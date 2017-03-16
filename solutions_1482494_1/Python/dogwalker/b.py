"""Google code jam 2012 round 1a: problem b: Kingdom rush"""

import unittest
import operator
import sys

class Level(object):
    def __init__(self, l):
        self.a = l[0]  # One star elg
        self.b = l[1]  # Two star elg
        self.didTwoStar = False
        self.didOneStar = False
    def __repr__(self):
        return "Level(%d,%d,%r,%r)" % (self.a, self.b, self.didTwoStar, self.didOneStar)
    def doTwoStars(self):
        assert(self.didTwoStar == False)
        self.didTwoStar = True
        k = 1
        if not self.didOneStar:
            k += 1
            self.didOneStar = True
        return k
    def doOneStar(self):
        assert(self.didOneStar == False)
        self.didOneStar = True
        return 1

def solveIt(numLevels, levelRaw):
    levels = map(Level, levelRaw)
    byTwoStarElg = list(levels)
    def cmpByA(x,y):
        return cmp(x.a, y.a)
    def cmpByB(x,y):
        return cmp(x.b, y.b)
    byTwoStarElg.sort(cmp=cmpByB)
    #byOneStarElg = list(levels)
    #byOneStarElg.sort(cmp=cmpByA)
    turns = 0
    numStars = 0
    #print byTwoStarElg
    while len(byTwoStarElg) > 0:
        moved = False
        for i in xrange(len(byTwoStarElg)):
            if byTwoStarElg[i].b <= numStars:
                numStars += byTwoStarElg[i].doTwoStars()
                byTwoStarElg = byTwoStarElg[:i] + byTwoStarElg[(i+1):] # too bad python lists aren't lists...
                moved = True
                turns += 1
                break
        if moved:
            continue
        # find first one star eligable ... by going backwards down the list
        for i in xrange(len(byTwoStarElg) - 1, -1, -1):
            if byTwoStarElg[i].didOneStar:
                continue
            elif byTwoStarElg[i].a <= numStars:
                moved = True
                numStars += byTwoStarElg[i].doOneStar()
                turns += 1
                break
        if moved:
            continue
        return "Too Bad"
    return "%d" % turns

def solveProblems(filename):
    f = open(filename, "r")
    l = f.readlines()
    f.close()
    l = map(lambda x: x[:-1], l)
    numCases = int(l[0])
    l = l[1:]
    for i in xrange(numCases):
        print >> sys.stderr, "Computing case %d" % (i + 1)
        numLevels = int(l[0])
        l = l[1:]
        levels = map(lambda x: map(int, x.split()[:2]), l[:numLevels])
        l = l[numLevels:]
        print "Case #%d: %s" % ((i + 1),solveIt(numLevels, levels))

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
