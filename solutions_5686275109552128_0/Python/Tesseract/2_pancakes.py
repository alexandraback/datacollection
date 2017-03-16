from __future__ import division
from pylab import *
from copy import deepcopy
import time
from pprint import pprint, pformat

'''
input:
    path: path to input file
    parser: function:
        input:
            list of the rows of the input file
        returns:
            one parsed case
        NOTE: only use the lines from the iterator corresponding with current case being parsed
returns:
    list of cases with parsed cases returned by provided parser-function
'''
def parseCases(path, parser, printout=False):
    # get rows without newline from file and make iterator
    with open(path) as fil:
        rows = fil.readlines()
        rows = [row.rstrip() for row in rows]
    rowsIter = iter(rows)
    
    # parse cases
    nrOfCases = int(rowsIter.next())
    parsedCases = [parser(rowsIter) for i in range(nrOfCases)]
    
    # printout if needed
    if printout:
        printSubject("Parsed Cases", pformat(parsedCases))
    return parsedCases

def runCases(cases, runCase, printout=False, casesep='\n'):
    # run
    results = [runCase(case) for case in cases]
    
    # printout if needed
    if printout:
        printResults(results, casesep=casesep)
    return results

def printResults(results, printout=True, casesep='\n'):
    # build string
    resultsString = '\n'.join(["Case #{}:{}{}".format(i+1, casesep, caseResult) for i,caseResult in enumerate(results)])
    
    # printout if needed
    if printout:
        printSubject("Results", resultsString)
    return resultsString

def writeResults(path, results, casesep='\n'):
    with open(path,'w') as fil:
        fil.write(printResults(results, printout=False, casesep=casesep))

def printSubject(title, content):
    title = ' '+title+' '
    dividerLength = max(len(title), 60)
    print "{title:-^{dividerLength}}\n{content}\n{empty:-^{dividerLength}}\n".format(title=title, content=content, dividerLength=dividerLength, empty="")

###########################################################################################################################

INPUT = "B-small-attempt0.in.txt"
OUTPUT = "output.txt"
CASE_SEP = '\n'

def main():
    cases = parseCases(INPUT, parser, printout=True)
    results = runCases(cases, runCase, printout=True, casesep = ' ')
    writeResults(OUTPUT, results, casesep = ' ')
    
def parser(rowsIter):
    rowsIter.next()
    return sort([int(i) for i in rowsIter.next().split(' ')])

def runCase(case):
    r = range(1, case.max()+1)
    solutions = zeros(len(r), dtype=int)
    
    for border in r:
        remaining = deepcopy(case)
        operations = 0
        while True:
            remaining -= border
            remaining = remaining[remaining>0]
            if len(remaining)==0:
                break
            operations += len(remaining)
        solutions[border - 1] = border+operations
    
    res = solutions.min()
    assert res<=case.max()
    return res

if __name__=="__main__":
    main()
