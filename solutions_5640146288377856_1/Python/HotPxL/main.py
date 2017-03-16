#!/usr/bin/env python3.4
import sys
import math

if __name__ == '__main__':
    for testCase in range(int(sys.stdin.readline())):
        sys.stdout.write('Case #{}: '.format(testCase + 1))
        rows, columns, width = map(int, sys.stdin.readline().split())
        blocks = columns // width
        residue = columns - blocks * width
        blocks -= 1
        residue += width
        if residue % width == 0:
            count = blocks + width
        else:
            count = blocks + width + 1
        if rows > 1:
            count += columns // width * (rows - 1)
        print(count)

