#!/usr/local/bin/python

import sys

def testBFF(l,N,bffs):
    left = set(l)
    full = set(l)

    neighbors = [ set() for i in range(N) ]

    #print l, N, bffs
    while left:
        next_kid = list(left)[0]
        left.remove(next_kid)
        clique_size = 0
        chain_start = next_kid

        while True:
            bff = bffs[next_kid]
            if bff  not in full:
                return False

            neighbors[next_kid].add(bff)
            neighbors[bff].add(next_kid)
            #print next_kid, bff, l, N, bffs, left, neighbors
            clique_size += 1

            if len(neighbors[bff]) > 2:
                 return False

            if bff == chain_start:
                if clique_size == len(l):
                    return True

                elif clique_size == 2:
                    break

                else:
                    return False

            if bff in left:
                left.remove(bff)
                next_kid = bff
            else:
                break 

    return True

import itertools
def solve(t):
    N = int(sys.stdin.readline().rstrip())
    bffs = map(lambda x:int(x)-1, sys.stdin.readline().rstrip().split())

    best = 0
    children = range(N)
    for i in range(N, 1, -1):
        for combination in itertools.combinations(children, i):
            if testBFF(combination, N, bffs):
                print 'Case #{}: {}'.format(t, i) 
                return

    print 'Case #{}: {}'.format(t, 0)

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
