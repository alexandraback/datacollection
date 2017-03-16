import os
import sys
import re
import math
import random
from itertools import product, permutations, combinations, combinations_with_replacement

# Itertools Functions:
# product('ABCD', repeat=2)                   AA AB AC AD BA BB BC BD CA CB CC CD DA DB DC DD
# permutations('ABCD', 2)                     AB AC AD BA BC BD CA CB CD DA DB DC
# combinations('ABCD', 2)                     AB AC AD BC BD CD
# combinations_with_replacement('ABCD', 2)    AA AB AC AD BB BC BD CC CD DD

def memoize(f):
    """Simple dictionary-based memoization decorator"""
    cache = {}
    def _mem_fn(*args):
        if args not in cache:
            cache[args] = f(*args)
        return cache[args]

    _mem_fn.cache = cache
    return _mem_fn

def wardrobe(j, p, s):
    return product(*[xrange(1, j + 1), xrange(1, p + 1), xrange(1, s + 1)])

# -----------------------

num_cases = int(raw_input())
num_lines = 1

for case in range(1, num_cases + 1):
    jackets, pants, shirts, max_combinations = (int(n) for n in raw_input().split())

    # Let's do some statistics

    full_wardrobe = list(wardrobe(jackets, pants, shirts))
    # random.shuffle(full_wardrobe)

    attires = []

    for _ in range(10000):
        random.shuffle(full_wardrobe)
        tmp_attires = []

        combinations = {}

        for attire in full_wardrobe:
            for a, b, c in [(1, 1, 0), (1, 0, 1), (0, 1, 1)]:
                key = (
                    attire[0] if a else 0,
                    attire[1] if b else 0,
                    attire[2] if c else 0,
                )

                if key in combinations.keys():
                    combinations[key] += 1
                else:
                    combinations[key] = 1

                if combinations[key] > max_combinations:
                    break
            else:
                tmp_attires.append(attire)

        if len(tmp_attires) > len(attires):
            attires = tmp_attires[:]

    print "Case #{}: {}".format(case, len(attires))
    for a in attires:
        print ' '.join(str(n) for n in a)
