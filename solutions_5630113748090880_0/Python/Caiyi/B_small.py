# -*- coding: utf-8 -*-
"""
Created on Fri Apr 15 21:14:57 2016

@author: caiyi
"""

def write_res(file_name, res):
    with open(file_name,'w') as f:
        res_str = ''
        i = -1
        for i in range(len(res[:-1])):
            res_str += "Case #{}: ".format(i+1)+ str(res[i])+'\n'
        res_str += "Case #{}: ".format(i+2) + str(res[-1])
        f.write(res_str)
from collections import defaultdict
def helper(N, lists):
    D = defaultdict(int)
    for l in lists:
        for i in l:
            D[int(i)] += 1
    res = []
    for key in D:
        if D[key] % 2 != 0:
            res.append(key)
    res.sort()
    return ' '.join([str(i) for i in res])
    


#N = 3
#lists = [
#['1', '2', '3'],
#['2', '3', '5'],
#['3', '5', '6'],
#['2', '3', '4'],
#['1', '2', '3']
#]
#print helper(N, lists)

with open('B-small-attempt0.in') as f:
    lines = f.readlines()[1:]
ind = 0
M = len(lines)
res_total = []
while True:
    N = int(lines[ind].strip()) 
    lists = lines[ind + 1: ind + 2*N]
    lists = [l.strip().split() for l in lists]
    res = helper(N, lists)
    res_total.append(res)
    ind  += 2*N
    if ind >=  M:
        break

write_res('res_B_small.txt', res_total)
