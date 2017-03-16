from os import path, linesep
import itertools
import math


def solve_case(reader):
    """
    Solves one case of this CodeJam task and returns its solution.
    Read a line by calling 
       next(reader)
    """
    answer = ""
    # TODO solve
    
    votes = read_intarray(reader)[1:]
    votessorted = sorted(set(votes))
    if len(votessorted) == 1:
        return " ".join([str("%.6f" % round(100/len(votes), 6)) for x in votes])
    votessorted.append(5 * max(votes))
    
    result = [0 for x in range(len(votes))]
    minvali = 0
    sumvotes = sum(votes)
    audvotes = sumvotes
    while audvotes > 0:  
        # inc minval
        minvali += 1
        minval = votessorted[minvali]
        
        # get fields which need votes
        count = 0
        for x in votes:
            if x < minval:
                count += 1
        if count == 0:
            count = len(votes)
        
        # increase votes
        votespp = votessorted[minvali] - votessorted[minvali-1]
        if votespp * count > audvotes:
            votespp = audvotes / count
            audvotes = -1
        audvotes -= count * votespp
        for i in range(len(votes)):
            if votes[i] < minval or count == len(votes):
                votes[i] += votespp
                result[i] += votespp
              
                
    for i in range(len(result)):
        result[i] = "%.6f" % (round(result[i]/sumvotes * 100, 6))
    
    answer = " ".join(result)
    return answer    


# From here on, the fairly generic CodeJam code follows. Read in file, output solutions.
# Potentially the first line does not include number of cases, this may have to be adapted.

def read_intarray(reader):
    return list(map(int, next(reader).split(" ")))

def read_floatarray(reader):
    return list(map(float, next(reader).split(" ")))

def run_codejam():
    """
    Runs the codejam by initializing input and output, calling methods which solve the cases and finally
    outputting the results.
    """
    testfile = "A-large"
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