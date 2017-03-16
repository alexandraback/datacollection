"""2013 qual round problem A: tic."""


import unittest
import operator
import sys

def checkFour(row, player):
    for i in xrange(4):
        c = row[i]
        if (c != player) and (c != "T"):
            return False
    return True

def solveIt(b):
    for p in ["X", "O"]:
        for r in b:
            if checkFour(r, p):
                return "%s won" % p
        for j in xrange(4):
            r = map(lambda i: b[i][j], xrange(4))
            if checkFour(r,p):
                return "%s won" % p
        r = map(lambda i: b[i][i], xrange(4))
        if checkFour(r,p):
            return "%s won" % p
        r = map(lambda i: b[i][3-i], xrange(4))
        if checkFour(r,p):
            return "%s won" % p
    for r in b:
        if r.find(".") >= 0:
            return "Game has not completed"
    return "Draw"

def solveProblems(filename):
    f = open(filename, "r")
    l = f.readlines()
    f.close()
    l = map(lambda x: x[:-1], l)
    numCases = int(l[0])
    l = l[1:]
    for i in xrange(numCases):
        print >> sys.stderr, "Computing case %d" % (i + 1)
        b = l[:4]
        l = l[5:]
        print "Case #%d: %s" % ((i + 1),solveIt(b))

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
