import operator
import itertools
import functools
import math

     
fn = open('1.in')
ofn = open('1.out', 'w')
TC = int(fn.readline())
for tc in range(TC):
    r = map(int, fn.readline().strip().split())
    N = r[0]
    S = r[1:]
    ssum = reduce(operator.add, S)
    #print ssum
    aver = float(ssum) / N
    
    negS = []
    posS = []
    for i in xrange(N):
        res = (aver * 2 - S[i]) / ssum * 100
        if res < 0:
            negS.append(i)
        else:
            posS.append(i)
    
    print >>ofn, 'Case #{}:'.format(tc +1),
    
    if len(negS) == 0:        
        for i in xrange(N):
            res = (aver * 2 - S[i]) / ssum * 100
            print >>ofn, res,
        print >>ofn, ''
    else:
        resVec = [0]*N
        ssum2 = 0
        for i in posS:
            ssum2 += S[i]
        for i in posS:
            aver = float(ssum + ssum2) / len(posS)
            resVec[i] = (aver - S[i]) / ssum * 100
        print >>ofn, ' '.join([str(x) for x in resVec])
            
    
    