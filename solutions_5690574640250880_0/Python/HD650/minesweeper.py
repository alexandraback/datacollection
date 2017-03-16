import os, sys, math
import numpy as np

infile = sys.stdin
#infile = open('small')

g_rev = False

def solve(case_num, R, C, M):
    print "Case #%d:" % case_num
    if M == 1:
        return print_mat(R, C, 1, 1)
    if R == 1:
        return print_mat(R, C, 1, M)
    if M in [2, 3, 5, 7]:
        print "Impossible"
        return
    if R == 2:
        if M % 2 == 1:
            print "Impossible"
            return
        else:
            return print_mat(R, C, 2, M / 2)

    if M == 4:
        return print_mat(R, C, 2, 2)
    if M == 6:
        return print_mat(R, C, 2, 3)

    
    mat = list()
    for i in xrange(R):
        mat.append(['*'] * C)

    for i in xrange(3):
        mat[i][0:3] = ['.'] * 3
    mat[2][2] = '*'

    M -= 8

    if M > 0:
        x = (C - 3) * 2
        cur = min(M / 2 * 2, x)

        if x <= M / 2 * 2:
            w = x / 2 + 1
        else:
            w = M / 2 + 1

        for i in xrange(cur / 2):
            mat[0][3+i] = '.'
            mat[1][3+i] = '.'
        M -= cur
        

    if M > 0:
        x = (R - 3) * 2
        cur = min(M / 2 * 2, x)
        for i in xrange(cur / 2):
            mat[3 + i][0] = '.'
            mat[3 + i][1] = '.'
        M -= cur

    idx = 0
    r = 2
    while M > 0:
        if idx == w:
            r += 1
            idx = 0
            continue
        mat[r][2+idx] = '.'
        idx += 1
        M -= 1

    if g_rev:
        mat = np.array(mat).T

    mat[0][0] = 'c'
    for line in mat:
        print ''.join(line)

def print_mat(row, col, r, c):
    if g_rev:
        row, col = col, row
        r, c = c, r

    mat = list()
    for i in xrange(row):
        mat.append(['*'] * col)

    for i in xrange(0, r):
        mat[i][0:c] = ['.'] * c
        
    mat[0][0] = 'c'
    for line in mat:
        print ''.join(line)


if __name__ == "__main__":
    T = int(infile.readline())
    for i in xrange(T):
        R, C, M = [int(v) for v in infile.readline().split()]
        if R > C:
            R, C = C, R
            g_rev = True
        else:
            g_rev = False
        solve(i+1, R, C, R * C - M)
