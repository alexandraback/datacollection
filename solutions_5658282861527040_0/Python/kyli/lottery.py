#!/usr/bin/env python
# -*- coding: UTF-8 -*-
import argparse
import itertools
import sys

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-in', '--input', 
        metavar='FILE', 
        action='store', 
        type=argparse.FileType('r'), 
        help='input file', 
        default=sys.stdin)
    parser.add_argument('-out', '--output', 
        metavar='FILE', 
        action='store', 
        type=argparse.FileType('w'), 
        help='output file', 
        default=sys.stdout)
    (known_args, unknown_args) = parser.parse_known_args()
    
    T = int(known_args.input.readline().rstrip('\n'))
    
    for i in xrange(T):
        args = known_args.input.readline().rstrip('\n').split()
        A = int(args[0]) # unused?
        B = int(args[1])
        K = int(args[2])
        # print A,B,K
        counter = int()
        for x in xrange(A):
            for y in xrange(B):
                if x & y < K:
                    counter += 1
        known_args.output.write('Case #{0:d}: {1:d}\n'.format(i + 1, counter))
    

if __name__ == '__main__':
    main()
