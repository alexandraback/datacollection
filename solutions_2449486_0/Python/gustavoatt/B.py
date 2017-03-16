#!/usr/bin/env python
import sys

def achiveable(lawn):
    while len(lawn) > 0:
        n, m = len(lawn), len(lawn[0])
        r, c, minimum = None, None, None

        for i in xrange(n):
            for j in xrange(m):
                if minimum is None or lawn[i][j] < minimum:
                    r, c, minimum = i, j, lawn[i][j]

        count_row, count_col = 0, 0

        # Check the row
        for j in xrange(m):
            if lawn[r][j] == minimum:
                count_row += 1

        # Check the column
        for i in xrange(n):
            if lawn[i][c] == minimum:
                count_col += 1


        rem_row = (count_row == m)
        rem_col = (count_col == n)

        if not rem_row and not rem_col:
            return False
        elif rem_row:
            lawn = lawn[:r] + lawn[r + 1:]
        elif rem_col:
            for i in xrange(n):
                l = lawn[i][:c] + lawn[i][c + 1:]
                if len(l) == 0:
                    lawn.pop(i)
                else:
                    lawn[i] = l

    return True

if __name__ == '__main__':
    T = int(sys.stdin.readline().strip())
    for CASE in xrange(1, T + 1):
        n, m = map(int, sys.stdin.readline().strip().split())
        lawn = [map(int, sys.stdin.readline().strip().split()) for i in xrange(n)]

        if achiveable(lawn):
            print "Case #{}: YES".format(CASE)
        else:
            print "Case #{}: NO".format(CASE)
