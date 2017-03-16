#!/usr/bin/env python
# encoding: utf-8
"""
B.py
"""

import sys
from bintrees import FastAVLTree
import heapq

def main():
    f = open(sys.argv[1])
    T = int(f.readline())
    
    for t in xrange(T):
        N = int(f.readline())
        one_star_single_tree = FastAVLTree()
        one_star_tree = FastAVLTree()
        two_star_tree = FastAVLTree()
        for n in xrange(N):
            a_i, b_i = map(int, f.readline().split())
            one_star_tree[(a_i, -b_i)] = True
            two_star_tree[(b_i, a_i)] = True
        
        plays = 0
        stars = 0
        
        result = None
        while True:
            if (not two_star_tree.is_empty()) and two_star_tree.min_key()[0] <= stars:
                stars += 2
                plays += 1
                k, v = two_star_tree.pop_min()
                b_i, a_i = k
                del one_star_tree[(a_i, -b_i)]
                continue
            if (not one_star_single_tree.is_empty()) and one_star_single_tree.min_key() <= stars:
                stars += 1
                plays += 1
                one_star_single_tree.pop_min()
                continue
            if (not one_star_tree.is_empty()) and one_star_tree.min_key()[0] <= stars:
                stars += 1
                plays += 1
                k, v = one_star_tree.pop_min()
                a_i, b_i = k
                del two_star_tree[(-b_i, a_i)]
                one_star_single_tree[-b_i] = True
                continue
            break
        
        result = str(plays) if stars == 2*N else "Too Bad"
        
        print "Case #%i: %s" % (t+1, result)

if __name__ == "__main__":
    sys.exit(main())
