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

import itertools

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
    
    N = read_int()
    cars = read_strings()
    assert N == len(cars)
    
    return cars

def is_valid(cars):
    line = ''.join(cars)
    
    active = line[0]
    chars = set([active])
    for c in line:
        if not c == active:
            if c in chars:
                return False
            active = c
            chars.add(c)
    return True
    
def classify(car):
    mid = set()
    for c in car[1:-1]:
        mid.add(c)
    if car[0] in mid:
        mid.remove(car[0])
    if car[-1] in mid:
        mid.remove(car[-1])
    
    #Return None for "bad" cars
    if not is_valid([car]):
        return None
    
    return car[0], car[-1], mid

@memoize    
def factorial(n):
    if n <= 1:
        return 1
    return n * factorial(n - 1)

def solve_case(cars):
    #For the small, just generate all permutations of the cars and check to see if
    #they're valid (only N! possibilities, ~3.6 million max for small input)
    #Not fast enough!  Let's merge cars that will have to be merged, and then take
    #this approach.
    
    for car in cars:
        if classify(car) is None:
            return 0
    
    #Merge single-letter cars
    single = {}
    others = []
    for car in cars:
        c = classify(car)
        if c[0] == c[1]:
            try:
                single[c[0]].append(car)
            except KeyError:
                single[c[0]] = [car]
        else:
            others.append(car)
                
    #Merge singletons and count up
    ways = 1
    for key in single:
        ways *= factorial(len(single[key]))
        single[key] = ''.join(single[key])
        
    #Now lets merge together boundary cars
    starts = set()
    ends = set()
    for car in others:
        s, e = car[0], car[-1]
        #Max one each for start and end
        if s in starts:
            return 0
        if e in ends:
            return 0
        starts.add(s)
        ends.add(e)
    
    for s in starts:
        #Try and merge this one
        if not s in ends:
            continue #can be one unpaired start and end
        first, second = None, None
        #print others
        for car in others:
            if car[0] == s:
                second = car
            if car[-1] == s:
                first = car
        #Check for a middle:
        if s in single:
            merge = first + single.pop(s) + second
        else:
            merge = first + second
        #Stick the merged car back on our list
        if not is_valid([merge]):
            return 0 #The merge produces a bad arrangement!
        
        
        #print others, first, second
        others.remove(first)
        others.remove(second)
        others.append(merge)
        
    cars = []
    for key in single:
        cars.append(single[key])
    for car in others:
        cars.append(car)
    
    print len(cars)
    #return ways * factorial(len(cars))
    
    count = 0
    for permute in itertools.permutations(cars):
        if is_valid(permute):
            count += 1
            
    return ways * count

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
        print 'Case #%i: %s\n' % (i+1, output)
    
    #Close files
    infile.close()
    outfile.close()
