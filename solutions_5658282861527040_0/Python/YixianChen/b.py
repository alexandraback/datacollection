#!/usr/bin/env python
import sys, operator as op, itertools as itt, math, collections, bisect
debug = False
#if debug: print

def main():
    f = sys.stdin
    T = int( f.next() )
    
    for i in xrange(1, T+1):
        A, B, K = map ( int, f.next().strip().split() )
        #f.next().strip().split()
        x = len( filter( lambda i: i<K, map ( lambda j:j[0]&j[1], itt.product( xrange(A), xrange(B) ) ) ) )
        print "Case #{0}: {1}".format ( i, x )
    return 0

sys.exit ( main() )
