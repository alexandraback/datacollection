from collections import Counter
from collections import defaultdict
import itertools
import sys
import re

sys.setrecursionlimit(100000)

def check(a, b):
    real = a - b
    fs = set(f for f,l in real)
    ls = set(l for f,l in real)
    for f, l in b:
        if f not in fs or l not in ls:
            return False
    return True


with open('input.txt', 'r') as input, open('output.txt', 'w') as output:
    tt = int(next(input))
    for test in range(tt):
        print (test)
        n = int(next(input))
        lines = set()
        for i in range(n):
            lines.add(tuple(next(input).split()))
        best = 0
        for i in range(1, n):
            fakes = itertools.combinations(lines, i)
            for fake in fakes:
                if check(lines, set(fake)):
                    best = i

        
        output.write('Case #{}: {}\n'.format(test + 1, best))
