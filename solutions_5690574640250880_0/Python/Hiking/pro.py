#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import math
def transpose(matrix):
    return [[matrix[i][j] for i in xrange(len(matrix))] for j in xrange(len(matrix[0]))]

def check_collectness(R, C, M, mat):
    return(
        len(filter(lambda x: x=="*", [item for line in mat[0] for item in line]))==M
        and
        len([item for line in mat[0] for item in line])==R*C
        )

def get_possible_move(R, C, M):
    retlist = (
        rect(R, C, M)+
        no_mine(R, C, M)+
        one_residue(R, C, M)+
        line_1_possible_move(R, C, M)+
        line_2_possible_move(R, C, M)+
        line_3_possible_move(R, C, M)
        )
    tp = line_3_possible_move(C, R, M)
    if tp: retlist.append(transpose(tp[0]))
    return retlist


def no_mine(R, C, M):
    if M==0:
        return [
            [["."]*C]*(R-1)+
            [["c"]+["."]*(C-1)]
        ]
    else: return []

def one_residue(R, C, M):
    if M+1==R*C:
        return [
            [["*"]*C]*(R-1)+
            [["c"]+["*"]*(C-1)]
        ]
    else: return []

def rect(R, C, M):
    i = 0
    deleted = 0
    true_deleted = 0
    while(M>=deleted):
        true_deleted = deleted
        deleted += (R+C-2*i-1)
        i+=1
    deleted = true_deleted
    i-=1
    if min(R-i, C-i) < 3: return []
    residue_bomb = M-deleted
    residue_clear = (R+C-2*i-1) - residue_bomb
    if residue_clear == 1: return []
    rb_R, rb_C = 0, 0
    if residue_bomb == 0:
        rb_R, rb_C = 0, 0
    elif residue_clear >= 4:
        rb_R = min(R-i-2, residue_bomb)
        rb_C = residue_bomb - rb_R + 1
    
    elif rb_R<rb_C:
        rb_R = min(R-i, residue_bomb)
        if(R-i-rb_R==1): return []
        rb_C = residue_bomb - rb_R + 1
    else:
        rb_C = min(C-i, residue_bomb)
        if(C-i-rb_C==1): return []
        rb_R = residue_bomb - rb_C + 1

        
    lastflag = 1 if rb_R == R-i else 0
    #print deleted, residue_bomb, residue_clear, rb_R, rb_C, lastflag
    return [
        [["*"]*C] * i +
        ([["."]*(C-i-rb_C)+["*"]*(i+rb_C)] if rb_C else []) +
        [["."]*(C-i-1)+["*"]*(i+1)]*(rb_R-lastflag-1) +
        [["."]*(C-i)+["*"]*(i)]*(R-rb_R-i-1+lastflag) +
        [["c"]+["."]*(C-i-1-lastflag)+["*"]*(i+lastflag)]
    ]

    
def line_1_possible_move(R, C, M):
    if min([R, C])>1: return []
    maxlen = max([R, C])
    if M+1 > maxlen: return []
    retmat = [["c"]+["."]*(maxlen-M-1)+["*"]*M]
    if R>C: retmat = transpose(retmat)
    return [retmat]

def line_2_possible_move(R, C, M):
    maxlen = max([R, C])
    minlen = min([R, C])
    residue = (R*C-M)
    if maxlen<2: return [] 
    if residue%2 == 1: return []

    needlen = int(residue/2)
    if needlen == 1: return []
    if R>=needlen and C >=2:
        retmat = [transpose(
            [["c"]+["."]*(needlen-1)+["*"]*(R-needlen)]+
            [["."]*(needlen)+["*"]*(R-needlen)]+
            [["*"]*R]*(C-2)
        )]
    elif C>=needlen and R>=2:
        retmat = [
            [["c"]+["."]*(needlen-1)+["*"]*(C-needlen)]+
            [["."]*(needlen)+["*"]*(C-needlen)]+
            [["*"]*C]*(R-2)
        ]
    else:
        retmat = []
    return retmat

def line_3_possible_move(R, C, M):
    if R<3: return []
    fulllen = M/C
    if fulllen >= R - 2: return []
    residue = M - fulllen*C
    #print fulllen
    #print residue
    moreflag = 0
    if residue == C-1:
        if fulllen==0 and R==C:
            if R<=3:
                return []
            retmat = (
                [["*"]*C] * fulllen +
                [["*"]*(residue-1) + ["."]*(C-residue+1)] +
                [["*"] + ["."]*(C-1)] * (1) +
                [["."]*C] * (R-3) +
                [["."]*(C-1) + ["c"]]
            )
            return [retmat]
            #print R, fulllen, residue
        if R-fulllen > residue:
            return []
        residue -= (R-fulllen-1)
        moreflag = 1
    retmat = (
        [["*"]*C] * fulllen +
        [["*"]*residue + ["."]*(C-residue)] +
        [["*"]*moreflag + ["."]*(C-moreflag)] * (R-fulllen-2) +
        [["*"]*moreflag + ["."]*(C-moreflag-1) + ["c"]]
    )
    return [retmat]
    
    
f_input = open(sys.argv[1])
problems = int(f_input.readline().rstrip())
for probnum in xrange(1, problems+1):
    
    R, C, M = map(int, f_input.readline().rstrip().split())
    mat =  get_possible_move(R,C,M)
    #print line_1_possible_move(R,C,M)
    #print line_2_possible_move(R,C,M)
    #print line_3_possible_move(R,C,M)
    print("Case #%i:" % probnum)
    #print mat
    #print R, C, M
    if len(mat):
        #print check_collectness(R,C,M,mat)
        mat = reduce(lambda x,y: x+"\n"+y,
            [reduce(lambda x,y: x+y, line) for line in mat[0]]
        )
    else: mat = "Impossible"
    print(mat)
    
