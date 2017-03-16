import sys
from itertools import *
from collections import *


def simpleSolve(a, motes):
    while motes:
        if motes[0] < a:
            a += motes.pop(0)
        else:
            break
    if not motes:
        return 0
    #removing all motes
    result = len(motes)
    if a == 1:
        return result
    inserted = 0
    while a <= motes[0]:
        inserted += 1
        a += a - 1
    otherResult = simpleSolve(a, motes) + inserted
    return min(result, otherResult)

def solve(f):
    line1 = next(f)
    line2 = next(f)
    a, nOthers = map(int,line1.split())
    others = map(int,line2.split())
    others.sort()
    
    return simpleSolve(a, others)

def main(infile, outfile):
    with open(infile, 'r') as f:
        with open(outfile, 'w') as f2:
            cases = int(next(f))
            for i in range(cases):
                solution = solve(f)
                f2.write("Case #{}: {}\n".format(i+1, solution))

if __name__ == '__main__':
    main(*sys.argv[1:3])

