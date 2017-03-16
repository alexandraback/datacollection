"""Google code jam 2012 round 1a problem A: passwords """


import unittest
import operator
import sys

def solveIt(numTyped, numTotal, probs):
    #print locals()
    best = 1 + numTotal + 1  # enter password enter
    x = 1.0  # culmative probability right so far
    for i in xrange(numTyped):
        x *= probs[i]
        y = x * (2 * (numTyped - (i+1)) + 1 + (numTotal - numTyped)) # backspace upto i strat works
        y += (1 - x)*(1 + numTotal + (numTyped - (i+1) )*2 + 1 + (numTotal - numTyped)) # strat fails
        #print i,y
        best = min(best, y)
    return best

def solveProblems(filename):
    f = open(filename, "r")
    l = f.readlines()
    f.close()
    l = map(lambda x: x[:-1], l)
    numCases = int(l[0])
    l = l[1:]
    for i in xrange(numCases):
        print >> sys.stderr, "Computing case %d" % (i + 1)
        (numTyped,numTotal) = map(int, l[0].split()[:2])
        probs = map(float, l[1].split()[:numTyped])
        l = l[2:]
        print "Case #%d: %f" % ((i + 1),solveIt(numTyped, numTotal, probs))

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
