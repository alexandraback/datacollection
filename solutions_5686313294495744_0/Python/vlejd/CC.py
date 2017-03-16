import numpy as np
import sys
from itertools import product, combinations
from collections import defaultdict as dfd


def solve(t):
    print "Case #%d:"%(t+1),
    n = input()
    vocab = {}
    vords = []
    for i in xrange(n):
        q ,w = raw_input().split()
        vords.append([q,w])
    
    f ,s = zip(*vords)
    sf = len(set(f))
    ss = len(set(s))
    
    staci = 999
    for comb in xrange(n):
        for c in combinations(vords,comb+1):
            
            g, h = zip(*c)
            if len(set(g))==sf and len(set(h))==ss:
                staci = min(staci, comb+1)
    print n-staci
    
def main():
    T = input()
    for i in xrange(T):
        solve(i)
    
if __name__=="__main__":
    main()