import fileinput,sys
import math

print_indicator = 0

def myprint(*arg):
    if print_indicator != 0:
        print print_indicator
        print arg

lines = []

for line in fileinput.input():
    lines.append(line)

n= int(lines[0])

def nchk(n,k):
    numerator = 1;
    for i in xrange(n-k+1,n+1):
        numerator *= i
    for i in xrange(1,k+1):
        numerator /= i
    myprint("n ch k", n,k,numerator)
    return numerator
        

def bin(n,i,p,lim):
    val = 0.0
    #for k in xrange(i,lim+1):
    for k in xrange(i,n+1):
        val += (p**k)*(1-p)**(n-k) * nchk(n,k)
    return val

def slow(X,Y,N):
    if X < 0:
        X = -X
    prob1 = bin(n,X,.5)
    myprint("prob1",prob1)
    prob2 = bin(n,Y+1,prob1)
    myprint("prob2",prob2)
    return prob2

def ndiamonds(w):
    return ((w+1)*(w+2)/2)

def foo(X,Y,N):
    if (X < 0):
        X = -X
    W = int(math.sqrt(2*N)-5)
    if (W < 0):
        W = 0
    W = (W/2)*2
    while (True):
        if ndiamonds(W) > N:
            break
        W += 2
    W = W-2
    myprint("W", W)
    excess = N - ndiamonds(W)
    myprint("ndiamonds", ndiamonds(W))
    myprint("excess", excess)
    if (X +Y <= W):
        return 1.0
    elif (X+Y > W+2):
        return 0.0
    elif (Y+1 <= excess-W-2):
        return 1.0
    elif (Y == W+2 and ndiamonds(W+2) > N):
        return 0.0
    else:
        return bin(excess,Y+1,.5,W+2)

case = 0
line_no =1      
myprint("n",n)
for j in xrange(1,n+1):
    case +=1
    print "Case #%d:" % (case),
    nbym = (lines[line_no]).partition(" ")
    line_no +=1
    N = int(nbym[0])
    rest = nbym[2].partition(" ")
    X = int(rest[0])
    Y = int(rest[2])
    print foo(X,Y,N)
