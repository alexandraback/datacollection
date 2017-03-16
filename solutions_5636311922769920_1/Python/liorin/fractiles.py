# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>
from __future__ import division
import sys
import math

# <codecell>

num_cases = sys.stdin.readline()

"""every selected tile gives us info about c tiles in the original sequence
   therefore, we need ceil(k/c) students """

def split_the_list(l, c):
    ret = []
    tmp = []
    count = 0
    for x in l:
        tmp.append(x)
        count += 1
        if count == c:
            ret.append(tmp)
            count = 0
            tmp = []
    #if the length of the list is not divisible by c, we need to manually add the last segment
    if count != 0:
        ret.append([tmp[0]]*(c-len(tmp)) + tmp)
    return ret

def decode_pos(l,k):
    """given a list of c positions a_1,...,a_c 
       find the position in the artwork of the complexity c that corresponds to it:
       that is the a_c-th position in the segment generated from the a_{c-1}-th position 
       from the previous artwork...
       would be better to write this in a nice functional way"""
    if len(l) == 1:
        return l[0]
    else: #len(l > 1)
        return l[-1] + k*(decode_pos(l[:-1],k)-1)
    
def solve(k,c,s):
    if (s < math.ceil(k/c)):
        return []
    if (s == k): #not really necessary
        return range(1,s+1)
    return [decode_pos(l, k) for l in split_the_list(range(1,k+1), c)]


for num, line in enumerate(sys.stdin):
    k, c, s = [int(x) for x in line.split()]
    l = solve(k,c,s)
    out = "Case #{0}:".format(num+1)
    for x in l:
        out += " {0}".format(x) 
    if not l:
        out += " IMPOSSIBLE"
    print out

# <codecell>


