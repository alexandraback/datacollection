test_case = \
'''\
4
2 2
2 1
2 4
2 1 1 6
10 4
25 20 9 100
1 4
1 1 1 1
'''

test_solution = \
'''\
Case #1: 0
Case #2: 1
Case #3: 2
Case #4: 4
'''

from engine import run
import sys
from collections import Counter, defaultdict
from operator import itemgetter
from math import sqrt, floor, ceil
from itertools import count


def size_after_k_meals(start_size, k):
    return 2**k * (start_size - 1) + 1

def cost_to_eat_size_s(start_size, s):
    for k in count():
        s_current = size_after_k_meals(start_size, k)
        if s_current > s:
            return k, s_current + s

class Solver:
    def __init__(self, reader):
        self.reader = reader
        
    def solve(self):
        a, n = self.reader.get_list()
        motes = sorted(self.reader.get_list())
        assert len(motes) == n
        best_so_far = len(motes)
        current = len(motes)
        if a <= 1:
            return best_so_far
        for last_kept_i, last_kept_size in enumerate(motes):
            cost, a = cost_to_eat_size_s(a, last_kept_size)
            current += cost-1
            best_so_far = min(best_so_far, current)
        return best_so_far
        
    
run(__name__)