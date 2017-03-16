#! /usr/bin/env python
#coding=utf-8

import string

f = open(r'e:\B-large.in')
fw = open(r'e:\output2.txt','w')

caseNum = string.atoi(f.readline())
for i in range(caseNum):
    list = f.readline().strip().split()
    A = string.atoi(list[0])
    B = string.atoi(list[1])
    K = string.atoi(list[2])
    if (A > K and B > K):
        result = B*K + (A-K)*K
        for j in range(K,A):
            for k  in range(K,B):
                if(j&k<K):
                    result +=1
    else:
        result = A*B
    fw.write('Case #%d: '%(i+1))
    fw.write('%d\n'%result)
f.close()
fw.close()