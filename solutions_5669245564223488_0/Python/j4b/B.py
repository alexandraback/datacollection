#!/usr/bin/python

import sys
import functools
import operator
import math
from itertools import chain, combinations, permutations
from heapq import heappop, heappush, _siftup

def isValid(s):
    prev_chars = set()

    pc = s[0]
    for c in s:
        if pc != c:
            if c in prev_chars:
                return False
            prev_chars.add(pc)
            pc = c
    return True
    

def simplify(l):
    new_l = []
    for i in range(len(l)):
        if l[i][0] == l[i][-1]:
            new_l.append(str(l[i][0]))
        else:
            new_l.append(str(l[i][0]) + str(l[i][-1]))
        
        internal = set(l[i])
        internal.remove(l[i][0])
        if l[i][0] == l[i][-1] and internal:
            return []
        if l[i][-1] in internal:
            internal.remove(l[i][-1])
        for j in range(len(l)):
            if i != j:
                jletters = set(l[j])
                if internal.intersection(jletters):
                    return []

    return new_l
        
        

def solve(words):
    count = 0
    swords = simplify(words)
    if not swords:
        return 0

    for perm in permutations(swords):
        #print perm
        s = ''.join(perm)
        if isValid(s):
            count += 1
    return count
        

def main():
    for i in range(int(raw_input())):
        n = int(raw_input())
        words = [x for x in raw_input().split()]
        result = -1
        for word in words:
            if not isValid(word):
                result = 0
                
        if result == -1:
            result = solve(words)
        print ("Case #%s: %s" % (i+1, result))

if __name__ == '__main__':
    main()
