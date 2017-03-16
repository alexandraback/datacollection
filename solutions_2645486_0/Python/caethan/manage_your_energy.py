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
problem = "B"

tag = "small" #commonly sample, small, or large
#tag = "large"
#tag = "sample"

suffix = "-attempt1" #used sometimes for indexing later input files
#suffix = "-2"
#suffix = ""

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
#      if not isinstance(args, collections.Hashable):
         # uncacheable. a list, for instance.
         # better to not cache than blow up.
#         return self.func(*args)
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
    
    E, R, N = read_ints()
    values = read_ints()
    
    assert N == len(values)
    
    return E, R, values

def max_gain(E, R, maxspent, values):

    if len(maxspent) <= 1:
        #print 'trace', maxspent
        return maxspent
    
    index = np.where(values == values.max())[0][0]
    #print index, maxspent
    
    
    if (maxspent == R).all():
        return maxspent
    
    spent = np.ones(len(maxspent), dtype=int)
    spent[index] = maxspent[index]
    
    for i in range(len(maxspent)):
        maxspent[i] = min(E, maxspent[i], R * abs(index - i))
    
    #print maxspent[:index], maxspent[index+1:]
    
    if index < (len(maxspent) - 1):
        spent[index+1:] = max_gain(E, R, maxspent[index+1:], values[index+1:])
    if index > 0:
        spent[:index] = max_gain(E, R, maxspent[:index], values[:index])
        
    return spent
        

def solve_case(case):
    """Take the input data (structured in case) and perform any necessary
    calculations to obtain the desired output, formatted as the appropriate
    string.    
    """
    
    E, R, values = case
    
    maxspent = np.zeros(len(values), dtype=int) + E

    #print 'start', maxspent

    spent = max_gain(E, R, maxspent, values)
    output = (spent * values).sum()
    
    print spent
    
    return output

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