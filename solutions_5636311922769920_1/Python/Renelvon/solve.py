#!/usr/bin/env python3
import sys


def main():
    input_file = sys.argv[1]
    solve(input_file)


def solve(input_file):
    with open(input_file) as f_in:
        next(f_in)
        for i, input_line in enumerate(f_in):
            K, C, S = tuple(int(s) for s in input_line.split())
            solve_instance(i, K, C, S)


def solve_instance(i, K, C, S):
    min_tiles = (K + C - 1) // C;
    if (S < min_tiles):
        print("Case #%d: IMPOSSIBLE" % (i + 1))
        return
    
    solution = []
    source = 0
    for _ in range(min_tiles):
        pos = 0
        for _ in range(min(C, K - source)):
            pos *= K
            pos += source
            source += 1
        solution.append(pos + 1)
    output = " ".join(str(n) for n in solution)
    print("Case #%d: %s" % (i + 1, output.rstrip()))


if __name__ == '__main__':
    main()
