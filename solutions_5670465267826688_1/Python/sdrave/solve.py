import sys
import numpy as np

def div_round_up(x, y):
    return x // y + (1 if x % y > 0 else 0)

class Oct(object):

    #       1  i  j  k -1 -i -j -k
    LUT = [[0, 1, 2, 3, 4, 5, 6, 7], #  1 
           [1, 4, 3, 6, 5, 0, 7, 2], #  i
           [2, 7, 4, 1, 6, 3, 0, 5], #  j
           [3, 2, 5, 4, 7, 6, 1, 0], #  k
           [4, 5, 6, 7, 0, 1, 2, 3], # -1
           [5, 0, 7, 2, 1, 4, 3, 6], # -i 
           [6, 3, 0, 5, 2, 7, 4, 1], # -j 
           [7, 6, 1, 0, 3, 2, 5, 4]] # -k 

    def __init__(self, c):
        if type(c) == int:
            self.value = c
        elif c == 'i':
            self.value = 1
        elif c == 'j':
            self.value = 2
        elif c == 'k':
            self.value = 3
        else:
            raise ValueError

    def __eq__(self, other):
        return self.value == other.value

    def __mul__(self, other):
        return Oct(self.LUT[self.value][other.value])

E = Oct(0)
MINUS_E = Oct(4)
I = Oct('i')
J = Oct('j')
K = Oct('k')

def process(l1, l2):
    L, X = map(int, l1.strip().split(' '))
    chars = l2.strip()
    assert L == len(chars)
    octs = map(Oct, chars)

    octs8 = octs * 8

    val = E
    for k, x in enumerate(octs8):
        val = val * x
        if val == I:
            break
    if not (val == I):
        return 'NO'
    length_i = k + 1
    if length_i + 2 > L * X:
        return 'NO'

    val = E
    for k, x in enumerate(reversed(octs8)):
        val = x * val
        if val == K:
            break
    if not (val == K):
        return 'NO'
    length_k = k + 1
    if length_i + length_k + 1 > L * X:
        return 'NO'

    X = X % 4
    octs = octs * X
    val = E
    for x in octs:
        val = val * x

    if val == MINUS_E:
        return 'YES'
    else:
        return 'NO'


data = open(sys.argv[1]).readlines()[1:]

with open(sys.argv[2], 'w') as f:
    for i, d in enumerate(zip(data[0::2], data[1::2])):
        f.write('Case #{}: {}\n'.format(i+1, process(*d)))
