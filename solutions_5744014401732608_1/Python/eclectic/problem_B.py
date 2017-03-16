#!/usr/bin/python3
import sys
import numpy as np

T = int(input())

for i_T in range(T):
    B, M = tuple(map(int, input().split(" ")))
    # print(B,M,2**(B-2))
    if M < 1 or M > 2**(B-2): # possible range
        print("Case #{}: {}".format(i_T+1, 'IMPOSSIBLE'))
        continue
    else:
        print("Case #{}: {}".format(i_T+1, 'POSSIBLE'))

    matrix = np.zeros((B,B), dtype=np.int)
    for i in range(0,B-1):
        matrix[i,i+1] = 1
    if M == 2**(B-2):
        for i in range(0,B-1):
            matrix[i,i+1:] = 1
        for row in matrix:
            print(''.join([str(e) for e in row]))
        continue
    elif M == 1:
        for row in matrix:
            print(''.join([str(e) for e in row]))
        continue

    # print('{0:052b}'.format(M))
    bin_str = '{0:052b}'.format(M).lstrip('0')
    
    exp = len(bin_str)
    pos_first_row = B-exp-2
    # print('bin_str', bin_str, 'exp',exp, 'pos_first_row', pos_first_row)
    for i in range(B-exp-1,B-1):
        matrix[i,i+1:] = 1
    
    # print(matrix)
    # print('res', M-2**(exp-1))
    bin_str = '{0:052b}'.format(M-2**(exp-1)).lstrip('0')
    # print(bin_str)
    first_row = np.array([int(e) for e in bin_str])
    i0 = len(first_row)
    if i0 > 0:
        # print('first_row', first_row, i0, B-1-i0, B-2)
        matrix[pos_first_row,B-1-i0:B-1] = first_row

    # matrix[pos_first_row,B-len(first_row)+i] = e
    # if sum(first_row[1:]) > 0:
    #     for i, e in enumerate(first_row):
    #         matrix[pos_first_row,B-len(first_row)+i] = e
    # print('first_row', first_row)
    # print(matrix)
    # matrix[B-exp-3,B-len(first_row)-1:] = np.array([int(e) for e in bin_str])
    # print(bin_str)

    # while M > 0:
    #     bin_str = '{0:08b}'.format(M)
    #     print(bin_str)
    #     exp = int(np.floor(np.log2(M)))
    #     print('M, exp', M, exp)
    #     M -= 2**exp
    #     for i in range(B-exp-1,B-1):
    #     # print(i, M, 2**i, M // (2**i))
    #         matrix[i,i+1:] = 1
    #     print(matrix)
    # print('possible:', B, M)
    for row in matrix:
        print(''.join([str(e) for e in row]))
