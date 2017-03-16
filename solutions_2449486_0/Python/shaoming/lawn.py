#!/usr/bin/env python

import sys, os, re

#---------------------------------------------------
# Variable 
#---------------------------------------------------

#---------------------------------------------------
# Function 
#---------------------------------------------------
def get_col(lawn, x):
    return [ row[x] for row in lawn]

def get_row(lawn, y):
    return lawn[y]

def check_lawn(lawn, h, w):
    # buffers
    rows = [ get_row(lawn, y) for y in range(h)]
    cols = [ get_col(lawn, x) for x in range(w)]

    row_max = [ max(r) for r in rows]
    col_max = [ max(c) for c in cols]

    # horizontal 
    for y in range(h):
        for x in range(w):
            target = lawn[y][x]
            if target != row_max[y] and target != col_max[x]:
                return False
    
    return True

def load_file(filename):
    dict = {True:'YES', False: 'NO'}
    with open(filename, 'rU') as f:
        number = int(f.readline())

        for i in range(number):
            h, w = [int(v) for v in f.readline().split()]
            lawn = []
            for y in range(h):
                list = [int(v) for v in f.readline().split()]
                lawn.append(list[0:w])

            result = check_lawn(lawn, h, w)
            print 'Case #%d: %s' % (i+1, dict[result])
            continue

#       for i in range(number):
#           board = [] 
#           for j in range(4): board.append(f.readline().strip())
#           f.readline()
#           result = check_tic(board)
#           print 'Case #%d: %s' % (i+1, dict[result])
    return

#---------------------------------------------------
# Entry Point 
#---------------------------------------------------
def main():
    load_file (sys.argv[1])

    return

#---------------------------------------------------
# Unit Test Entry 
#---------------------------------------------------
if __name__ == '__main__':
    main()


