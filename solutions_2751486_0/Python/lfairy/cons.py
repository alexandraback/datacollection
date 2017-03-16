#!/usr/bin/env python3

import string

consonants = frozenset(string.ascii_lowercase) - frozenset('aeiou')

def substrings(s):
    for start in range(len(s)):
        for end in range(start+1, len(s)+1):
            yield s[start:end]

def sub_n(s, n):
    for start in range(len(s)-n+1):
        yield s[start:start+n]

def completely_fancy(s):
    return all(letter in consonants for letter in s)

def count_fancy(s, n):
    result = 0
    for section in substrings(s):
        if any(completely_fancy(bit) for bit in sub_n(section, n)):
            result += 1
    return result

if __name__ == '__main__':
    cases = int(input())
    for i in range(cases):
        s, n = input().split()
        n = int(n)
        print('Case #{}: {}'.format(i+1, count_fancy(s, n)))
