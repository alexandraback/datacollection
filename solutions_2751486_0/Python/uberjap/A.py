#!/usr/bin/env python

import re
import sys

novowelmatch = r'[^aeiou]'

def rec_hit(name, n):
    nnmatch = '%s{%d}' % (novowelmatch, n)
    for p in range(len(name)):
        if re.match(nnmatch, name[p:]):
            # determine the amount of substrings that fit around this string
            left = p + 1
            right = len(name) + 1 - (p+n)
            #print name, left, right, left*right
            return left * right + rec_hit(name[p+1:], n)
    return 0

def main():
    inp = iter(sys.stdin)
    num_cases = int(inp.next())
    for case in range(1, num_cases + 1):
        name, n = inp.next().split()
        n = int(n)
        print 'Case #%d: %d' % (case, rec_hit(name, n))

if __name__ == '__main__':
    main()
