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


PROBLEM = "A"
MODE = 0
# Mode None - solving baby input.
# Mode 0 - solving small input.
# Mode 1 - verifying small input against correct solution.
# Mode 2 - solving large input.

INPUTNAME = PROBLEM + "_baby.txt"
if MODE == 0 or MODE == 1: INPUTNAME = PROBLEM + "-small-attempt0.in"
if MODE == 2: INPUTNAME = PROBLEM + "-large.in"
OUTPUTNAME = INPUTNAME[:INPUTNAME.find(".")] + ".out"


def preprocess():
    
    return

def solve_case():
    r, t = Input.readints()

    n = 0.25 * (sqrt(4.0 * r * r - 4.0 * r + 8.0 * t + 1) - 2.0 * r - 3.0)
    n = int(floor(n)) + 20
    
    while 2 * n * (n + 1) + 2 * r * (n+ 1 ) + n + 1 > t:
        n -= 1
    
    return n + 1
    
  





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