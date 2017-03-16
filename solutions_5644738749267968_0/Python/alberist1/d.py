#!/usr/bin/pypy

def solve():
    N = int(raw_input())
    A = map(float,raw_input().split())
    B = map(float,raw_input().split())
    A.sort()
    B.sort()
    b_ind = 0
    for x in A:
        if x>B[b_ind]:
            b_ind+=1
    a_ind = 0
    for x in B:
        if x>A[a_ind]:
            a_ind+=1
    print b_ind,N-a_ind

if __name__=="__main__":
    T = int(raw_input())
    for i in range(1,T+1):
        print "Case #%d:"%i,
        solve()
