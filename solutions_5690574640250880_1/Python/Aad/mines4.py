
from itertools import *
import sys
import random

debug = False

def log(*argv):
    if debug:
        print " ".join(imap(str, argv))

def print_full(i, r, c, t):
    print "Case #" + str(i) + ":"
    print "c" + t*(c-1)
    for _ in xrange(r-1):
        print t*c

def adj(p, R, C):
    t = [(p[0]+1, p[1]), (p[0], p[1]+1), (p[0]-1, p[1]), (p[0], p[1]-1), (p[0]-1, p[1]+1), (p[0]-1, p[1]-1), (p[0]+1, p[1]+1), (p[0]+1, p[1]-1)]
    return filter(lambda (x,y): x>=0 and y>=0 and x<R and y<C, t)

def fill_mines(R,C,M):
    l = []
    a = [(0,0)]
    if M == 0:
        return []
    c = C-1
    r = R-1
    l.append((0,0))
    for i in range(M-1):
        log("c, r :", c,r)
        if c < r:
            l.append((R-r,0))
            r -= 1
        else :
            l.append((0,C-c))
            c -= 1
    log("end l :", l)
    #check if valid
    tc = [[0]*C for i in xrange(R)]
    for p in l:
        tc[p[0]][p[1]] = '*'
        a = adj(p, R, C)
        for pa in a:
            if tc[pa[0]][pa[1]] != '*':
                tc[pa[0]][pa[1]] = tc[pa[0]][pa[1]] + 1
    for line in tc:
        log(line)
    for i in xrange(R):
        for j in xrange(C):
            if tc[i][j] != '*':
                for pa in adj((i,j), R, C):
                    if tc[pa[0]][pa[1]] == 0:
                        break
                else:
                    raise Exception("impossibru!!!")
    return l

def main(f, case):
    R, C, M = map(int, f.readline().split())
    F = R*C-M
    log("begin R,C,M,F :", R, C, M, F)
    if M == 0:
        print_full(case, R, C, ".")
        return
    if M == R*C-1:
        print_full(case, R, C, "*")
        return
    if R==1:
        print "Case #" + str(case) + ":"
        print "*"*M + "."*(C-M-1) + "c"
        return
    if C==1:
        print "Case #" + str(case) + ":"
        print "*\n"*M + ".\n"*(R-M-1) + "c"
        return
    if F < 4:
        print "Case #" + str(case) + ":"
        print "Impossible"
        return
    t = [['.']*C for i in xrange(R)]
    m = M
    r = R
    c = C
    i = 0
    while r >= 2 and c >= 2 and (m >= r or m >= c):
        if r < c:
            for j in range(r):
                t[j+R-r][i+C-c] = '*'
            m -= r
            c -= 1
        else:
            for j in range(c):
                t[i+R-r][j+C-c] = '*'
            m -= c
            r -= 1
    log("new value r c m :", r, c, m)
    try:
        l = fill_mines(r,c,m)
        log("l :", l)
        for p in l:
            t[p[0]+R-r][p[1]+C-c] = '*'
        t[R-1][C-1] = 'c'
        print "Case #" + str(case) + ":"
        for line in t:
            print ''.join(line)
    except:
        print "Case #" + str(case) + ":"
        print "Impossible"

with open(sys.argv[1]) as f:
    N = int(f.readline())
    for i in xrange(N):
        main(f, i+1)
