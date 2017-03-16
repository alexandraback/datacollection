#
# Google Code Jam 2016
# Roaund 1C: B. Slides
# submission by EnTerr
#

'''
'''


import sys
from time import clock
from collections import defaultdict

f = open(sys.argv[1])
def input(): return f.readline().strip();

       
def slides(B, M):
    '''
    topologic sort - we notice matrix for max.connections matrix
    has to be triangular with 1 above main diagonal and 0 underneath
    (0 to avoid cycles)
       1 2 3 4 5
       ---------
       ( 4 2 1 1)  weight / what a note can contribute
    1| 0 1 1 1 1 
    2| 0 0 1 1 1
    3| 0 0 0 1 1
    4| 0 0 0 0 1
    5| 0 0 0 0 0
    so the maximum we can dial is 2 ^ B-2
    '''
    if M > 2 ** (B-2):
        print 'IMPOSSIBLE'        
    else:
        print 'POSSIBLE'
        last = '0'
        if M == 2 ** (B-2): 
            M -= 1
            last = '1'
        print ('0'*B + bin(M)[2:] + last)[-B:]
        for i in range(2, B+1):
            print '0'*i + '1'*(B-i)
    
    return None


#clk = clock()

for caseNo in xrange(1, int(input())+1):
    #print >>sys.stderr, caseNo
    B, M = map(int, input().split())
    print 'Case #%d:' % caseNo, 
    slides(B, M)
    
#print >>sys.stderr, 'time= %.1f seconds' % (clock()-clk )

