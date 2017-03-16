test_case = \
'''\
8
bbbbbb 6
quartz 3
straight 3
gcj 2
tsetse 2
aaaaaa 1
bbbbbb 1
b 1
'''

test_solution = \
'''\
Case #1: 1
Case #2: 4
Case #3: 11
Case #4: 3
Case #5: 11
Case #6: 0
Case #7: 21
Case #8: 1
'''

#ignore_test = 1

from engine import run, SolverBase
import sys
from collections import Counter, defaultdict
from operator import itemgetter
from math import sqrt, floor, ceil
from itertools import count
import functools

_vowels = {'a', 'e', 'i', 'o', 'u'}

class Solver(SolverBase):
    def solve(self):
        s, n = self.reader.get_list(str)
        n = int(n)
        total = (len(s) + 1) * (len(s)) // 2
        clusters = []
        left = None
        i = 0
        cons_count = 0
        
        while True:
            if i == len(s) or s[i] in _vowels:
                if cons_count > 0:
                    # just finished a consonant group
                    if cons_count >= n:
                        found = True
                        right = i
                        clusters.append((left, right))
                        left = None
                    cons_count = 0
            else:
                if cons_count == 0:
                    left = i
                cons_count += 1
            if i == len(s):
                break
            i += 1
        print(clusters)
        if not clusters:
            return 0
        for m, c in enumerate(clusters):
            if m == 0:
                left_consonants = 0
                vowels = c[0]
            else:
                left_consonants = n-1
                vowels = c[0] - clusters[m-1][1]
            right_consonants = n-1
            total -= vowels * (vowels+1) // 2
            total -= left_consonants * vowels
            total -= vowels * right_consonants
            total -= left_consonants * right_consonants
            cons = c[1]-c[0]
            total -= cons * (cons+1) //2
            total += (cons-n+1)*(cons-n+2) // 2
            
        left_consonants = n-1
        vowels = len(s) - c[1]
        right_consonants = 0
        total -= vowels * (vowels+1) // 2
        total -= left_consonants * vowels
        total -= vowels * right_consonants
        total -= left_consonants * right_consonants
        total -= right_consonants * (right_consonants+1) // 2
        assert total >= 0
        return total
            
            
            
            
    
run(__name__)