#!/usr/bin/env python3
import sys

T = int(sys.stdin.readline().strip())

for case_index in range(1, T+1):
    X, R, C = map(int, sys.stdin.readline().strip().split())
    if X == 1:
        # Every grid can be perfectly covered with 1x1 cells
        print('Case #{}: GABRIEL'.format(case_index))
    elif X > max(R, C):
        # Richard can build a | shaped omino that can't fit in the grid
        print('Case #{}: RICHARD'.format(case_index))
    elif (R * C) % X != 0:
        # Richard wins whatever n-omino he chooses: the number of cells of the
        # grid is not a multiple of n
        print('Case #{}: RICHARD'.format(case_index))
    elif X >= 7:
        # Richard can use a "closed" n-omino with a single square free in the
        # center, which will be uncoverable
        print('Case #{}: RICHARD'.format(case_index))
    elif X >= 2*min(R, C) + 1:
        # Richard can build a L-shaped n-omino with both segments longer than
        # the smallest grid dimension: it can't be placed in the grid
        print('Case #{}: RICHARD'.format(case_index))
    elif min(R, C) == 2 and X == 4:
        # Richard can build a T-shaped 4-omino: It will divide the grid in
        # two regions with an odd number of cells that can't be covered with
        # 4-ominos. This is a general rule for grid with an even smallest
        # dimension and X double that, but for other cases it's already covered
        # by X >= 7
        print('Case #{}: RICHARD'.format(case_index))
    elif min(R, C) == 3 and X == 6:
        # Similar to the previous case: Richard can build a T shaped 6-omino
        # that will subdivide the grid in two regions none of which are multiple
        # of 3 (and, therefore, of 6)
        print('Case #{}: RICHARD'.format(case_index))
    else:
        print('Case #{}: GABRIEL'.format(case_index))
        
# da gestire: min(R,C) = 3, X = 5
