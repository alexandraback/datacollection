#!/usr/bin/env python
#
# Problem: Good Luck
# Language: Python
# Author: KirarinSnow
# Usage: python thisfile.py <input.in >output.out


from itertools import *

raw_input()
r, n, m, k = map(int, raw_input().split())
print "Case #1: "
q = [i for i in combinations_with_replacement('8765432',12)]
qq = filter(lambda x: x.count('2')+x.count('4') <= 1, q)
w = map(lambda x: eval('*'.join(list(x))), qq)

for case in range(r):
    z = map(int, raw_input().split())

 #   q = ['555', '554', '553', '552', '544', '543', '542', '533', '532',
 #        '444', '443', '442', '433', '432', '333', '332']

#    print qq[0]
#    w = map(lambda x: eval('*'.join(list(x))), qq)
    
    for i in range(len(qq)):
        if w[i] in z:
            ans = ''.join(q[i])
            break
    else:
        ans = 444422225555
    
#    ans = 3    
    print ans
