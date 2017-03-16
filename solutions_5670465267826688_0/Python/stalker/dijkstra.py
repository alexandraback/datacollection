#!/usr/bin/env python3

################################################################################

def read_int():
    return int(input())

def read_words():
    return input().split()

def read_ints():
    return list(map(int,read_words()))

################################################################################

i = 'i'
j = 'j'
k = 'k'

quat = {}

quat[(1,1)] = (1,1)
quat[(1,i)] = (1,i)
quat[(1,j)] = (1,j)
quat[(1,k)] = (1,k)

quat[(i,1)] = (1,i)
quat[(i,i)] = (-1,1)
quat[(i,j)] = (1,k)
quat[(i,k)] = (-1,j)

quat[(j,1)] = (1,j)
quat[(j,i)] = (-1,k)
quat[(j,j)] = (-1,1)
quat[(j,k)] = (1,i)

quat[(k,1)] = (1,k)
quat[(k,i)] = (1,j)
quat[(k,j)] = (-1,i)
quat[(k,k)] = (-1,1)

def mult(q1,q2):
    q3 = quat[(q1[1],q2[1])]
    return (q1[0]*q2[0]*q3[0],q3[1])

def solve(L,X):
    L = "".join([ L for x in range(X) ])

    ident = (1,1)

    cum = ident
    left = ident
    left_idx = -1
    right = ident
    right_idx = -1

    N = len(L)
    for x in range(N):
        lv = (1, L[x])
        cum = mult(cum,lv)
        
        if left_idx == -1 and cum == (1,i):
            left_idx = x
        if right_idx == -1:
            rv = (1, L[N-x-1])
            right = mult(rv,right)
            if right == (1,k):
                right_idx = N-1-x

    return cum == (-1,1) and left_idx < right_idx and left_idx > -1

    


if __name__ == "__main__":
    T = read_int()
    for c in range(T):
        [_,X] = read_ints()
        L = input()
        if solve(L,X):
            R = "YES"
        else:
            R = "NO"
        print("Case #{}: {}".format(c+1,R))
