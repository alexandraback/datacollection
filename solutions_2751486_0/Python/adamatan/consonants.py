#!/usr/bin/python

# parse input into cases
# calculate n value for each and print it
# Functions:
#    consecutive_constants_in_string
#    substrings(s, min_size, max_size)
# data structures:
#    constants

import string

vowels = set("aeiou")
constants = set(string.ascii_lowercase)-vowels

def consecutive_constants(s):
    """
    >>> consecutive_constants("quarts")
    3
    >>> consecutive_constants("")
    0
    >>> consecutive_constants("quarts") == consecutive_constants("uarts") == consecutive_constants("arts") == consecutive_constants("rts")
    True
    """ 
    result=0
    count=0;
    for i in range(len(s)):
        if s[i] in constants:
            count+=1
            result=max(count, result)
        else:
            count=0
    return result

def get_substrings(s, min_size, max_size):
    """
    >>> get_substrings("abcd", 4, 4)
    ['abcd']
    >>> get_substrings("abcd", 3, 4)
    ['abc', 'bcd', 'abcd']
    """
    result=[]
    for length in range(min_size, max_size+1):
        for i in range(0, len(s)-length+1):
            result.append(s[i:i+length])
            #print length, i , s[i:i+length]
    return result

def n_value(s, n):
    """
    >>> n_value("quartz", 3)
    4
    >>> n_value("straight", 3)
    11
    >>> n_value("gcj", 2)
    3
    >>> n_value("tsetse", 2)
    11"""
    substrings = get_substrings(s, n, len(s))
    return len([1 for i in substrings if consecutive_constants(i)>=n])


lines=[l.split() for l in open('small.in').readlines()[1:]]

for i in range(len(lines)):
    line=lines[i]
    print "Case #%d: %d" % (i+1, n_value(line[0], int(line[1])))
    
# Test mode
if __name__ == "__main__" and False:
    import doctest
    doctest.testmod(verbose=True)
    
    
