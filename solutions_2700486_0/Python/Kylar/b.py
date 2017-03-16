import sys
from itertools import *
from collections import *

def diamondsInLayer(layerN):
    return layerN * 4 + 1

#layer 2, n 3, height 2
def probability(layer, n, height):
    if height == layer * 2:
        if n == diamondsInLayer(layer):
            return 1.0
        else:
            return 0.0
    if n - height > layer * 2:
        return 1.0
    if n == 0:
        return 0.0
    if height == 0:
        result = 0.0
        for i in range(n):
            result += 0.5 ** (i + 1)
        return result
    p1 = probability(layer, n-1, height)
    p2 = probability(layer, n-1, height-1)
    return (p1 + p2) / 2


def solve(f):
    line1 = next(f)
    n, x, y = map(int, line1.split())

    diamondLayer = abs(x) + y
    if diamondLayer % 2:
        return 0.0
    diamondLayer //= 2
    
    layer = 0
    while layer < diamondLayer:
        n -= diamondsInLayer(layer)
        if n <= 0:
            return 0.0
        layer += 1
        
    if n >= diamondsInLayer(layer):
        return 1.0

    return probability(layer, n, y)
        


    return result

def main(infile, outfile):
    with open(infile, 'r') as f:
        with open(outfile, 'w') as f2:
            cases = int(next(f))
            for i in range(cases):
                solution = solve(f)
                f2.write("Case #{}: {}\n".format(i+1, solution))

if __name__ == '__main__':
    main(*sys.argv[1:3])

