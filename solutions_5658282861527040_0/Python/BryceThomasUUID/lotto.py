import fileinput
import sys
from itertools import groupby
import math
import numpy as np

cases = int(sys.stdin.readline())
for i in range(1, cases + 1):
    A, B, K = map(int, sys.stdin.readline().strip().split(' '))
    
    possible_lotto_results = []
    for j in range(A):
        for k in range(B):
            #print 'adding ', i, 'and', j
            possible_lotto_results.append((j & k))
    #sys.exit(1)
    #print >> sys.stderr, 'possible_lotto_results len:', len(possible_lotto_results)
    kates_possible_winners = [res for res in possible_lotto_results if res < K]
    #print kates_possible_winners
    #sys.exit(1)
    print 'Case #' + str(i) + ': ' + str(len(kates_possible_winners))
    
