import sys, re
import numpy as np
from fractions import Fraction as F


def solve(f):
    k = -1
    for i in range(41):
        if f.denominator == 1 << i: 
            k = i
            break
    else: return 'impossible'
    if f <= 0 or f > 1: return 'impossible'
    n = f.numerator
    while n > 1:
        k -= 1
        n = n//2
    return k
    
def main(filename):
    with open(filename) as f_in:
        T = int(f_in.readline())
        for i in range(1, T+1):
            f = F(f_in.readline().strip())
            print( 'Case #{0}: {1}'.format(i, solve(f)))
            #map(int, f_in.readline().strip().split(' '))

if __name__ == "__main__":
    main(sys.argv[1])
