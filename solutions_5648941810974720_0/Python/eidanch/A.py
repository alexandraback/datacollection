# -*- coding: utf-8 -*-
"""
Created on Sat Apr 30 18:56:55 2016

@author: Eidan Cohen
"""

from itertools import combinations

dwords = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

def str_hist(s):
    lst = 26*[0]
    for c in s:
        lst[ord(c) - ord('A')] += 1
    return lst

def solve(s):
    hist = str_hist(s)
    counts = 10*[0]
    alg = [(0,'Z'), (2,'W'), (4,'U'), (3,'R'), (1,'O'), (5,'F'), 
           (6,'X'), (7, 'V'), (8, 'G'), (9, 'I')]
    for d, c in alg:
        counts[d] = hist[ord(c) - ord('A')]
        for cc in dwords[d]:
            hist[ord(cc) - ord('A')] -= counts[d]
    s = ""
    for d in range(10):
        s += counts[d]*str(d)
    return s
    
def main():
    t = int(input())
    for i in range(1,t+1):
        s = input()
        print('Case #{0}: {1}'.format(i, solve(s)))

if __name__ == '__main__':
    main()

