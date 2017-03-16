#!/usr/bin/env python3

# This code jam solution is powered by Nathan West's LibCodeJam; see
# https://github.com/Lucretiel/LibCodeJam for source code and (ostensibly) some
# documentation.

from code_jam import *

#code_jam.INSERT_NEWLINE = True

# quick reference:
#   @autosolve, @collects, @cases(n)
#   tokens.token(t), tokens.many(n, t)
#   debug(expr), @unroll(t) gen, @trace func|gen
#   solve(int_token: int, list_token: ('int_token', str)):

keys = [
	(2, 'TWO', 'W'),
	(4, 'FOUR', 'U'),
	(6, 'SIX', 'X'),
	(8, 'EIGHT', 'G'),
	(3, 'THREE', 'H'),
	(5, 'FIVE', 'F'),
	(7, 'SEVEN', 'S'),
	(0, 'ZERO', 'R'),
	(1, 'ONE', 'O'),
	(9, 'NINE', 'I'),
]

@autosolve
@collects
def solve(S: str):
    letters = list(S)
    numbers = []

    for number, word, key in keys:
    	while key in letters:
    		for w in word:
    			letters.remove(w)
    		numbers.append(number)

    return ''.join(map(str, sorted(numbers)))
