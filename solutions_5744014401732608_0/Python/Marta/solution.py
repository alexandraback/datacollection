import numpy as np
import sys
import random

random.seed(0)
T = input()
for case in xrange(T):
    B,M = map(int,raw_input().split())

    sys.stdout.flush()
    print 'Case #'+str(case+1)+":",
    if 2**(B-2) < M:
        print 'IMPOSSIBLE'
    else:
        print 'POSSIBLE'
        a = np.zeros(shape=(B,B),dtype='int')
        p = np.identity(B,dtype='int')
        count = np.zeros(shape=(B,B), dtype='int')
        for i in xrange(B-1):
            p = p.dot(a)
            count += p
        while count[0][B-1] != M:
            i = random.randrange(B-1)
            j = random.randrange(i+1,B)
            a[i,j] = 1 if count[0][B-1] < M else 0
            p = np.identity(B,dtype='int')
            count = np.zeros(shape=(B,B), dtype='int')
            for i in xrange(B-1):
                p = p.dot(a)
                count += p

            #print a

        for r in a:
            print ''.join(map(str,r))
