import os, sys

def neg(S):
    S = ["+" if x == "-" else "-" for x in S]
    return "".join(S)

def solve(S):
    # ignore good pancakes at bottom
    S = S.rstrip("+")
    
    # empty string? nothing to do
    if S == "":
        return 0
    
    # now we have one (or more) minus(es) at the bottom,
    # so we must flip the stack once;
    # before that, let's try to put all the items on the negative side
    # with minimal number of moves
    S = S.rstrip("-")
    return 1 + solve(neg(S))

def readint():
	return int(sys.stdin.readline())

T = readint()
for t in range(T):
    S = sys.stdin.readline().strip()
    
    print >> sys.stderr, "Solving case #%d..." % (t+1)
    print ("Case #%d:" % (t+1)),
    
    print solve(S)
