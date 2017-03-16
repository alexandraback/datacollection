#Template code developed by Brett Olsen (brett.olsen@gmail.com), 2013
#for the Google Code Jam programming contest

###############################################################################
# Imports go here
###############################################################################

import numpy as np
from scipy import special
import math
import itertools
import collections
import functools

###############################################################################
# Global variables (for caching, etc.) go here
###############################################################################

#Set up the input/output files: problem-tagsuffix.in / *.out
problem = "A"

#tag = "small" #commonly sample, small, or large
tag = "large"
#tag = "sample"

#suffix = "-attempt0" #used sometimes for indexing later input files
#suffix = "-2"
suffix = ""

###############################################################################
# Decorators
###############################################################################

class memoize(object):
   """Decorator. Caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned
   (not reevaluated).
   """
   def __init__(self, func):
      self.func = func
      self.cache = {}
   def __call__(self, *args):
      if not isinstance(args, collections.Hashable):
         # uncacheable. a list, for instance.
         # better to not cache than blow up.
         return self.func(*args)
      if args in self.cache:
         return self.cache[args]
      else:
         value = self.func(*args)
         self.cache[args] = value
         return value
   def __repr__(self):
      '''Return the function's docstring.'''
      return self.func.__doc__
   def __get__(self, obj, objtype):
      '''Support instance methods.'''
      return functools.partial(self.__call__, obj)

###############################################################################
# Functions
###############################################################################

def precalculate():
    """Perform any calculations that need to be performed before the main path
    (e.g., preparing lookup tables, etc.)
    
    N.B. Make sure you make any important variables global so that other
    functions can access them.
    """
    
    pass

def read_input(infile):
    """This function should take an open input file, load in all of the
    relevant information for a single case of the problem, and output it
    as a single object.    
    """
    #Some utility functions to read in particular types of input
    def read_int():
        return int(infile.readline().strip())
    def read_ints():
        return np.array(infile.readline().split(), dtype=int)
    def read_bigints():
        line = infile.readline().split()
        return np.array(map(lambda x: int(x), line))
    def read_float():
        return float(infile.readline().strip())
    def read_floats():
        return np.array(infile.readline().split(), dtype=float)
    def read_string():
        return infile.readline().strip()
    def read_strings():
        return np.array(infile.readline().split(), dtype=object) #change the dtype?
    
    r, t = read_ints()
    
    return r, t


def how_much_paint(r, k):
    """How much paint is needed to paint k black rings starting at radius r?
    """
    return 2 * r * k + k * (2 * k - 1)

def solve_case(case):
    """Take the input data (structured in case) and perform any necessary
    calculations to obtain the desired output, formatted as the appropriate
    string.    
    """
    
    r, t = case
    
    #Do a one-sided binary search on k to find the maximum number of rings
    #possible with how much paint we have
    
    #Initialize the number of rings to 1
    k_low = 0
    k_high = 1
    
    #First we find the interval by incremental doubling
    while how_much_paint(r, k_high) <= t:
        k_low = k_high
        k_high *= 2
        
    #Then we binary search in that interval
    while k_high - k_low > 1:
        k_mid = k_low + (k_high - k_low) / 2 #N.B. integer division
        if how_much_paint(r, k_mid) > t:
            k_high = k_mid
        elif how_much_paint(r, k_mid) <= t:
            k_low = k_mid
            
    return k_low    

###############################################################################
# Main execution path
###############################################################################

if __name__ == "__main__":
    #Do any pre-calculations required
    precalculate()
    
    #Open up the input & output files
    infile = open("%s-%s%s.in" % (problem, tag, suffix), 'r')
    outfile = open("%s-%s%s.out" % (problem, tag, suffix), 'w')
    
    #Read in the number of cases (the first input line) to iterate through
    cases = int(infile.readline().strip('\n'))
    for i in range(cases):
        
        #Read in the input data for this case
        case = read_input(infile)
        
        #Solve the problem for this case
        output = solve_case(case)
        
        #Write out the output of this case
        outfile.write('Case #%i: %s\n' % (i+1, output))
        print 'Case #%i: %s\n' % (i+1, output)
    
    #Close files
    infile.close()
    outfile.close()