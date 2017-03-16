import os
import math
import copy
import sys
import numpy as np

def solve(l):
    #print(l)
    s = 0
    mark = 0
    i = 0
    while i<len(l) and mark==0:
        temp = l[i][len(l[i])-1]
        for j in range(len(l)):
            if temp==l[j][0] and i!=j:
                #print(i,j)
                l1 = copy.deepcopy(l)
                conc = l[i]+l[j]
                record = set(conc[0])
                flag = True
                for k in range(1,len(conc)):
                    if conc[k] in record and conc[k]!=conc[k-1]:
                        flag = False
                    record.add(conc[k])
                if flag:
                    l1.insert(i,l[i]+l[j])
                    l1.pop(i+1)
                    l1.pop(j)
                    #print(l[i],l[j])
                    r = solve(l1)
                    #print('l1=',l1)
                    #print(r)
                    mark = 1
                    #print(l[i],l[j])
                    if set(l[i])==set(l[j]) and len(set(l[i]))==1:
                        #print(l,l[i],l[j])
                        s = (s+2*r)%1000000007
                    else:
                        s = (s+r)%1000000007
                    #print('s=',s,'l=',l)
        i = i+1
    if mark==0:
        conc = ''.join(l)
        flag = True
        record = set(conc[0])
        for k in range(1,len(conc)):
            if conc[k] in record and conc[k]!=conc[k-1]:
                flag = False
                #print(k,conc[k])
            record.add(conc[k])
        if flag:
            s = (math.factorial(len(l)))%1000000007
        else:
            s = 0
    return s

os.chdir('C:/Python33/20141C')
f = open('B-small-attempt3.in','r')
fo = open('B-small.out','w')
#f = open('B-large.in','r')
#fo = open('B-large.out','w')
T = int(f.readline())
for ite in range(T):
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': ')
    n = int(f.readline())
    letters = str.split(f.readline())
    for i in range(len(letters)):
        temp = list(letters[i])
        j = 1
        while j<len(temp):
            if temp[j]==temp[j-1]:
                temp.pop(j)
            else:
                j = j+1
        letters[i] = list(temp)
    for i in range(len(letters)):
            letters[i] = ''.join(letters[i])
    dif = 1
    i = 0
    while i<len(letters):
        s = 1
        j = i+1
        while j<len(letters):
            if letters[i]==letters[j] and len(letters[i])==1:
                s = s+1
                letters.pop(j)
            else:
                j = j+1
        dif = dif*math.factorial(s)
        i = i+1
    letters1 = set(letters)
    letters = list(letters1)
    res = solve(letters)*dif
    #print(letters)
    print(res)
    print(ite)
    fo.write(str(res))
    fo.write('\n')
fo.close()

