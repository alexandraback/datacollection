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
    L = []
    Max = 0
    Min = 100
    
    N, M = Input.readints()
    for x in range(N):
        L.append(Input.readints())
        Max = max(Max, max(L[-1]))
        Min = min(Min, min(L[-1]))
    
    LR = []
    
    for x in range(M):
        Row = []
        for y in range(N):
            Row.append(L[y][x])
        LR.append(Row)
            
    for l in range(Max-1, Min-1, -1):
        for n in range(0, N):
            for m in range(0, M):
                if L[n][m] == l:
                    if not(L[n][m] == max(L[n]) or L[n][m] == max(LR[m])):
                        return "NO"
    
    return "YES"
     
            
    
    return "not implemented"







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
    
print time.time() - start_time, "seconds"
