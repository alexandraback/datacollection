#!/usr/bin/python
import sys
f_input = open(sys.argv[1])

problems = int(f_input.readline().rstrip())


def factorial(i):
    ret = 1.0
    for x in xrange(1, i+1):
        ret*=x
    return ret

def solve(N, X, Y):
    #print "NXY", N, X, Y
    if(X<0): X=-X
    if(Y<0): Y=-Y

    ## SIGMA(4*n+1)
    if((X+Y)%2 == 1): return 0
    dist = (X+Y)/2
    N_top = 2*dist**2 + 3*dist +1
    if(  N_top <= N): return 1.0
    N_under = 2*(dist-1)**2 + 3*(dist-1) +1 
    if( N_under >= N): return 0.0 ## unreached
    
    ## centor ##
    if(X==0): return 0.0


    ## ELSE
    Nrest = N - N_under
    if(Nrest>=((X+Y)+Y+1)): return 1.0
    ## Nrest C Y * (0.5)**Nrest
    ## 
    ret = 0.0
    #print "Y,",Y
    for height in xrange(Y+1, Nrest+1):
        #print height
        #print "Nrest-height",Nrest-height
        #print "height",height
        #print "fact(height)",factorial(height)
        #print "fact(Nrest-height)",factorial(Nrest-height) 
        #print factorial(Nrest) * (0.5)**Nrest / factorial(Nrest-height) / factorial(height)
        ret += factorial(Nrest) * (0.5)**Nrest / factorial(Nrest-height) / factorial(height)
        #print ret 
    return ret


for i in xrange(problems):
    #mine = int(f_input.readline().rstrip().split()[0])
    N, X, Y = map(int, f_input.readline().rstrip().split())
    
    sys.stdout.write("Case #"+str(i+1)+": "+str(solve(N, X, Y))+"\n")
