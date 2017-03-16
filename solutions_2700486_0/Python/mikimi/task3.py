import sys
import scipy
from scipy import special
T = int(sys.stdin.readline())
for case in xrange(1, T+1):
    [N, X, Y] = map(int, sys.stdin.readline().split())
    #print "N, X, Y:", N, X, Y
    #find maximum n:
    n = 0
    while (n+1)*(2*n+1) <= N:
        n+=1
    n -= 1
    
    N = N-(n+1)*(2*n+1)
    #print "Chose n:", n, "new N:", N
    k = n+1
    
    if abs(X)+Y < 2*k:
        result = 1.0
    if abs(X)+Y > 2*k:
        result = 0.0
    if abs(X)+Y == 2*k:
        if X == 0:
            result = 0.0
        else:
            #prawdopodobienstwo jest rozne od 0 i 1:
            #print "prawdopodobienstwo jest rozne od 0 i 1"
            good = 0
            bad = 0
            #zliczamy wszystkei podzialy
            for left in xrange(2*k+1):
                right = N - left
                #print "Rozpatruje:", left, right
                if right > 2*k:
                    continue
                elif (left > Y and X < 0) or (right > Y and X > 0):
                    #print "good"
                    good += scipy.special.binom(N, right)
                else:
                    #print "bad"
                    bad += scipy.special.binom(N, right)
            #print good, bad
            result = 1.0*good/(good+bad)
    
    print "Case #"+str(case)+": "+str(result)
