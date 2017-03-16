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

INPUT = "C-large.in.txt"
OUTPUT = "output.txt"
CASE_SEP = ' '

def main():
    cases = parseCases(INPUT, parser, printout=False)
    results = runCases(cases, runCase, printout=True, casesep = CASE_SEP)
    writeResults(OUTPUT, results, casesep = CASE_SEP)

def parser(rowsIter):
    _, repeat = rowsIter.next().split(' ')
    repeat = int(repeat)
    string = rowsIter.next()
    return string, repeat

def runCase(case):
    origString, repeat = case
    
    total = '1'
    for c in origString:
        total = mult(total, c)
    
    string = origString*min(repeat,8)
    repeat -= 8
    
    res = '1'
    searching='i'
    for c in string:
        res = mult(res, c)
        
        if res==searching:
            if searching=='i':
                searching = 'j'
            elif searching=='j':
                searching = ''
            res = '1'
    
    if repeat>0:
        res = mult(res,power(total,repeat))
    
    possible = searching=='' and res=='k'
    
    #test()
    
    return 'YES' if possible else 'NO'

def power(a,nr):
    nr = nr%4

    if nr==0:
        return '1'
    elif nr==1:
        return a
    elif nr==2:
        return mult(a,a)
    elif nr==3:
        return mult(mult(a,a),a)

def mult(a,b):
    positive = not ((a[0]=='-' or b[0]=='-') and a[0]!=b[0])
    
    a = a[-1]
    b = b[-1]
    
    if a=='1':
        res = b
    elif b=='1':
        res = a
    elif a==b:
        res = '1'
        positive = not positive
    elif a=='i':
        if b=='j':
            res = 'k'
        elif b=='k':
            res = 'j'
            positive = not positive
    elif a=='j':
        if b=='i':
            res = 'k'
            positive = not positive
        elif b=='k':
            res = 'i'
    elif a=='k':
        if b=='i':
            res = 'j'
        elif b=='j':
            res = 'i'
            positive = not positive
    
    return ('-' if not positive else '') + res

def test():
    assert power('1', 1) == '1'
    assert power('1', 2) == '1'
    assert power('1', 3) == '1'
    assert power('1', 4) == '1'
    assert power('1', 5) == '1'

    assert power('-1', 1) == '-1'
    assert power('-1', 2) == '1'
    assert power('-1', 3) == '-1'
    assert power('-1', 4) == '1'
    assert power('-1', 5) == '-1'
    
    assert power('j', 1) == 'j'
    assert power('j', 2) == '-1'
    assert power('j', 3) == '-j'
    assert power('j', 4) == '1'
    assert power('j', 5) == 'j'
    
    assert mult("1", "1") == "1"
    assert mult("1", "i") == "i"
    assert mult("1", "j") == "j"
    assert mult("1", "k") == "k"
    assert mult("i", "1") == "i"
    assert mult("i", "i") == "-1"
    assert mult("i", "j") == "k"
    assert mult("i", "k") == "-j"
    assert mult("j", "1") == "j"
    assert mult("j", "i") == "-k"
    assert mult("j", "j") == "-1"
    assert mult("j", "k") == "i"
    assert mult("k", "1") == "k"
    assert mult("k", "i") == "j"
    assert mult("k", "j") == "-i"
    assert mult("k", "k") == "-1"
    
    assert mult("-1", "-1") == "1"
    assert mult("-1", "-i") == "i"
    assert mult("-1", "-j") == "j"
    assert mult("-1", "-k") == "k"
    assert mult("-i", "-1") == "i"
    assert mult("-i", "-i") == "-1"
    assert mult("-i", "-j") == "k"
    assert mult("-i", "-k") == "-j"
    assert mult("-j", "-1") == "j"
    assert mult("-j", "-i") == "-k"
    assert mult("-j", "-j") == "-1"
    assert mult("-j", "-k") == "i"
    assert mult("-k", "-1") == "k"
    assert mult("-k", "-i") == "j"
    assert mult("-k", "-j") == "-i"
    assert mult("-k", "-k") == "-1"

    assert mult("-1", "1") == mult("1","-1")
    assert mult("-1", "i") == mult("i","-1")
    assert mult("-1", "j") == mult("j","-1")
    assert mult("-1", "k") == mult("k","-1")
    assert mult("-i", "1") == mult("i","-1")
    assert mult("-i", "i") == mult("-1","-1")
    assert mult("-i", "j") == mult("k","-1")
    assert mult("-i", "k") == mult("-j","-1")
    assert mult("-j", "1") == mult("j","-1")
    assert mult("-j", "i") == mult("-k","-1")
    assert mult("-j", "j") == mult("-1","-1")
    assert mult("-j", "k") == mult("i","-1")
    assert mult("-k", "1") == mult("k","-1")
    assert mult("-k", "i") == mult("j","-1")
    assert mult("-k", "j") == mult("-i","-1")
    assert mult("-k", "k") == mult("-1","-1")

    assert mult("1", "-1") == mult("1","-1")
    assert mult("1", "-i") == mult("i","-1")
    assert mult("1", "-j") == mult("j","-1")
    assert mult("1", "-k") == mult("k","-1")
    assert mult("i", "-1") == mult("i","-1")
    assert mult("i", "-i") == mult("-1","-1")
    assert mult("i", "-j") == mult("k","-1")
    assert mult("i", "-k") == mult("-j","-1")
    assert mult("j", "-1") == mult("j","-1")
    assert mult("j", "-i") == mult("-k","-1")
    assert mult("j", "-j") == mult("-1","-1")
    assert mult("j", "-k") == mult("i","-1")
    assert mult("k", "-1") == mult("k","-1")
    assert mult("k", "-i") == mult("j","-1")
    assert mult("k", "-j") == mult("-i","-1")
    assert mult("k", "-k") == mult("-1","-1")
    
    print "----- tests ran successfully"

if __name__=="__main__":
    main()
