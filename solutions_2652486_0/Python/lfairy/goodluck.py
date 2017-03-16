#!/usr/bin/env python3

from collections import defaultdict
from functools import reduce
import operator
from random import choice

def product(it):
    return reduce(operator.mul, it, 1)

def possible_factors(n_digits, limit):
    if n_digits > 0:
        for i in range(2, limit+1):
            yield (i,)
        for i in range(2, limit+1):
            for init in possible_factors(n_digits-1, i):
                yield init + (i,)

def possible_guesses(n_digits, limit):
    if n_digits == 0:
        yield ()
    else:
        for i in range(2, limit+1):
            for init in possible_guesses(n_digits-1, i):
                yield init + (i,)

def make_table(n_digits, limit):
    table = defaultdict(set)
    for nums in possible_factors(n_digits, limit):
        table[product(nums)].add(nums)
    return table

def make_guess(n_digits, limit, table, prods):
    guesses = list(possible_guesses(n_digits, limit))
    for p in prods:
        if p == 1:
            continue
        factors = table[p]
        new_guesses = []
        for g in guesses:
            if any(is_subset(f, g) for f in factors):
                new_guesses.append(g)
        guesses = new_guesses
    if guesses:
        return choice(guesses)
    else:
        return [2] * n_digits

def is_subset(a, b):
    return to_s(a) in to_s(b)  # haha

def to_s(digits):
    return ''.join(map(str, digits))

def main():
    input()  # Ignore first line
    n_cases, n_digits, limit, n_prods = map(int, input().split())
    table = make_table(n_digits, limit)
    print('Case #1:')
    for case in range(n_cases):
        prods = map(int, input().split())
        guess = make_guess(n_digits, limit, table, prods)
        print(to_s(guess))

if __name__ == '__main__':
    main()
