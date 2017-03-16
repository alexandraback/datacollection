#!/usr/bin/python

import sys

def checkrow(row):
    winner = None
    if row.count('X') >=3 and row.count('.') == 0 and row.count('O') == 0:
        winner = 'X won'
    elif row.count('O') >=3 and row.count('.') == 0 and row.count('X') == 0:
        winner = 'O won'
    return winner

def main():
    infile = file(sys.argv[1])

    ncases = int(infile.readline().strip())

    for case in xrange(ncases):
        rows = []
        winner = None

        for j in xrange(4):
            rows.append(infile.readline().strip())

        for row in rows:
            if not winner:
                winner = checkrow(row)

        for col in xrange(4):
            column = [row[col] for row in rows]
            if not winner:
                winner = checkrow(column)

        diag = [rows[i][i] for i in xrange(4)]
        if not winner:
            winner = checkrow(diag)

        diag = [rows[i][3-i] for i in xrange(4)]
        if not winner:
            winner =checkrow(diag)

        if not winner:
            for row in rows:
                if '.' in row:
                    winner = "Game has not completed"

        if not winner: winner = "Draw" 
        
        print "Case #%d: %s" % (case+1, winner)
        infile.readline()

        
            






        

        
main()
