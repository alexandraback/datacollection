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
    r, t = nextints()
    case.r = r
    case.t = t
    return case

def val(r, n):
    return 2*(n**2) + (2*r - 1)*n

def solve(case):
    """
    Solves a single test case, and returns the result.
    """
    r = case.r
    t = case.t
    rings = 0
    
    n = 1
    while val(r, 2*n) <= t:
        n *= 2
        #logging.error("n=%d, val=%d", n, val(r, 2*n))

    a = n
    b = 2*n
    while a < b:
        
        if val(r, a) == t:
            return a
        if val(r, b) == t:
            return b
        if val(r, a+1) < t:
            a += 1
        if val(r, b) > t:
            b -= 1
        
        c = (a+b) // 2
        v = val(r, c)
        logging.error("a=%d, b=%d, c=%d, v=%d", a,b, c, v)
        
        if v == t:
            return c
        elif val(r, c) > t:
            b = c-1
        else:
            a = c
            
    return a

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