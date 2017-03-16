# -*- coding: utf-8 -*-
"""
Created on Fri Apr 15 21:14:57 2016

@author: caiyi
"""

def write_res(file_name, res):
    with open(file_name,'w') as f:
        res_str = ''
        for i in range(len(res[:-1])):
            res_str += "Case #{}: ".format(i+1)+ str(res[i])+'\n'
        res_str += "Case #{}: ".format(i+2) + str(res[-1])
        f.write(res_str)
from collections import deque
def helper(S):
    if S == '': return S
    
    Q = deque()
    left = S[0]
    Q.append(S[0])
    for l in S[1:]:
        if left > l:
            Q.append(l)
        else:
            left = l
            Q.appendleft(l)
    res = ''.join(list(Q))
    return res

### small test
#strs= [
#'CAB',
##'JAM',
#'CODE',
#'ABAAB',
#'CABCBBABC',
#'ABCABCABC',
#'ZXCASDQWE'
#]
#for S in strs:
#    print helper(S)

with open('A-large.in') as f:
    str1 = f.read()
    strs = str1.strip().split('\n')[1:]
res_total = []
for S in strs:
    print "S", S
    res = helper(S)
    print 'res', res
    res_total.append(res)

write_res('res_A_large.txt', res_total)
