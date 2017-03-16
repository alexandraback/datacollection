#import numpy as np
#import sys
'''

for x in xrange(1<<10):
    A = map(list,[[0]*5]*5)
    A[0][1] = x & 1;
    A[0][2] = x >> 1 & 1
    A[0][3] = x >> 2 & 1
    A[0][4] = x >> 3 & 1

    A[1][2] = x >> 4 & 1
    A[1][3] = x >> 5 & 1
    A[1][4] = x >> 6 & 1

    A[2][3] = x >> 7 & 1
    A[2][4] = x >> 8 & 1

    A[3][4] = x >> 9 & 1

    if not all([A[x][y] for x in xrange(1,4) for y in xrange(x+1,5)]):
        continue

    A = np.matrix(A)
    B = sum(A**i for i in xrange(15))
    #print B[0,4]
    if B[0,4] == int(sys.argv[1]):
        print B[0,4]
        print A
'''
T = input();
for casenum in xrange(1, T+1):
    print 'Case #{}:'.format(casenum),
    B, M = map(int,raw_input().split())
    if M <= 2**(B-2):
        print 'POSSIBLE'
        A = map(list, [['0']*B]*B)
        for i in xrange(1, B):
            for j in xrange(i+1, B):
                A[i][j] = '1'
        if M == 2**(B-2):
            for i in xrange(1, B):
                A[0][i] = '1'
        else:
            b = bin(M)[2:].zfill(B-2);
            for i in xrange(1, B-1):
                A[0][i] = b[i-1];
        for x in A:  print ''.join(x)
    else:
        print 'IMPOSSIBLE'
                
