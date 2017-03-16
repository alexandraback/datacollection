#!/usr/bin/pypy
import sys

def solve1(a,sm):
    for i in range(1,sm):
        a[i][0] = '.'
    return a

def solve2(a,sm):
    if sm%2 !=0:
        return
    a[0][1] = '.'
    for i in range(1,sm//2):
        a[i][0] = a[i][1] = '.'
    return a

def solve3(a,sm):
    a[0][1] = a[1][0] = a[1][1] = a[0][2] = a[1][2] = a[2][0] = a[2][1] = '.'
    sm -= 8
    for i in range(sm//3):
        a[i+3][0] = a[i+3][1] = a[i+2][2] = '.'
    if sm%3==1:
        a[sm//3+2][2] = '.'
    if sm%3==2:
        a[sm//3+3][0] = a[sm//3+3][1] = '.'
    return a

def solve4(a,sm):
    if len(a)*3>=sm:
        return solve3(a,sm)
    for j in range(len(a[0])):
        for i in range(len(a)):
            if sm and i==0 and j!=0:
                a[0][j] = a[1][j] = '.'
                a[len(a)-1][j-1] = '*'
                sm-=1
            elif sm and i==1 and j!=0:
                a[len(a)-1][j-1] = '.'
                sm-=1
            elif sm:
                a[i][j] = '.'
                sm-=1
    a[0][0] = 'c'
    return a

def check(a,R,C,M):
    assert len(a) == R
    assert tuple(set(map(len,a))) == (C,)
    assert len([x for y in a for x in y if x == '*'])==M
    return True

def solve():
    R, C, M = map(int,raw_input().split())
    need_rotate = R<C
    if need_rotate:
        R, C = C, R
    sm = R*C - M
    a = [['*' for j in range(C)] for i in range(R)]
    a[0][0] = 'c'
    if sm==1:
        pass
    elif C==1:
        a = solve1(a,sm)
    elif sm in (2,3,5,7):
        a = None
    elif sm == 4:
        a[0][1] = a[1][0] = a[1][1] = '.'
    elif sm == 6:
        a[0][1] = a[1][0] = a[1][1] = a[2][0] = a[2][1] = '.'
    elif C==2:
        a = solve2(a,sm)
    elif C==3:
        a = solve3(a,sm)
    else:
        a = solve4(a,sm)
    if a == None:
        print "Impossible"
    else:
        if need_rotate:
            a = zip(*a)
            R,C = C,R
        print '\n'.join(map(''.join,a))
        check(a,R,C,M)

if __name__=="__main__":
    T = int(raw_input())
    for i in range(1,T+1):
        print "Case #%d:"%i
        solve()
