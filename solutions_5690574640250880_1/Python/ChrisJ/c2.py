#!/usr/bin/python

from __future__ import division

# this code uses numpy

import sys
import numpy

f = sys.stdin

debug = False

T = int(f.readline())


# assuming here that R>=C
# and free >= 4
def fill(R, C, M, free):
    res = numpy.zeros((R, C), dtype=int)
    fullRows = M // C
    Mrem = M - C * fullRows
    if debug: print("ini: fullRows={}, Mrem={}".format(fullRows, Mrem))
    if (C == 2 or R==2) and free%2 == 1:
        return None
    if fullRows < R-3:    # the (not so) easy case
        res[0:fullRows,:] = 1
        cols = min(Mrem, C-2)
        res[fullRows,0:cols] = 1
        Mrem -= cols
        if debug: print("easy: cols={}, still Mrem={}".format(cols, Mrem))
        if Mrem > 1:
            raise(Exception("Error: cols={} Mrem={}".format(cols, Mrem)))
        if Mrem == 1:
            if fullRows < R-3:
                if cols > 0:
                    res[fullRows+1, 0] = 1
                else:
                    res[fullRows, 0] = 1
            else:
                if debug: 
                    print("corner case, fullRows={}, C={}".format(fullRows, C))
                    pr(res)
                    print("---")
                return None
                    
                #res[fullRows, C-3] = 0
                #res[fullRows+1, 0] = 1
                #res[fullRows+2, 0] = 1
        res[R-1,C-1] = 2
        #print("Mrem={}, C={}".format(Mrem, C))
    elif fullRows >= R-2 and (free%2 == 0):
        fullRows = R-2
        Mrem = M - C * fullRows
        res[0:fullRows,:] = 1
        res[fullRows:,0:(C-free//2)] = 1
        res[R-1,C-1] = 2
    elif fullRows >= R-3:
        fullRows = R-3
        Mrem = M - C * fullRows
        res[0:fullRows,:] = 1
        fullCols = (3*C-free)//3
        res[fullRows:,0:fullCols] = 1
        r = (3*C-free) % 3
        if debug: print("fullCols={}, r={}".format(fullCols, r))
        #pr(res)
        if fullCols+r <= C-2:
            for i in range(r):
                res[fullRows,fullCols+i] = 1
            res[R-1,C-1] = 2
        else:
            return None
    else:
        return None
        
    return res


def pr(m):
    cha = ['.', '*', 'c']
    def ch(x):
        return cha[x]
        
    for r in range(m.shape[0]):
        print("".join(map(ch, m[r])))


for index in range(1, T+1):
    print("Case #{}:".format(index))
    
    [R, C, M] = map(int, f.readline().split())
    
    free = R*C - M

    def imp():
        if free not in [2, 3, 5, 7] and not( (C==2 or R==2) and free%2==1 ):
            raise Exception("Should be possible")
        print("Impossible")


    if debug: print("Case #{}: <R={}, C={}, M={}, free={}>".format(index, R, C, M, free))    
    
    if C == 1:
        if free >= 1:
            print("c")
            for i in range(free-1):
                print(".")
            for i in range(M):
                print("*")
        else:
            imp()
    
    elif R == 1:
        if free >= 1:
            print("c" + (free-1)*"." + M*"*")
        else:
            imp()
    
    else:
        if free == 1:
            for i in range(R-1): print(C * "*")
            print((C-1)*"*" + "c")
        elif free >= 4:
            res = fill(R, C, M, free)
            if res == None and R!=C:
                if debug: print("(trying transposed)")
                res = fill(C, R, M, free)
                if res != None:
                    res = res.transpose()
            if res != None:
                pr(res)
                if free in [2, 3, 5, 7]:
                    raise Exception("Should be impossible")
                if numpy.count_nonzero(res == 1) != M:
                    raise Exception("Incorrect number of mines")
                if numpy.count_nonzero(res == 2) != 1:
                    raise Exception("No click")
            else:
                imp()
        else:
            imp()