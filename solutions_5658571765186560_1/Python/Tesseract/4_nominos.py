from __future__ import division
from pylab import *
import time
from copy import deepcopy
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

INPUT = "D-large.in.txt"
OUTPUT = "output.txt"
CASE_SEP = ' '

def main():
    cases = parseCases(INPUT, parser, printout=True)
    results = runCases(cases, runCase, printout=True, casesep = CASE_SEP)
    writeResults(OUTPUT, results, casesep = CASE_SEP)
    
def parser(rowsIter):
    return [int(e) for e in rowsIter.next().split(' ')]

def runCase(case):
    X,a,b = case
    R = min(a,b)
    C = max(a,b)
    
    blockPossible = isPossible(X,R,C)
    
    return "RICHARD" if blockPossible else "GABRIEL"

def isPossible(X,R,C):
    if R*C%X!=0:
        return True
    if X>6:
        return True
    if R<ceil(X/2) or C<X:
        return True
    if X<3:
        return False
    
    if X==3:
        assert R>=2 and C>=3
        return False
    if X==4:
        assert R>=2 and C>=4
        if R==2:
            return True
        else:
            return False
    if X==5:
        assert R>=3 and C>=5
        return False
    if X==6:
        assert R>=3 and C>=6
        if R==3:
            return True
        else:
            return False
    else:
        assert False

if __name__=="__main__":
    main()
