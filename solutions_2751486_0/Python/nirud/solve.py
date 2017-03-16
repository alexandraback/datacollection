'''
Created on May 12, 2013

@author: nils
'''

def solve(s, n):
    nvalue = 0
    for substring in substrings(s, n):
        if has_substring_consecutive_consonants(substring, n):
            nvalue += 1
            
    return nvalue

def substrings(s, n):
    for i in range(len(s)+1):
        for j in range(i + n, len(s)+1):
            yield s[i:j]

def substrings_with_comp(s,n):
    for i in range(len(s) + 1 - n):
        yield (s[i:i+n], 1 + i * len(s) - i+n)

def has_substring_consecutive_consonants(s, n):
    for i in range(len(s) + 1 - n):
        if are_all_consonants(s[i:i+n]):
            return True;
        
    return False;

def are_all_consonants(s):
    for c in s:
        if is_vocal(c):
            return False
        
    return True
        
def is_consonant(c):
    return not is_vocal(c)
    
def is_vocal(c):
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'