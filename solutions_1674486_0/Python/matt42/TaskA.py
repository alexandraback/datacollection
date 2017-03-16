from os import path, linesep
import itertools
import math
import queue



def solve_case(reader):
    """
    Solves one case of this CodeJam task and returns its solution.
    Read a line by calling 
       next(reader)
    """
    # TODO solve
    N = int(next(reader))
    INH = [read_intarray(reader)[1:] for x in range(N)]
    for i in range(len(INH)):
        for j in range(len(INH[i])):
            INH[i][j] -= 1
    done = set()
    visit = queue.Queue()
    CLO = [[0 for x in range(N)] for y in range(N)]
    for i in range(N):
        CLO[i][i] = 1
    for i in range(N):
        for j in INH[i]:
            CLO[i][j] = 1
    
    for i in range(N):
        visit.put(i)
        
    while not visit.empty():
        i = visit.get()
        if i in done:
            continue
        if not all_visited(INH[i], done):
            visit.put(i)
            continue
        done.add(i)
        # parents derive from same parent?
        cl = [0 for x in range(N)]
        for j in range(N):
            if (i == j):
                continue
            if CLO[i][j] >= 1:
                cl = closure(cl, CLO[j])
        if max(cl) >= 2:
            return "Yes"
        CLO[i] = closure(CLO[i], cl, False)

    return "No"    

def all_visited(inh, visited):
    for i in inh:
        if not i in visited:
            return False
    return True

def closure(A, B, doSum = True):
    C = []
    for i in range(min(len(A), len(B))):
        C.append(A[i] + B[i] if doSum else max(A[i], B[i]))
    return C


# From here on, the fairly generic CodeJam code follows. Read in file, output solutions.
# Potentially the first line does not include number of cases, this may have to be adapted.

def read_intarray(reader):
    return list(map(int, next(reader).split(" ")))

def run_codejam():
    """
    Runs the codejam by initializing input and output, calling methods which solve the cases and finally
    outputting the results.
    """
    testfile = "A-small-attempt1"
    cases_file = path.join(path.dirname(__file__), testfile)
    with open(cases_file + ".in", "r") as reader:
        with open(cases_file + ".out", "w") as cj_output:
            # get a line-based reader
            reader = iter(reader.read().splitlines())
            
            # read number of cases
            caseCount = int(next(reader))
            
            # handle cases (1-based)
            for i in range(1, caseCount+1):
                result = solve_case(reader)
                outputStr = "Case #" + str(i) + ": " + result
                cj_output.write(outputStr + "\n")
                print(outputStr)
        
# run the CodeJam analysis
run_codejam()