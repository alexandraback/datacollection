from functools import *
from itertools import *

#f = open('B.in')
#def input():
#    return next(f)

import re

for x in range(1, int(input()) + 1):
    K, L, S = map(int, input().split())
    keys, tar = input().strip(), input().strip()
    total = ctr = maxi = 0
    matcher = re.compile('(?=' + tar + ')')
    for typed in product(keys, repeat=S):
        typed = ''.join(typed)
        occ = matcher.subn('', typed)[1]
        #occ = 0
        #for i in range(S):
        #    if typed[i:i+L] == tar:
        #        occ += 1
        total += occ
        ctr += 1
        maxi = max(maxi, occ)
#        print(typed, occ, tar, L)
#    print(maxi, total, ctr, maxi - total/ctr)
#    print('Case #%d:' % x, K, L, S, keys, tar)
    print('Case #%d:' % x, maxi - total/ctr)
