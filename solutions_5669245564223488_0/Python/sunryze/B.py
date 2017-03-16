import sys, re
import numpy as np
from math import factorial

# http://code.activestate.com/recipes/577225-union-find/
def MakeSet(x):
     x.parent = x
     x.rank   = 0
     return x

def Union(x, y):
     xRoot = Find(x)
     yRoot = Find(y)
     if xRoot.rank > yRoot.rank:
         yRoot.parent = xRoot
     elif xRoot.rank < yRoot.rank:
         xRoot.parent = yRoot
     elif xRoot != yRoot: # Unless x and y are already in same set, merge them
         yRoot.parent = xRoot
         xRoot.rank = xRoot.rank + 1

def Find(x):
     if x.parent == x:
        return x
     else:
        x.parent = Find(x.parent)
        return x.parent

class Node(object):
    def __init__ (self, label):
        self.label = label
    def __str__(self):
        return self.label
        
def sanity(Cars):
    N = len(Cars)
    for i in range(N):
        c = Cars[i]
        if len(c) > 2:
            # purity internal
            seen = set()
            for j in range(1, len(c)):
                if c[j] != c[j-1]:
                    if c[j] in seen: 
                        return False
                    seen.add(c[j-1])
            for a in set(c[1:-1]):
                if a != c[0] and a != c[-1]:
                    if a in ''.join(Cars[j] for j in range(N) if j != i): return False
    # only pures and bridges remain. check for sanity of briges
    S = dict((c, 0) for c in 'abcdefghijklmnopqrstuvwxyz')
    E = dict(S)
    for i in range(N):
        ci = Cars[i]
        if len(ci) >= 2 and ci[0] != ci[-1]:
            if S[ci[0]] > 0: return False
            S[ci[0]] = 1
            if E[ci[-1]] > 0: return False
            E[ci[-1]] = 1
    return True

def solve(Cars):
    M = 1000000007
    N = len(Cars)
    # sanity
    if not sanity(Cars): return 0
    # count number of pures
    P = dict((c, 0) for c in 'abcdefghijklmnopqrstuvwxyz')
    for i in range(N):
        ci = Cars[i]
        if ci[0] == ci[-1]: P[ci[0]] += 1
    # clusters: all start/end letters of all cars {{ab}, {ba}, {bb}, {ca}, {cd}, ...}
    C = [MakeSet(Node(Cars[i][0]+Cars[i][-1])) for i in range(N)]
    for i in range(N):
        for j in range(i+1, N):
            if Cars[i][0] == Cars[j][-1] or Cars[j][0] == Cars[i][-1] or Cars[i][0] == Cars[j][0] or Cars[i][-1]==Cars[j][-1]:
                Union(C[i], C[j])
    Z = dict((s, set()) for s in set([Find(C[i]).label for i in range(N)]))
    for i in range(N):
        cls = Find(C[i]).label
        if Cars[i][0] == Cars[i][-1]:
            Z[cls].add(Cars[i][0])
    total = 1
    #print (Z)
    for c in Z:
        # compute combs for class
        k = 1
        for p in Z[c]:
            k = (k * factorial(P[p])) % M
        total = (total * k) % M
    groups = len(set([Find(C[i]).label for i in range(N)]))
    return (factorial(groups) * total) % M
    

    
    
def main(filename):
    with open(filename) as f_in:
        T = int(f_in.readline())
        for i in range(1, T+1):
            f_in.readline().strip() # ignore N
            Cars = f_in.readline().strip().split(' ')
            print( 'Case #{0}: {1}'.format(i, solve(Cars)))
            #map(int, f_in.readline().strip().split(' '))

if __name__ == "__main__":
    main(sys.argv[1])
