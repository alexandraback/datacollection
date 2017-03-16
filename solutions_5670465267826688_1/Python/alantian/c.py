#!/usr/bin/env pypy3

from collections import OrderedDict
#import numpy as np

unit = ['1','i','j','k']
def unit_ord(a):
    return [i for i,c in enumerate(unit) if c == a][0]

posi_table = [
    ['1','i','j','k'],
    ['i','-1','k','-j'],
    ['j','-k','-1','i'],
    ['k','j','-i','-1'],
    ]

def calc(a,b):
    count_neg = 0

    if a.startswith('-'):
        a = a[1:]
        count_neg += 1

    if b.startswith('-'):
        b = b[1:]
        count_neg += 1

    count_neg = count_neg % 2

    a_ord = unit_ord(a)
    b_ord = unit_ord(b)
    c = posi_table[a_ord][b_ord]

    if c.startswith('-'):
        c = c[1:]
        count_neg += 1

    result = c if count_neg % 2 == 0 else '-' + c

    return result

all_unit = unit + ['-'+u for u in unit]
def all_unit_ord(a):
    return [i for i,c in enumerate(all_unit) if c == a][0]

all_table = OrderedDict()
#int_all_table = np.zeros(shape=(8,8),dtype=int)
int_all_table = [[0]* 8 for _ in range(8)]
for a in all_unit:
    for b in all_unit:
        c = calc(a,b)
        all_table[a,b] = c
        int_all_table[all_unit_ord(a)][all_unit_ord(b)] = all_unit_ord(c)

#print(all_table)
#print(int_all_table)

T = int(input())

for C in range(1,T+1):
    L, X = map(int,input().split())
    S = input()

    X = min(X,16+X%4)
    S = S * X


    #f = np.zeros(shape=(len(S)+1,3,8),dtype=bool)
    f = [[[0]*8 for _1 in range(3) ] for _2 in range(len(S)+1)]
    f[0][0][all_unit_ord('1')] = True
    for i in range(0,len(S)):
        c = all_unit_ord(S[i])
        for l in range(3):
            for a in range(8):
                if f[i][l][a]:
                    f[i+1][l][int_all_table[a][c]] = True
        if f[i][0][all_unit_ord('i')]:
            f[i+1][1][c] = True
        if f[i][1][all_unit_ord('j')]:
            f[i+1][2][c] = True

    answer = f[len(S)][2][all_unit_ord('k')]

    """
    for i in range(0,len(S)+1):
        for l in range(3):
            for a in range(8):
                if f[i][l][a]:
                    print('True',i,l,a,all_unit[a])
    """
    print('Case #%d:'%C,'YES' if answer else 'NO')
