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

def left_find(val, L):
    for x in range(len(L)):
        val = mult(val,(1,L[x]))
        if val == (1,i):
            return x
        
def right_find(val, L):
    N = len(L)
    for x in range(N):
        val = mult((1,L[N-x-1]),val)
        if val == (1,k):
            return x

def try_to_find_index(f, L, cum):
    loop = 0
    start = (1,1)
    idx = f(start,L)
    tried = set(start)
    while idx is None:
        start = mult(start,cum)
        loop += 1
        if start in tried:
            return None
        tried.add(start)
        idx = f(start,L)

    return loop * len(L) + idx

def exp(cum,x):
    if x == 0:
        return (1,1)
    
    v = exp(cum, x//2)
    v = mult(v,v)

    if x % 2 == 1:
        return mult(v,cum)
    else:
        return v
        
        
def solve(L,X):
    ident = (1,1)

    cum = ident
    for x in L:
        cum = mult(cum,(1,x))

    C = exp(cum,X)
    # C = ident
    # for x in range(X):
    #     C = mult(C,cum)

    if C != (-1,1):
        return False

    li = try_to_find_index(left_find, L, cum)
    ri = try_to_find_index(right_find, L, cum)

    return not(li is None or ri is None or li >= (len(L)*X - ri - 1))



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
