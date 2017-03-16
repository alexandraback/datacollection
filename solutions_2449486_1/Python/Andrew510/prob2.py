#!/usr/bin/python

import sys
infile = sys.stdin
#infile = open('in.txt', 'r')

def check(matrix):
    rowht = map(max, matrix)
    colht = map(max, zip(*matrix))
    
    for i in range(N):
        for j in range(M):
            v = matrix[i][j]
            if v != rowht[i] and v != colht[j]:
                return 'NO'
    return 'YES'

T = int(infile.readline())
for t in range(T):
    N, M = map(int, infile.readline().split())
    matrix = [ map(int, infile.readline().split()) for _ in range(N) ]
    
    print 'Case #%d: %s' % (t+1, check(matrix))
