#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

positions = ([[(i, j) for i in xrange(4)] for j in xrange(4)] +
             [[(j, i) for i in xrange(4)] for j in xrange(4)] +
             [[(i, i) for i in xrange(4)]] +
             [[(i, 3-i) for i in xrange(4)]])
    
def check(cells):
    counts = {'X': 0, 'O': 0, '.': 0, 'T': 0}
    for x in cells:
        counts[x] += 1
    if counts['X'] == 4 or (counts['X'] == 3 and counts['T'] == 1):
        return 'X'
    if counts['O'] == 4 or (counts['O'] == 3 and counts['T'] == 1):
        return 'O'

def process(num, fin, fout):
    table = []
    for i in xrange(4):
        table.append(fin.readline().strip())
    fin.readline()
    for pos in positions:
        result = check([table[x][y] for (x,y) in pos])
        if result == 'X':
            fout.write('X won')
            return
        if result == 'O':
            fout.write('O won')
            return
    if '.' in set(''.join(table)):
        fout.write('Game has not completed')
    else:
        fout.write('Draw')
    

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print "Please indicate input and output"
        exit(0)
    fin = open(sys.argv[1], 'r')
    fout = open(sys.argv[2], 'w')
    times = int(fin.readline())
    for i in xrange(times):
        fout.write("Case #%d: " % (i+1))
        process(i, fin, fout)
        fout.write("\n")
    fin.close()
    fout.close()
