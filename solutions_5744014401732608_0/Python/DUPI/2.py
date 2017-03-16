import os
os.chdir('/Users/mac/OneDrive/competitions/codejam 2016/round2_c/2')
import numpy as np
import math
from collections import defaultdict
import math

##extra_need


def getW(B, M):
    c = 0
    c_dic = defaultdict(int)
    edges = []
    g = {}
    c_dic[B] = 1
    for i in range(2, B+1):
        edges.append((1, i))
    c_dic[1] += 1
    c += 1
    j = B-1
    i = j
    while j >= 2:
        if c >= M:
            break
        if i < 2:
            j -= 1
            i = j
            continue
        xx = False
        for k,v in c_dic.items():
            if k != B and k > 2 and v == M-c:
                edges.append((2, k))
                c += v
                xx = True
                break
        if xx:
            break
        if i >= 2:
            edges.append((i, j+1))
            c_dic[i] += c_dic[j+1]
            c += c_dic[j+1]
            #print c_dic[j+1]
            i -= 1
    
    if c == M:
        s = ''
        e = [['0' for _ in range(B)] for _ in range(B)]
        for i, j in edges:
            e[i-1][j-1] = '1'
        e = [''.join(x) for x in e]
        return 'POSSIBLE' + '\n' + '\n'.join(e)
    else:
        return 'IMPOSSIBLE'
        




##read test.in
test_f = open('./tests/B-small-attempt2.in.txt')
out_f = open('./tests/B-small-attempt2.out.txt', 'w+')
test_num = None
test_case_num = 1
current_rcs = []
for line in test_f:
    if test_num == None:
        test_num = int(line)
    else:
        s = line.strip() 
        B, M = [int(x) for x in line.split()]
        T = getW(B, M)
        #print '{}, {}, {}'.format(max_s, audiences, extra_need) 
        out_f.write('Case #{}: {}\n'.format(test_case_num, T))
        test_case_num += 1
        
test_f.close()
out_f.close()