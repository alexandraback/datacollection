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
    
    L, X = read_ints()
    chars = read_string()
    
    return chars, X

@memoize
def multiply(a, b):
    """This is correct, I checked it by hand (every case)"""
    #Simple stuff
    if a == 1:
        return b
    if b == 1:
        return a
    if a == -1 and b == -1:
        return 1
    
    #Non-ones squared are negative 1
    if a == b:
        return -1
    
    #If b is negative one, we can be commutative
    if b == -1:
        a, b = b, a
    
    #Check to see if we're multiplying by negative 1
    if a == -1:
        if b[0] == "-":
            return b[1]
        else:
            return "-" + b
            
    #Now we're sure that we have +/- i,j,k (all the 1/-1 possibilities are exhausted)
    
    #Both negative, remove the negative signs
    if a[0] == "-" and b[0] == "-":
        a, b = a[1], b[1]
        
    #One negative, move it to the first one
    if b[0] == "-":
        a = "-" + a
        b = b[1]
        
    #i,j,k by its negative is 1
    if a[0] == "-" and a[1] == b:
        return 1
      
    #And finally, return the rest  
    cache = {
        ("i", "j"): "k",
        ("i", "k"): "-j",
        ("j", "i"): "-k",
        ("j", "k"): "i",
        ("k", "i"): "j",
        ("k", "j"): "-i",
        ("-i", "j"): "-k",
        ("-i", "k"): "j",
        ("-j", "i"): "k",
        ("-j", "k"): "-i",
        ("-k", "i"): "-j",
        ("-k", "j"): "i",
        }
    return cache[(a, b)]

@memoize
def power(num, k):
    assert k >= 0
    k = k % 4
    if k == 0:
        return 1
    out = num
    while k > 1:
        out = multiply(out, num)
        k -= 1
    return out
    
@memoize
def interior_product(chars, start, end):
    #print start, end
    assert end >= start
    if start == end:
        return chars[start]
    #N = int(np.sqrt(len(chars)))
    #This is just meant to speed up the product calculation with memoization
    N = 25
    mid = start + (end - start) // 2
    rem = mid % N
    if rem and mid - rem >= start:
        mid -= rem
    return multiply(interior_product(chars, start, mid), interior_product(chars, mid+1, end)) 
    
def interior_product_simple(chars, leftcount, rightcount):
    return reduce(multiply, chars[leftcount:-rightcount], 1)

