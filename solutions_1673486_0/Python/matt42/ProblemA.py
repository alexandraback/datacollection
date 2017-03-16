from os import path, linesep
import itertools


def solve_case(reader):
    """
    Solves one case of this CodeJam task and returns its solution.
    Read a line by calling 
       next(reader)
    """
    (A, B) = read_intarray(reader)
    P = read_doublearray(reader)
    
    # find expected hits
    # keep typing, backspace, enter
    strategy = [0, [], 0]
    
    # was correct
    prob = 1.0
    for i in range(A):
        prob *= P[i]
    correct = prob
    
    
    # keep typing
    strategy[0] = ((B-A+1) * correct) + ((B-A+1+B+1) * (1-correct))
    
    # enter
    strategy[2] = (1 + B + 1)
    
    # backspaces
    strategy[1] = calc_backspace(A, B, P, correct)
    
    # min
    strategy[1] = min(strategy[1])
    result = min(strategy)
    return '%.6f'%result

def calc_backspace(A, B, P, correct):
    res = []
    for i in range(A-1, -1, -1):
        correct = correct / P[i]
        finish = B - A + 2 + (A - i)
        exp = correct * finish + (1 - correct) * (finish + B + 1)
        res.append(exp)
    return res


# From here on, the fairly generic CodeJam code follows. Read in file, output solutions.
# Potentially the first line does not include number of cases, this may have to be adapted.

def read_intarray(reader):
    return list(map(int, next(reader).split(" ")))

def read_doublearray(reader):
    return list(map(float, next(reader).split(" ")))

def run_codejam():
    """
    Runs the codejam by initializing input and output, calling methods which solve the cases and finally
    outputting the results.
    """
    testfile = "A-small-attempt0"
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