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
import random

###############################################################################
# Global variables (for caching, etc.) go here
###############################################################################

def sieve(max=None):
    composites = {}
    #Yield 2 first, then only loop through odd numbers
    yield 2
    q = 3
    while max is None or q < max:
        if q not in composites:
            yield q        
            composites[q * q] = [q]
        else:
            for p in composites[q]:
                try:
                    composites[p+q].append(p)
                except KeyError:
                    composites[p+q] = [p]
            del composites[q]
        q += 1
    
def construct_primes(filename, maxval):
    with open(filename, 'w') as outfile:
        for prime in sieve(maxval):
            outfile.write('%i\n' % prime)

# Pre-calculated list of primes less than 10,000,000 (should be good enough)
with open('primes.txt', 'r') as infile:
    primes = [int(line.strip()) for line in infile]

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
    
    N, J = read_ints()
    
    return (N, J)


def find_factor(num):
    assert num >= 2
    if num in primes:
        return False
    for prime in primes:
        if (num % prime == 0):
            return prime
    return False

def interpret(jamcoin, base):
    return sum(pow(base, exp) if char == '1' else 0 for exp, char in enumerate(jamcoin[::-1]))

def all_interpretations(jamcoin):
    return [interpret(jamcoin, base) for base in range(2, 11)]

def is_jamcoin(jamcoin):
    witnesses = []
    for value in all_interpretations(jamcoin):
        factor = find_factor(value)
        if not factor:
            return False
        witnesses.append(factor)
    return witnesses

def gen_coins(N):
    for i in xrange(pow(2, N-2)):
        binval = bin(i)[2:]
        yield '1' + '0' * (N - 2 - len(binval)) + binval + '1'

def solve_case(N, J):
    output = ['']
    count = 0
    for coin in gen_coins(N):
        witnesses = is_jamcoin(coin)
        if witnesses:
            count += 1
            print('Found %i of %i' % (count, J))
            output.append('%s %s' % (coin, ' '.join(str(w) for w in witnesses))) 
        if count >= J:
            break   
    return '\n'.join(output)

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
        output = solve_case(*case)
        
        #Write out the output of this case
        outfile.write('Case #%i: %s\n' % (i+1, output))
        print 'Case #%i: %s' % (i+1, output)
    
    #Close files
    infile.close()
    outfile.close()