def solve_case(case):
    """Take the input data (structured in case) and perform any necessary
    calculations to obtain the desired output, formatted as the appropriate
    string.    
    """
    
    chars, X = case
    print chars
    
    #A quick performance improvement - find strings that repeat themselves and reduce them
    def principal_period(s):
        i = (s+s).find(s, 1, -1)
        return None if i == -1 else s[:i]
    new = principal_period(chars)
    if new is not None and new != chars:
        X *= len(chars) // len(new)
        chars = new
    print 'X: %i' % X
    
    #Find the value of the chars, multiplied out
    product = reduce(multiply, chars, 1)
    
    #The product raised to the power of X must be equal to 'ijk=-1', so let's check (and save some time)
    if power(product, X) != -1:
        return "NO"
    
    #Find the value of the prefixes of the characters
    prefixes = [1]
    val = 1
    for char in chars:
        val = multiply(val, char)
        prefixes.append(val)
    assert prefixes[-1] == product
        
    #And suffixes
    suffixes = [1]
    val = 1
    for char in chars[::-1]:
        val = multiply(char, val)
        suffixes.append(val)
    assert suffixes[-1] == product
    
    #Just check that there's no errors
    """
    for i in range(len(chars) + 1):
        try:
            assert multiply(prefixes[i], suffixes[-(i+1)]) == product
        except AssertionError:
            print i, prefixes[i], suffixes[-(i+1)]
            print multiply(prefixes[i], suffixes[-(i+1)]), product
            print prefixes
            print suffixes
            raise(AssertionError)
    """
    
    #Look for left-hand 'i' values
    valid_i = []
    for leftcopies in range(0, min(X, 4)):
        for i, leftprefix in enumerate(prefixes[:-1]):
            #Check to see if this is a valid i
            num = power(product, leftcopies)
            num = multiply(num, leftprefix)
            if num == 'i':
                valid_i.append((leftcopies, i))
                
    #Look for right-hand 'k' values
    valid_k = []
    for rightcopies in range(0, min(X, 4)):
        for i, rightsuffix in enumerate(suffixes[:-1]):
            #Check to see if this is a valid k
            num = power(product, rightcopies)
            num = multiply(rightsuffix, num)
            if num == 'k':
                valid_k.append((rightcopies, i))
                
    #Go through pairs of valid i and valid k, see if they fit, and then
    #check to see if the interior is equal to j
    print len(valid_i)#, valid_i
    print len(valid_k)#, valid_k
    
    for leftcopies, leftcount in valid_i:
        for rightcopies, rightcount in valid_k:
            if leftcopies + rightcopies >= X:
                continue
            if (leftcount + rightcount >= len(chars)) and (leftcopies + rightcopies == (X - 1)):
                #Can't share the same interior copy
                continue
            #OK, now we can fit these together, let's calculate the interior
            if leftcount == 0 and rightcount == 0:
                #Neither side bites into the interior cop(ies)
                midcopies = X - leftcopies - rightcopies
                interior = power(product, midcopies)
            elif leftcount == 0:
                #Only the right side bites in
                midcopies = X - leftcopies - rightcopies - 1
                interior = power(product, midcopies)
                interior = multiply(interior, prefixes[len(chars) - rightcount])
            elif rightcount == 0:
                #Only the left side bites in
                midcopies = X - leftcopies - rightcopies - 1
                interior = power(product, midcopies)
                interior = multiply(suffixes[len(chars) - leftcount], interior)
            else:
                #Both sides bite in
                if X - leftcopies - rightcopies == 1:
                    #We're doing an interior product
                    interior = interior_product(chars, leftcount, len(chars) - rightcount - 1)
                else:
                    midcopies = X - leftcopies - rightcopies - 2
                    interior = power(product, midcopies)
                    interior = multiply(suffixes[len(chars) - leftcount], interior)
                    interior = multiply(interior, prefixes[len(chars) - rightcount])                    
                
                    """       midcopies = X - leftcopies - rightcopies - 2
                if rightcount + leftcount >= len(chars):
                    #And both sides together bite at least two copies away
                    interior = power(product, midcopies)
                    interior = multiply(suffixes[len(chars) - leftcount], interior)
                    interior = multiply(interior, prefixes[len(chars) - rightcount])
                else:
                    #The two sides bite away less than a full copy
                    if midcopies == 0:
                        #We need to calculate the interior bit of a copy
                        #interior_slow = reduce(multiply, chars[leftcount:-rightcount], 1)
                        interior = interior_product(chars, leftcount, len(chars) - rightcount - 1)
                        #try:
                        #    assert interior == interior_slow
                        #except AssertionError:
                        #    print 'Error!'
                        #    print chars[leftcount:-rightcount]
                        #    print interior, interior_slow
                        #    raise AssertionError
                    else:
                        interior = power(product, midcopies)
                        interior = multiply(suffixes[len(chars) - leftcount], interior)
                        interior = multiply(interior, prefixes[len(chars) - rightcount])
                    """
            if interior == 'j':
                print (leftcopies, leftcount), (rightcopies, rightcount)
                return "YES"
            
    return "NO"

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
    
    #Test multiply
    """
    vals = [1, 'i', 'j', 'k', -1, '-i', '-j', '-k']
    print '     |' , ''.join(['%4.2s' % str(val) for val in vals])
    print '-' * 30
    for val in vals:
        print '%4.2s |' % str(val), ''.join(['%4.2s' % str(multiply(val, sec)) for sec in vals])
    """