import sys
import itertools
import time
from files import *
#from PerfectAllocation import PerfectAllocation
from operator import itemgetter
import bisect
import math
from fractions import gcd


sys.setrecursionlimit(1000) #1000 is defaul




def preprocess():

        
    return


def solve_case():
    Answer = ""
    Square = []
    Rows = []
    Empty = False
    
    for f in range(4):
        Square.append(list(Input.readstring()))
        Rows.append(list(Square[-1]))
        if "." in Square[-1]:
            Empty = True
    
    Row1 = []
    Row2 = []
    
    for x in range(4):
        Row1.append(Square[x][x])
        Row2.append(Square[3-x][x])
        
    Rows.append(Row1)
    Rows.append(Row2)
    
    for x in range(4):
        Row1 = []
        for y in range(4):
            Row1.append(Square[y][x])
        Rows.append(Row1)
    
   
    for i in Rows:
        if "O" not in i and "." not in i:
            return "X won"
        if "X" not in i and "." not in i:
            return "O won"
    
    if Empty:
        return "Game has not completed"
    else:
        return "Draw"
    






start_time = time.time()

Input = File("input.txt", "r")
Output = File("output.txt", "w")

n_cases = Input.readint()
preprocess()

for n in range(n_cases):
    solution = solve_case()
    Output.write("Case #" + str(n+1) + ": " + str(solution) + "\n")
    print "Case #" + str(n+1) + ": " + str(solution)

    TOT = (time.time() - start_time) / (n + 1) * n_cases
    if TOT > 120:
        print "Running over two minutes by:", int (TOT - 120), "seconds"
    if n < n_cases - 1:
        Input.readstring()
    
print time.time() - start_time, "seconds"
