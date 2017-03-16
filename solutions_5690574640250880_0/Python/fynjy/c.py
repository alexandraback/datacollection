#!/usr/bin/python

import sys;
import os.path; 

def readi():
    return int(sys.stdin.readline().strip());

def readia():
    return [int(x) for x in sys.stdin.readline().strip().split()];

def readfa():
    return [float(x) for x in sys.stdin.readline().strip().split()];

def trace(x):
    #print x;
    pass;

def produceMines(R, C, M):
    #if isTransposed:
    #    tmp = R;
    #    R = C;
    #    C = tmp;
    #    tmp = cr;
    #    cr = cc;
    #    cc = tmp;

    field = [['.'] * C for r in range(R)]
    for m in range(M):
        field[m / C][m % C] = '*';
    #print field, cr, cc;
    #field[cr][cc] = 'c';
    #return '\n'.join(''.join(r) for r in field);
    return field;

def fieldToString(field, isTransposed):
    if not field:
        return None;

    if isTransposed:
        R = len(field);
        C = len(field[0]);
        field2 = [['.'] * R for r in range(C)];
        for r in range(R):
            for c in range(C):
                field2[c][r] = field[r][c];
        field = field2;
    return '\n'.join(''.join(r) for r in field);

def addStart(field, cr, cc):
    field[cr][cc] = 'c';
    return field;

def decide(R, C, M):
    if C == 1:
        trace("C == 1");
        return addStart(produceMines(R, C, M), R - 1, C - 1);

    if M == R * C - 1:
        trace("M == R * C - 1");
        return addStart(produceMines(R, C, M), R - 1, C - 1);

    # M = C * n + r;
    numFilledRows = M / C;
    numPartialRows = 1 if M % C != 0 else 0;
    numMinesInPartialRow = M % C;
    numRowsWithMines = numFilledRows + numPartialRows;

    if numRowsWithMines >= R - 1: 
        trace("numRowsWithMines >= R - 1 -> fail");
        return None;

    trace("numRowsWithMines < R - 1");

    if numPartialRows == 0:
        trace("numPartialRows == 0");
        return addStart(produceMines(R, C, M), R - 1, C - 1);

    trace("have partial row");

    if numMinesInPartialRow <= C - 2:
        trace("numMinesInPartialRow <= C - 2");
        return addStart(produceMines(R, C, M), R - 1, C - 1);

    trace("numMinesInPartialRow == C - 1");

    if numRowsWithMines <= R - 3 and C >= 3:
        trace("numRowsWithMines <= R - 3");
        field = addStart(produceMines(R, C, M - 1), R - 1, C - 1);
        field[numRowsWithMines][0] = '*';
        return field;

    trace("numRowsWithMines > R - 3 -> fail");
    return None;

def getHoleDimensions(R, C, M):
    holeSize = R * C - M;
    for sizeR in xrange(2, min(R, holeSize / 2) + 1):
        sizeC = holeSize / sizeR;
        trace("check : r = %d, c = %d" % (sizeR, sizeC));
        if sizeC > C:
            continue;
        leftover = holeSize % sizeR;
        trace("check : r = %d, c = %d, left = %d" % (sizeR, sizeC, leftover));
        if leftover != 1:
            trace("got hole dimensions: r = %d, c = %d, left = %d" % (sizeR, sizeC, leftover));
            return (sizeR, sizeC, leftover);
    trace("Couldn't find hole for %d %d %d, hole size %d" % (R, C, M, holeSize));    
    return None;

                
def makeHole(R, C, holeDims):
    if not holeDims:
        return None;

    (sizeR, sizeC, leftover) = holeDims;

    field = [['*'] * C for r in range(R)]
    for r in xrange(sizeR):
        for c in xrange(sizeC):
            field[r][c] = '.';

    if sizeR < R:
        if leftover > sizeC:
            print("BAD: leftover > sizeC");
        for c in range(leftover):
            field[sizeR][c] = '.';
    else:
        if leftover > sizeR:
            print("BAD: if leftover > sizeR");
        for r in range(leftover):
            field[r][sizeC] = '.';

    field[0][0] = 'c';       
    return field;

        
def main():
    nt = readi();
    for c in range(1, nt+1):
        trace("");
        (R, C, M) = readia();
        trace("%d %d %d" % (R, C, M));
        trace("checking normal");
        isTransposed = False;
        field = decide(R, C, M);
        if not field and R != C:
            trace("checking transposed");
            isTransposed = True;
            field = decide(C, R, M);

        if not field:
            #if R == 1 or C == 1:
            #    field = addStart(produceMines(R, C, M), R - 1, C - 1);
            #else:
            isTransposed = False;
            holeDims = getHoleDimensions(R, C, M);
            field = makeHole(R, C, holeDims);

        res = fieldToString(field, isTransposed);
        if not res:
            res = "Impossible";
            #res = "Impossible %d %d %d" % (R, C, M);

        print "Case #%d: " % c;
        print res;
    

main();
