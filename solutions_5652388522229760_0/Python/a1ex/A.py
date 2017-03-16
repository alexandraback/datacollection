import os, sys


def solve(N):
    digits = set()
    
    for i in range(1,100):
        digits = digits.union(set(str(i*N)))
        
        if len(digits) == 10:
            print i*N
            return
    
    print "INSOMNIA"

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

def readint():
	return int(sys.stdin.readline())

T = readint()
for t in range(T):
    N = readint()
    
    print >> sys.stderr, "Solving case #%d..." % (t+1)
    print ("Case #%d:" % (t+1)),
    
    solve(N)
