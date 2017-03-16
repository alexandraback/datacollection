#!/usr/bin/python

# parse input into cases
# calculate n value for each and print it
# Functions:
#    consecutive_constants_in_string
#    substrings(s, min_size, max_size)
# data structures:
#    constants

import string
import sys

vowels = set("aeiou")
constants = set(string.ascii_lowercase)-vowels

def simplify(s):
    """
    >>> simplify("quartz")
    'XOOXXX'
    >>> simplify("straight")
    'XXXOOXXX'
    >>> simplify("gcj")
    'XXX'
    >>> simplify("tsetse")
    'XXOXXO'"""
    return ''.join(['X' if i in constants else 'O' for i in s])

def n_indices_start(s, n):
    """List of indices of substrings of length n, made of constants.
    >>> n_indices_start("quarts", 3)
    [3]
    >>> print n_indices_start("quartzuartz", 3)
    [3, 8]""" 
    simplified=simplify(s)
    result=[]
    for i in range(len(s)-n+1):
        if simplified[i:i+n]=='X'*n:
            result.append(i)
    return result

def n_value(s, n):
    """
    >>> n_value("quartz", 3)
    4"""
    debug=False
    start_indices = n_indices_start(s, n)
    if debug: print "start indices: ", start_indices
    result=0
    length=len(s)
    if debug: print "length=%d" % length
    if len(start_indices)==0:
        return 0
    elif len(start_indices)>=1:
        options_index_before = start_indices[0]+1
        options_index_after  = length-start_indices[0]-n+1
        total_options = options_index_before*options_index_after
        if debug: print "First match: options before %d, options after %d, total options %d" % (options_index_before, options_index_after, total_options)
        result+=total_options
        for i in range(1, len(start_indices)):
            options_index_before = start_indices[i]-start_indices[i-1]
            options_index_after  = length-start_indices[i]-n+1
            total_options = options_index_before*options_index_after
            if debug: print "Match %d: options before %d, options after %d, total options %d" % (i, options_index_before, options_index_after, total_options)
            result+=total_options
    return result
            


lines=[l.split() for l in open('large.in').readlines()[1:]]

for i in range(len(lines)):
    line=lines[i]
    n=int(line[1])
    s=line[0]
    print "Case #%d: %d" % (i+1, n_value(s, n))
    
# Test mode
if __name__ == "__main__" and False:
    import doctest
    doctest.testmod(verbose=True)
    
    
