from code_jam import autosolve
from itertools import count
from fractions import Fraction

def powers_of_2(start):
    for i in count(start):
        yield 2**i

def is_2_power(value):
    for p in powers_of_2(0):
        if p == value:
            return True
        if p > value:
            return False

@autosolve
def generations(tokens):
    value = tokens.next_token(Fraction)

    if value.numerator > value.denominator:
        return 'impossible'
    if not is_2_power(value.denominator):
        return 'impossible'

    for i in range(1, 100):
        if value >= Fraction(1, 2**i):
            return i
