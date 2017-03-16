import sys
import itertools
import time
from files import *
#from PerfectAllocation import PerfectAllocation
from operator import itemgetter
import bisect
import math
from fractions import gcd

sys.setrecursionlimit(1000) #1000 is default


PROBLEM = "C"
MODE = 0
# Mode None - solving baby input.
# Mode 0 - solving small input.
# Mode 1 - verifying small input against correct solution.
# Mode 2 - solving large input.

INPUTNAME = PROBLEM + "_baby.txt"
if MODE == 0 or MODE == 1: INPUTNAME = PROBLEM + "-small-1-attempt1.in"
if MODE == 2: INPUTNAME = PROBLEM + "-large.in"
OUTPUTNAME = INPUTNAME[:INPUTNAME.find(".")] + ".out"


def preprocess():
    
    
    return

def solve_case():
    def factor(I):
        A = []
        while I%5 == 0 and I > 0:
            A.append(5)
            I = I / 5
        while I%4 == 0 and I > 0:
            A.append(4)
            A.append(2)
            A.append(2)
            I = I / 5
        while I%3 == 0 and I > 0:
            A.append(3)
            I = I / 5
        while I%2 == 0 and I > 0:
            A.append(2)
            I = I / 5
        return A
        
        
    R, N, M, K = Input.readints()
    
    A = ""
    for x in range(R):
        Answer = ""
        S = Input.readints()
        AllFactors = []
        for t in range(len(S)):
            AllFactors += factor(S[t])
        four = AllFactors.count(4)
        two = AllFactors.count(2)
        if 5 in AllFactors:
            Answer += "5"
        if 3 in AllFactors:
            Answer += "3"
        if len(Answer) < 2:
            if four < two / 4:
                Answer += "22"
            elif four == 2 * two:
                Answer += "24" 
            else:
                Answer += "22"
        else:
            if four >= 2 * two:
                Answer += "4"
            else:
                Answer += "2"
        
        if len(Answer) < 3:
            Answer += "2"
        
        A += "\n" + Answer
        
    return A





start_time = time.time()
Input = File(INPUTNAME, "r")
Correct = None

if MODE == 0 or MODE == 2:
    Output = File(OUTPUTNAME, "w")
if MODE == 1:
    Output = File(OUTPUTNAME, "r")
    Correct = Output.readall()

n_cases = Input.readint()
preprocess()

AllCorrect = True

for n in range(n_cases):
    solution = solve_case()
    if MODE == 0 or MODE == 2:
        Output.write("Case #" + str(n+1) + ": " + str(solution) + "\n")
    print "Case #" + str(n+1) + ": " + str(solution)
    if MODE == 1:
        Result = "Case #" + str(n+1) + ": " + str(solution)
        for line in split(Result, "\n"):
            if len(Correct) == 0 or line.rstrip("\n") <> Correct[0].rstrip("\n"):
                print "MISMATCH: ", line,
                AllCorrect = False 
                if len(Correct) > 0: print Correct[0]
                else: print ""
            if len(Correct) > 0: Correct.pop(0)

    TOT = (time.time() - start_time) / (n + 1) * n_cases
    if TOT > 120:
        print "Running over two minutes by:", int (TOT - 120), "seconds"
    
print time.time() - start_time, "seconds"
if MODE == 1 and AllCorrect == False:
    print "ERRORS WERE FOUND IN SOLUTION"