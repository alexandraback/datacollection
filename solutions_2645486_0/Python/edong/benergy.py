"""
Problem: $PROBLEM


This script was written for Python 3.3.
It
 * reads from standard input
 * writes to standard output
 * logs to standard error

@author: edong
"""

# Python built-in libraries
import itertools
import logging
import math
import sys

# External libraries
# NumPY <http://www.numpy.org/>
#import numpy

# Log to standard error
#level=logging.DEBUG
level=logging.INFO
logging.basicConfig(stream=sys.stderr, level=level, \
                    format='%(asctime)s %(levelname)-7s %(message)s')

class TestCase(object):
    """
    Container for the inputs of a test case.
    """
    def __init__(self):
        pass
    
    def __str__(self):
        """
        Returns a representation.
        """
        return str(self.__dict__)
    
def parse_test_case():
    """
    Parses the inputs for a test case from standard input
    and returns the result.
    """
    case = TestCase()
    case.maxe, case.r, case.n = nextints()
    case.values = nextints()
    
    return case

def calcscore(state, values):
    total = 0
    for s, v in zip(state, values):
        total += s*v
    return total

def calcenergy(state, maxe, r):
    total = maxe
    for s in state:
        if not s:
            continue
        total = min(total - s + r, maxe)
    return total

def minfortail(state, r, k):
    minreq = r
    for i in range(len(state)-1, k, -1):
        if minreq == 0:
            minreq = state[i]
        else:
            # TODO: Check the second half of this
            minreq = max(1, state[i] + minreq - r)
    return minreq
    
def solve(case):
    """
    Solves a single test case, and returns the result.
    """
    maxe = case.maxe
    r = case.r
    n = case.n
    values = case.values
    
    e = case.maxe
    score = 0
    
    state = [0 for v in values]
    logging.info("Starting state: %s", state)
    
    while True:
        next = None
        maxval = None
        potential = None
        e = case.maxe
        logging.debug("State: %s", state)
        
        for i in range(n):
            # How much I can add to the current value without ruining the rest
            m = minfortail(state, r, i)
            
            p = e - state[i] - max(0, m-r)
            
            logging.debug("i=%d, e=%d, m=%d, p=%d", i, e, m, p)
            if p > 0 and (next is None or values[i] > maxval):
                next = i
                maxval = values[i]
                potential = p
                
            e = min(e - state[i] + r, maxe)
        
        if next is None:
            break
        state[next] += potential
    
    return calcscore(state, values)
    
##############################################################
# Utility functions
        
def nextstr():
    """
    Returns the next line from standard input,
    without any trailing newlines.
    """
    l = sys.stdin.readline()
    if l[-1] == '\n':
        l = l[:-1]
    return l
    
def nextint():
    """
    Returns the next line from standard input as an integer.
    """
    return int(nextstr())

def nextints():
    """
    Returns the next line from standard input as a list of integers,
    where the input is split by ' '.
    """
    return [int(t) for t in nextstr().split(' ')]
    
def main():
    """
    Main function.
    """
    
    # Log module filename
    mainmod = sys.modules['__main__']
    if mainmod and hasattr(mainmod, '__file__'):
        logging.info("Running %s", mainmod.__file__)

    import time
    start_time = time.time()
    
    num_cases = nextint()

    for i in range(1, num_cases+1):
        test_case_start_time = time.time()
        case = parse_test_case()
        logging.info("Case #%d has inputs: %s", i, case)
        output = solve(case)
        print("Case #{}: {}".format(i, output))
        test_case_end_time = time.time()
        logging.info("Case #%d has output: %s", i, output)
        logging.debug("Case #%d running time: %0.1f s", \
                     i, test_case_end_time-test_case_start_time)
    sys.stdin.close()
    
    end_time = time.time()
    logging.info("Total running time: %0.1f s for %d test cases", \
                 end_time-start_time, num_cases)

if __name__ == '__main__':
    main()