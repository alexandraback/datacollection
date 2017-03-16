from os import path, linesep
import itertools

class Option:
    pass

def solve_case(reader):
    """
    Solves one case of this CodeJam task and returns its solution.
    Read a line by calling 
       next(reader)
    """
    N = int(next(reader))
    lvl1req = []
    lvl2req = []
    for i in range(N):
        (r1, r2) = read_intarray(reader)
        lvl1req.append([r1, -r2, i])
        lvl2req.append((r2, i))
    
    lvl1req.sort()
    lvl2req.sort()
    lvl1done = set()
    lvl2done = set()
    
    count = 0
    points = 0
    i1 = 0
    i2 = 0                
                
    while i2 < N:
        oldpoints = points
        if points >= lvl2req[i2][0]:
            lvlid = lvl2req[i2][1]
            if lvlid in lvl1done:
                points += 1
            else: points += 2
            i2 += 1
            count += 1
            lvl2done.add(lvlid)
            continue
        
        if i1 < N:
            lvlid = lvl1req[i1][2]
            if lvlid in lvl2done:
                i1 += 1
                continue
            if points < lvl1req[i1][0]:
                i1 = N
                continue
            points += 1
            i1 += 1
            count += 1
            lvl1done.add(lvlid)
            
        if oldpoints == points:
            break
    
    if i2 == len(lvl2req):
        return str(count)
    return "Too Bad"


# From here on, the fairly generic CodeJam code follows. Read in file, output solutions.
# Potentially the first line does not include number of cases, this may have to be adapted.

def read_intarray(reader):
    return list(map(int, next(reader).split(" ")))

def run_codejam():
    """
    Runs the codejam by initializing input and output, calling methods which solve the cases and finally
    outputting the results.
    """
    testfile = "B-large"
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