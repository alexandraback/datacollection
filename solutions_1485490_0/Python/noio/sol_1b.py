#! /usr/bin/python

__author__ = 'Thomas "noio" van den Berg'

### IMPORTS ###
import sys
import numpy as np

### FUNCTIONS ###    

def do(connectivity):
    pass

### PROCESS INPUT FILE ###

f = open(sys.argv[1])
fout = open(sys.argv[1].replace('.in','.out'),'w')


T = int(f.readline())
for case in xrange(T):
    
    print "\n\nCASE\n"
    
    N, M = [int(d) for d in f.readline().split()]
    A = [int(d) for d in f.readline().split()]
    B = [int(d) for d in f.readline().split()]
    a = A[0::2]
    A = A[1::2]
    b = B[0::2]
    B = B[1::2]
    
    print a, A
    print b, B
    
    table = np.zeros((N+1,M+1), dtype=int)
    remain = np.zeros((N+1,M+1,2), dtype=int)
    # remain[0,:,0] = a[0]
    # remain[1:,0,0] = a
    # remain[:,0,1] = b[0]
    remain[0,0,:] = 0
    # remain[0,1:,1] = b
    
    for i in xrange(N):
        for j in xrange(M):
            # Match
            print "ON %d, %d" % (i,j)
            dela = table[i, j+1]
            delb = table[i+1, j]
            rema = remain[i+1, j, 0]
            remb = remain[i, j+1, 1]
            print 'remain', rema, remb
            gain = min(a[i] + rema, b[j] + remb)
            print gain
            use = table[i][j] + gain
            print use
            if A[i] == B[j] and use >= max(dela, delb):
                table[i+1, j+1] = use
                remain[i+1, j+1, 0] = max(0, a[i] - gain)
                remain[i+1, j+1, 1] = max(0, b[j] - gain)
            # Move right
            elif delb > dela:
                table[i+1, j+1] = delb
                remain[i+1, j+1, 0] = remain[i+1, j, 0]
            # Move down
            elif dela > delb:
                table[i+1, j+1] = dela
                remain[i+1, j+1, 1] = remain[i, j+1, 1]
            else:
                table[i+1, j+1] = delb
                
    print remain[:,:,0]
    print remain[:,:,1]
    print table
    
    ans = table[-1,-1]
    print ans
    fout.write('Case #%d: %s\n'%(case+1,ans))
