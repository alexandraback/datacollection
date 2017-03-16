import sys
import copy
import numpy as np

def read():
    return sys.stdin.readline()

def format(tup):
    return 'Case #%d: %s'%tup

def do(lawn, n ,m):
    def move(i,j):
        bool_lawn[i,j] = False
        if i > 0 and bool_lawn[i-1,j]:
            move(i-1,j)
        if i < n - 1 and bool_lawn[i+1,j]:
            move(i+1,j)
        if j > 0  and bool_lawn[i,j-1]:
            move(i, j - 1)
        if j < m - 1 and bool_lawn[i,j+1]:
            move(i, j + 1)
        return ''

    for lmin in np.unique(lawn.ravel()):
        bool_lawn = lawn <= lmin 
        for i in xrange(n):
            if bool_lawn[i,0]: move(i,0)
            if bool_lawn[i,m-1]: move(i,m - 1)
        for j in xrange(m):
            if bool_lawn[0,j]: move(0,j)
            if bool_lawn[n-1,j]: move(n - 1,j)
        if bool_lawn.any():
            return "NO"

    return "YES"

#do(np.array([[2, 1, 2], [1, 1, 1], [2, 1, 2]]))
#print do(np.array([[2, 2, 2, 2, 2], [2, 1, 1, 1, 2], [2, 1, 2, 1, 2], [2, 1, 1, 1, 2], [2, 2, 2, 2, 2]]),5,5)
#sys.exit()
for i in xrange(int(read())):
    n, m = map(int,read().split()) 
    lawn = [] 
    for j in xrange(n):
        lawn.append(map(int,read().split()))
    lawn = np.array(lawn)
    print  i+1,n, m
    print lawn
    print  format((i+1,do(lawn, n ,m)))    
    print  "*"*10    
