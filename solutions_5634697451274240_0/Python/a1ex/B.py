import os, sys

def move(S,i):
    top = S[:i]
    bot = S[i:]
    top = ["+" if x == "-" else "-" for x in top]
    top.reverse()
    return "".join(top) + bot

def solve(S):
    if "-" not in S:
        print 0
        return
    
    Q = [S]
    N = [0]
    i = 0
    while i < len(Q):
        s = Q[i]
        for k in range(1,len(S)+1):
            m = move(s,k)
            if "-" not in m:
                print N[i]+1
                return
            if m not in Q:
                Q.append(m)
                N.append(N[i]+1)
        i += 1
    print "oops"

def readint():
	return int(sys.stdin.readline())

T = readint()
for t in range(T):
    S = sys.stdin.readline().strip()
    
    print >> sys.stderr, "Solving case #%d..." % (t+1)
    print ("Case #%d:" % (t+1)),
    
    solve(S)
