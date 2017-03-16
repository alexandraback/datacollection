# -*- coding: utf-8 -*-
"""
Created on Sun May  8 08:50:28 2016

@author: mattia
"""
import numpy as np

def print_matrix(N, matrix, fout):
    for i in range(N):
        for j in range(N):
            fout.write(str(int(matrix[i,j])))
        fout.write('\n')
        
def find_min_exp(M):
    i = 0
    count = 1
    while M >= count:
        count *= 2
        i += 1
    return i-1
        
def solve(B, M):
    MAT = np.zeros((B, B))
    n = find_min_exp(M)
    for i in range(1, n+2):
        row = B-1-i
        for j in range(row+1, B):
            MAT[row, j] = 1
    if B - (n+2) > 0:
        MAT[0, B - (n+2)] = 1
    diff = M - 2**n
    if diff > 0:
        conv = np.array([int(x) for x in bin(diff)[2:]])
        MAT[0, B-len(conv)-1:-1] = conv
    
    return MAT
            
with open('B-small-attempt0.in', 'r') as fin, open('../submission/b.out', 'w') as fout:
    T = int(fin.readline())
    for case in range(1, T+1):
        B, M = (map(int, fin.readline().split()))
        if M > 2**(B-2):
            fout.write("Case #" + str(case) + ": IMPOSSIBLE\n")
            continue
        else:
            fout.write("Case #" + str(case) + ": POSSIBLE\n")
            print_matrix(B, solve(B, M), fout)