#!/usr/bin/env python
import sys

def solve(rows):
    Nrows = len(rows)
    Ncols = len(rows[0])
    row_max = [max(rows[i]) for i in range(Nrows)]
    col_max = [max([rows[j][i] for j in range(Nrows)]) for i in range(Ncols)]

    for i in range(Nrows):
        for j in range(Ncols):
            if rows[i][j] < min(row_max[i], col_max[j]):
                return 'NO'
    return 'YES'

def main():
    assert len(sys.argv) == 2
    path = sys.argv[1]
    with open(path) as f:
        Ncases = int(f.readline())
        for ii in range(Ncases):
            Nrows = int(f.readline().strip().split(' ')[0])
            rows = [map(int, f.readline().strip().split(' ')) for i in range(Nrows)]
            print 'Case #{}: {}'.format(ii+1, solve(rows))

if __name__ == '__main__':
    main()
