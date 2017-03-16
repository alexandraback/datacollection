"""Python2- and Python3-compatible. That's all."""
"""Explanation: I tried to analyze the problem (see run()
    and is_divisible() for notes), but failed to find a
    strategy (yes I spotted the word recursive in the ex-
    planation thank you). My best guess for now would be
    that you have to find the solution gradually using
    some kind of dynamic programming magic.
    What I instead did here was implementing a brute-
    force algorithm that checks every possibility that
    has five 0-centers on its path."""
from time import clock
from sys import argv
#import math
#import itertools
#import numpy


#---------------------------------------------
# Code I'm not proud of goes here. :/
# Come on it's Google's fault; (R, C is <= 5)!
#---------------------------------------------

from copy import deepcopy as dc

def punch(grid, x, y, rows, cols, last=False):
    if grid:
        for xi in range(x-1, x+2):
            for yi in range(y-1, y+2):
               if yi > -1 and xi > -1:
                    if yi < rows and xi < cols:
                        grid[yi][xi] = "."
        if last==True:
            grid[y][x] = "c"
        return grid
    return None

def count(grid):
    ret = 0
    for row in grid:
        for x in row:
            if x == "*":
                ret += 1
    return ret

def brute_force(i, rows, cols):
    grid = []
    for y0 in range(rows):
        grid.append([])
        for x0 in range(cols):
            grid[y0].append("*")
            
    for y1 in range(rows):
        for x1 in range(cols):
            for y2 in range(y1-1, y1+2):
                for x2 in range(x1-1, x1+2):
                    for y3 in range(y2-1, y2+2):
                        for x3 in range(x2-1, x2+2):
                            if y2 > -1 and x2 > -1 and y2 < rows and x2 < cols:
                                if y3 > -1 and x3 > -1 and y3 < rows and x3 < cols:
                                    lgrid = dc(grid)
                                    lgrid = punch(lgrid, x1, y1, rows, cols)
                                    lgrid = punch(lgrid, x2, y2, rows, cols)
                                    lgrid = punch(lgrid, x3, y3, rows, cols, last=True)
                                    if lgrid:
                                        if count(lgrid) == i:
                                            return lgrid
    print("uff")
    for y1 in range(rows):
        for x1 in range(cols):
            for y2 in [y1-1, y1, y1+1]:
                for x2 in [x1-1, x1, x1+1]:
                    for y3 in [y2-1, y2, y2+1]:
                        for x3 in [x2-1, x2, x2+1]:
                            for y4 in [y3-1, y3, y3+1]:
                                for x4 in [x3-1, x3, x3+1]:
                                    if y2 > -1 and x2 > -1 and y2 < rows and x2 < cols:
                                        if y3 > -1 and x3 > -1 and y3 < rows and x3 < cols:
                                            if y4 > -1 and x4 > -1 and y4 < rows and x4 < cols:
                                                lgrid = dc(grid)
                                                lgrid = punch(lgrid, x1, y1, rows, cols)
                                                lgrid = punch(lgrid, x2, y2, rows, cols)
                                                lgrid = punch(lgrid, x3, y3, rows, cols)
                                                lgrid = punch(lgrid, x4, y4, rows, cols, last=True)
                                                if lgrid:
                                                    if count(lgrid) == i:
                                                        return lgrid
    print("uffuff")
    for y1 in range(rows):
        for x1 in range(cols):
            for y2 in [y1-1, y1, y1+1]:
                for x2 in [x1-1, x1, x1+1]:
                    for y3 in [y2-1, y2, y2+1]:
                        for x3 in [x2-1, x2, x2+1]:
                            for y4 in [y3-1, y3, y3+1]:
                                for x4 in [x3-1, x3, x3+1]:
                                    for y5 in [y4-1, y4, y4+1]:
                                        for x5 in [x4-1, x4, x4+1]:
                                            if y2 > -1 and x2 > -1 and y2 < rows and x2 < cols:
                                                if y3 > -1 and x3 > -1 and y3 < rows and x3 < cols:
                                                    if y4 > -1 and x4 > -1 and y4 < rows and x4 < cols:
                                                        if y5 > -1 and x5 > -1 and y5 < rows and x5 < cols:
                                                            lgrid = dc(grid)
                                                            lgrid = punch(lgrid, x1, y1, rows, cols)
                                                            lgrid = punch(lgrid, x2, y2, rows, cols)
                                                            lgrid = punch(lgrid, x3, y3, rows, cols)
                                                            lgrid = punch(lgrid, x4, y4, rows, cols)
                                                            lgrid = punch(lgrid,x5,y5,rows,cols,last=True)
                                                            if lgrid:
                                                                if count(lgrid) == i:
                                                                    return lgrid
    print("uffuffuff")
    for y1 in range(rows):
        for x1 in range(cols):
            for y2 in [y1-1, y1, y1+1]:
                for x2 in [x1-1, x1, x1+1]:
                    for y3 in [y2-1, y2, y2+1]:
                        for x3 in [x2-1, x2, x2+1]:
                            for y4 in [y3-1, y3, y3+1]:
                                for x4 in [x3-1, x3, x3+1]:
                                  for y5 in [y4-1, y4, y4+1]:
                                    for x5 in [x4-1, x4, x4+1]:
                                      for y6 in [y5-1, y5, y5+1]:
                                        for x6 in [x5-1, x5, x5+1]:
                                          if y2 > -1 and x2 > -1 and y2 < rows and x2 < cols:
                                            if y3 > -1 and x3 > -1 and y3 < rows and x3 < cols:
                                              if y4 > -1 and x4 > -1 and y4 < rows and x4 < cols:
                                                if y5 > -1 and x5 > -1 and y5 < rows and x5 < cols:
                                                  if y6 > -1 and x6 > -1 and y6 < rows and x6 < cols:
                                                            lgrid = dc(grid)
                                                            lgrid = punch(lgrid, x1, y1, rows, cols)
                                                            lgrid = punch(lgrid, x2, y2, rows, cols)
                                                            lgrid = punch(lgrid, x3, y3, rows, cols)
                                                            lgrid = punch(lgrid, x4, y4, rows, cols)
                                                            lgrid = punch(lgrid, x5, y5, rows, cols)
                                                            lgrid = punch(lgrid,x6,y6,rows,cols,last=True)
                                                            if lgrid:
                                                                if count(lgrid) == i:
                                                                    return lgrid
    print("Not possible")
    return None

