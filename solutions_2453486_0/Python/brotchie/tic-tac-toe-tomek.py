#!/usr/bin/env python
import sys
from operator import or_

def rowcolgen(x):
    # rows
    for i in range(4):
        yield x[i]

    # cols
    for i in range(4):
        yield ''.join(x[j][i] for j in range(4))

    # diags
    yield ''.join(x[i][i] for i in range(4))
    yield ''.join(x[i][3-i] for i in range(4))

def solve(rows):
    for s in rowcolgen(rows):
        selems = set(s)
        selems.discard('T')
        complete = '.' not in selems
        selems.discard('.')
        if complete and len(selems) == 1:
            return '{} won'.format(selems.pop())

    elems = reduce(or_, map(set, rows), set())
    draw = '.' not in elems

    if draw:
        return 'Draw'
    else:
        return 'Game has not completed'

def main():
    assert len(sys.argv) == 2
    path = sys.argv[1]
    with open(path, 'r') as f:
        N = int(f.readline())
        for ii in range(N):
            rows = [f.readline().strip() for i in range(4)]
            f.readline()
            print 'Case #{}: {}'.format(ii+1, solve(rows))

if __name__ == '__main__':
    main()
