#Template code developed by Brett Olsen (brett.olsen@gmail.com), 2013
#for the Google Code Jam programming contest

###############################################################################
# Imports go here
###############################################################################

#Do proper division
from __future__ import division

#For faster numerical analysis
import numpy as np

import sys

#Needed for the memoization decorator
import collections
import functools

###############################################################################
# Global variables (for caching, etc.) go here
###############################################################################

###############################################################################
# Decorators (taken from http://wiki.python.org/moin/PythonDecoratorLibrary)
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
    def read_bigints(): #For ints that won't fit directly in an int32 array
        line = infile.readline().split()
        return np.array(map(lambda x: int(x), line))
    def read_float():
        return float(infile.readline().strip())
    def read_floats():
        return np.array(infile.readline().split(), dtype=float)
    def read_string():
        return infile.readline().strip()
    def read_strings():
        return np.array(infile.readline().split(), dtype=object) #N.B. general dtype
    
    X, R, C = read_ints()
    
    return X, R, C

def solve_case(case):
    """Take the input data (structured in case) and perform any necessary
    calculations to obtain the desired output, formatted as the appropriate
    string.    
    """
    
    X, R, C = case
    print X, R, C
    #Make R smaller if it isn't already
    if R > C:
        R, C = C, R
        
    #If the number of squares isn't divisible by X, it's clearly not possible
    if R * C % X:
        return "RICHARD"
        
    #If the (longer) number of columns is shorter than X, Richard can give a straight piece
    #that won't fit
    if C < X:
        return "RICHARD"
        
    #If X >= 7, then Richard can give an omino with an unfillable hole in the middle
    if X >= 7:
        return "RICHARD"   
        
    #X = 1 is always possible
    if X == 1:
        return "GABRIEL"
    #X = 2 is always possible if there's an even number of squares (as determined above)
    elif X == 2:
        return "GABRIEL"
    
    #X = 3 is only possible if there are at least 2 rows.  Then either triomino can fit 
    #into a 3 by 2 tile, which can repeatedly tile any larger set along with the 3 by 1 piece.
    #(as long as the total square count is divisible by 3)
    elif X == 3:
        if R < 2:
            return "RICHARD"
        else:
            return "GABRIEL"
    
    #All tetrominos can fit into a 3 by 4 tile.  That means that as long as there are at least
    #3 rows and the count is divisible by 4, we can definitely tile.
    elif X == 4:
        if R < 3:
            return "RICHARD"
        else:
            return "GABRIEL"
    
    #All pentominos can fit into a 4 by 5 tile.  So as long as we have at least 4 rows and the
    #count is divisible by 5 we can tile
    elif X == 5:
        if R < 4:
            return "RICHARD"
        else:
            return "GABRIEL"
        
    #Similarly here
    elif X == 6:
        if R < 5:
            return "RICHARD"
        else:
            return "GABRIEL" 

###############################################################################
# Main execution path
###############################################################################

if __name__ == "__main__":
    #Do any pre-calculations required
    precalculate()
    
    #Open up the input & output files based on the provided input file
    assert len(sys.argv) == 2 #only one argument
    assert sys.argv[1][-3:] == ".in" #input must end with .in
    infile = open("%s" % sys.argv[1], 'r')
    outfile = open("%s.out" % sys.argv[1][:-3], 'w')
    
    #Read in the number of cases (the first input line) to iterate through
    cases = int(infile.readline().strip('\n'))
    for i in range(cases):
        
        #Read in the input data for this case
        case = read_input(infile)
        
        #Solve the problem for this case
        output = solve_case(case)
        
        #Write out the output of this case
        outfile.write('Case #%i: %s\n' % (i+1, output))
        print 'Case #%i: %s' % (i+1, output)
    
    #Close files
    infile.close()
    outfile.close()
