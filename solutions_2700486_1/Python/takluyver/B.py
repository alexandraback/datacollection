# -*- coding: utf-8 -*-
fname = "B-large"
fin = open(fname+".in","r")
fout = open(fname+".out","w")
def gcj_read():
  linestr = fin.readline().strip()
  return [int(numb) for numb in linestr.split()]

from math import fsum, factorial

numcases = gcj_read()[0]

def triangle(n):
    return (n*(n+1)) //2

def probkheads(k, trials):
    "probability that k or more trials suceed (p=0.5 for each)"
    allposs = 2**trials
    successposs = sum(factorial(trials)/(factorial(w)*factorial(trials-w)) for w in range(k, trials+1))
    return successposs/allposs

def pdiamond(N, X, Y):
    q = Y + abs(X)
    print(q)
    to_certain = triangle(q+1)
    if N >= to_certain:
        return 1.0   # Pile must include that point - triangle around it
    
    before_possible = triangle(q-1)
    if N <= before_possible:
        print(before_possible, N)
        return 0.0   # Pile won't fill the previous triangle

    if X == 0:
        # Special case for the top of the pile - both sides must be filled first.
        # If we've reached this, N < to_certain, so we can't reach it.
        return 0.0
    
    # We need Y+1 diamonds to fall down this side of the pile to get a diamond
    available = N - before_possible
    required = Y+1
    if required > available:
        # Stack can't get there
        return 0.0
    if available >= required + q:
        # Other side will file up, reaching this point is certain
        return 1.0
    
    return probkheads(required, available)

for caseno in range(numcases):
    N, X, Y = gcj_read()
    outstr = str(pdiamond(N, X, Y))
    
    print("Case #"+str(caseno+1)+": "+ outstr)
    fout.write("Case #"+str(caseno+1)+": "+ outstr +"\n")

fin.close()
fout.close()
