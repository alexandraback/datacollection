#!/usr/bin/env python
# -*- coding: utf-8 -*-
def read_lawn(N,M):
    lawn = []
    for i in range(N):
        row = map(int,raw_input().split())
        assert(len(row) == M)
        lawn.append(row)
    return lawn

def solve(lawn,M,N):
    r = [0]*N
    c = [0]*M
    for i in range(N):
        r[i] = max([lawn[i][j] for j in range(M)])
    for j in range(M):
        c[j] = max([lawn[i][j] for i in range(N)])
    pseudo = [ [min(r[i],c[j]) for j in range(M)] for i in range(N) ]
    for i in range(N):
        for j in range(M):
            if pseudo[i][j] <> lawn[i][j]:
                return False
    return True

yesno = {False:'NO', True:'YES'}
T = int(raw_input())
for t in xrange(T):
    N,M = map(int,raw_input().split())
    lawn = read_lawn(N,M)
    print "Case #%d: %s" % (t+1,yesno[solve(lawn,M,N)])
