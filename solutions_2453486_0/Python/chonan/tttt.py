#! /usr/bin/env python3
# -*- coding: utf8 -*-
# vim: expandtab ts=4 ai

from functools import reduce

DIC = { 'X':1, 'O':2, 'T':3, '.':0 }
CONDS = [
    [ 0, 1, 2, 3], [ 4, 5, 6, 7], [ 8, 9,10,11], [12,13,14,15],
    [ 0, 4, 8,12], [ 1, 5, 9,13], [ 2, 6,10,14], [ 3, 7,11,15],
    [ 0, 5,10,15], [ 3, 6, 9,12]
]

def do_calc(query):
    for c in CONDS:
        cond_seq = [ query[x] for x in c ]
        seq_judge = reduce(lambda x,y: x&y,cond_seq)

        if seq_judge == 1:
            return 'X won'
        if seq_judge == 2:
            return 'O won'

    if reduce(lambda x,y: x*y,query) == 0:
        return 'Game has not completed'
    else:
        return 'Draw'


def main():
    for c in range(int(input())):
        query = ""
    
        while( len(query)<16 ):
            query += input()
            
        judge = do_calc([ DIC[x] for x in query])
     
        print('Case #%d: %s' % ( c+1, judge ))

if __name__ == '__main__':
    main()
