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

def contains(a, x):
    i = bisect.bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return True
    return False


def preprocess():

    
    return


def solve_case():
    def recourse(Queue, Keys, Ans):
        if len(Queue) == 0:
            return Ans
        
        for x in Queue:
            uKeys = Keys[:]
            for t in Chests[x][1]:
                uKeys[t] += 1
            uKeys[Chests[x][0]] -= 1
            if min(uKeys) >= 0:
                uQueue = Queue[:]
                uQueue.remove(x)
                A = recourse(uQueue, uKeys, Ans + [x])
                if A is not False:
                    return A
        else:
            return False

    
    K, N = Input.readints()
    Key = Input.readints()
    
    Keys = [0] * 201
    for i in Key:
        Keys[i] += 1
        
    Chests = [0]
    
    for _ in range(N):
        t = Input.readints()
        Chests.append((t[0],t[2:]))
        Keys[t[0]] -= 1
        for k in t[2:]:
            Keys[k] += 1
    
    print Chests
    print Keys
    
    
    if min(Keys) < 0:
        return "IMPOSSIBLE"
    
    Queue = range(1, N+1)
    
    Keys = [0] * 201
    for i in Key:
        Keys[i] += 1

    Answer = recourse(Queue, Keys, [])
    
    if Answer == False:
        return "IMPOSSIBLE"
    
    return " ".join(str(x) for x in Answer)  
                
                 

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