#---------------------------------------------

def read(f):
    return next(f).strip("\n")
    
def read_singles(f):
    # returns chars of a word
    # or digits (as strings) of an int
    return list(read(f))
    
def read_int(f, b=10):
    return int(read(f), b)
 
def read_float(f):
    return float(read(f))
 
def read_digits(f, b=10):
    return [int(n, b) for n in read_singles(f)]

#---------------------------------------------

def read_strs(f, s=" "):
    return read(f).split(s)
    
def read_ints(f, b=10, s=" "):
    return [int(n, b) for n in read_strs(f, s)]

def read_floats(f, s=" "):
    return [float(n) for n in read_strs(f, s)]
               
#---------------------------------------------

def read_lines(f, n, reader=read_ints, *args, **kwargs):
    ret = []
    for i in range(n):
        ret.append(reader(f, *args, **kwargs))
    return ret

#---------------------------------------------

def is_divisible(mines, rows, cols):
    """Checks if pattern can be achieved using 'punchouts' (see below)"""
    """edit: just using to cut down on trivial cases
        to improve the brute force now :("""
    cells = rows*cols
    if rows>=3 and cols>=3:
        # if rows<3 and cols<3 brute force is fast anyway
        """Can punch out:
        4, 6, 8(6+(6-4)), 9, 10(6+4), 11(9+(4-2)/9+(6-4)),
        12(9+6-3/9+4-1), 13(9+4), 14(9+(9-4)), 15(9+6)...
        negatives: 1, 2, 3, 5, 7 -> 1 invalid (instant win)
        """
        for target in [2, 3, 5, 7]:
            if mines+target == cells:
                return "impossible"
    if mines == 0:
        null_sol = []
        for y in range(rows):
            null_sol.append([])
            for x in range(cols):
                null_sol[y].append(".")
        null_sol[0][0] = "c"
        return null_sol
    elif mines == cells-1:
        one_sol = []
        for y in range(rows):
            one_sol.append([])
            for x in range(cols):
                one_sol[y].append("*")
        one_sol[0][0] = "c"
        return one_sol
    """These three lines are super effective! 277s->93s!"""
    if (cols==2 and rows>=3) or (rows==2 and cols>=3):
        if mines%2 != 0:
            return "impossible"
    return "permission"

def run(data):
    rows, cols, mines = data
    """So this problem is essentially asking:
        Construct a field using only 3x3-grids as punchouts.
        The grids' centers must be within the minefield (i.e.
        allows for 2x2 at the corners, 2x3 and 3x2 at the edges)."""
    cells = rows*cols
    pre_judgement = is_divisible(mines, rows, cols)
    if pre_judgement == "impossible":
        return None
    elif pre_judgement == "permission":
        return brute_force(mines, rows, cols)
    else:
        return pre_judgement
        

#---------------------------------------------

def read_case(f):
    return read_ints(f)

def write_case(f, i, sol, last=False):
    f.writelines("Case #"+str(i+1)+":\n")
    addendum = "\n"
    if last==True:
        addendum = ""
    if sol:
        for row in sol:
            sol_string = ""
            for element in row:
                sol_string += element
            f.writelines(sol_string+"\n")
    else:
        f.writelines("Impossible"+addendum)

#---------------------------------------------

def main():
    f = open(argv[1])
    f2 = open(argv[2], "wt")
    for i in range(read_int(f)-1):
        print("Init case "+str(i+1)+".")
        write_case(f2, i, run(read_case(f)), last=False)
        print("Finished in "+str(clock())+".")
    write_case(f2, i+1, run(read_case(f)), last=True)
    f.close()
    f2.close()

if __name__ == "__main__":
    main()
