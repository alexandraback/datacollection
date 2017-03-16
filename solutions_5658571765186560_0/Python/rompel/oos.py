#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr().split()
def rdints(): return map(int, ssr().split())
def rd1int(): return int(rdline())

ominoes = {}
rich = set()
gabe = set()
dq = ((0,1), (1,0), (0,-1), (-1,0))


def find_ominoes(X):
    if X in ominoes:
        return ominoes[X]
    Z = find_ominoes2(X)
    ominoes[X] = Z
    return Z


def find_ominoes2(X):
    assert X>1
    SS = set()
    S = set([(0,0)])
    L = [ (0,0), [(0,1), (1,0)] ]
    while(L):
        if not L[-1]:
            L.pop()
            S.remove(L.pop())
            continue
        p = L[-1].pop()
        S.add(p)
        if len(L)==2*X-2:
            fs = frozenset(S)
            SS.add(fs)
            S.remove(p)
            continue
        L.append(p)
        l = set()
        (i,j) = p
        for (di,dj) in dq:
            ii = i+di
            jj = j+dj
            pp = (ii,jj)
            if ii>=0 and (ii>0 or jj>0):
                l.add(pp)
        for i in L[1::2]:
            l.update(i)
        L.append(sorted(pp for pp in l if pp not in S))


    # de-dup
    L = []
    nn = len(SS)
    while(SS):
        l = sorted(SS.pop())
        S = set()
        for a in range(2):
            for b in range(4):
                ii = min(i for (i,j) in l)
                jj = min(j for (i,j) in l if i==ii)
                fs = frozenset((i-ii, j-jj) for (i,j) in l)
                if fs not in S:
                    S.add(fs)
                    if (a,b)!=(0,0):
                        SS.remove(fs)
                l = [ (j,-i) for (i,j) in l ]
            l = [ (j,i) for (i,j) in l ]
        L.append(list(S))
                
    if False:
        print "%d oriented %d-ominoes (%d families):" % (nn, X, len(L))
        for l in L:
            fs = l[0]
            print ""
            print len(l), "versions of:"
            r = 1 + max(i for (i,j) in fs)
            A = [ (2*X+1)*[" "] for i in range(r)]
            for (i,j) in fs:
                A[i][X+j] = "*"
            for i in A:
                print " ".join(i)

    O = []
    OF = []
    OD = {}
    for i in range(len(L)):
        l = L[i]
        for fs in l:
            fst = tuple(sorted(fs))
            OD[fst] = len(O)
            O.append(fst)
            OF.append(i)
    return (O, OF, OD)


def solve_one_interesting_case(X, R, C):
    (O, OF, OD) = find_ominoes(X)
    no = len(O)
    nof = len(set(OF))
    N = R*C // X
    assert N>1
    L = [ [0, 0, -1] ]
    S = set()
    A = [ C*[False] for i in range(R) ]
    while L:
        L[-1][2] += 1
        (i, j, k) = L[-1]
        if k>=no:
            L.pop()
            if L:
                (i, j, k) = L[-1]
                l = O[k]
                for (ii,jj) in l:
                    A[i+ii][j+jj] = False
            continue
        l = O[k]
        if any(i+ii>=R or j+jj>=C or j+jj<0 or A[i+ii][j+jj] for (ii,jj) in l):
            continue
        for (ii, jj) in l:
            A[i+ii][j+jj] = True
        if len(L)+1==N:
            e = [ (ii,jj) for ii in range(R) for jj in range(C) if not A[ii][jj] ]
            i0 = min(ii for (ii,jj) in e)
            j0 = min(jj for (ii,jj) in e if ii==i0)
            e = tuple((ii-i0,jj-j0) for (ii,jj) in e)
            if e in OD:
                k = OD[e]
                L.append([i0, j0, k])
                #print L
                S.update(OF[k] for (ii,jj,k) in L)
                if len(S)==nof:
                    return "GABRIEL"
                L.pop()
            #(i, j, k) = L[-1]
            for (ii, jj) in l:
                A[i+ii][j+jj] = False
            continue
        else:
            i = min(ii for ii in range(R) if not all(A[ii]))
            j = min(jj for jj in range(C) if not A[i][jj])
            L.append([i, j, -1])
    if len(S)<nof:
        return "RICHARD"
    else:
        return "GABRIEL"
    #return "UNCLEAR"



def do_one_case(cnum):
    (X, R, C) = rdints()
    ans = solve_one_case(X, R, C)
    print "Case #%d: %s" % (cnum, ans)


def solve_one_case(X, R, C):
    if C>R:
        (R,C) = (C,R)
    if (X,R,C) in rich:
        return "RICHARD"
    if (X,R,C) in gabe:
        return "GABRIEL"
    ans = solve_one_case2(X, R, C)
    if ans=="RICHARD":
        rich.add((X, R, C))
        rich.add((X, C, R))
    elif ans=="GABRIEL":
        gabe.add((X, R, C))
        gabe.add((X, C, R))
    return ans


def solve_one_case2(X, R, C):
    if C>R:
        (R,C) = (C,R)
    if X>=7:
        return "RICHARD"
    if (R*C)%X:
        return "RICHARD"
    if C < (X+1)//2:
        return "RICHARD"
    if R < X:
        return "RICHARD"
    if X<=2:
        return "GABRIEL"    # X==1 or X==2 and R*C even

    if False and X==6 and C==3:
        return "RICHARD"    # seems to be a pattern for now...

    sys.stdout.flush()
    return solve_one_interesting_case(X, R, C)
    
    

def main():
    T = rd1int()
    for i in range(T):
        do_one_case(i+1)
        sys.stdout.flush()


if __name__ == "__main__":
    main()
