#!/usr/bin/python

import sys

def main():
    T = int(sys.stdin.readline())
    for x in range(1, T + 1):
        N, M = [int(i) for i in sys.stdin.readline().split()]
        A = [[int(i) for i in sys.stdin.readline().split()] for j in range(N)]
        y = 'YES'
        occ = [[1 for i in range(M)] for j in range(N)]
        row_max = [max(A[i]) for i in range(N)]
        col_max = [max(A[i][j] for i in range(N)) for j in range(M)]
        for i in range(N):
            for j in range(M):
                if A[i][j] and A[i][j] in (row_max[i], col_max[j]):
                    occ[i][j] = 0
        if any(any(row) for row in occ):
            y = 'NO'
        print "Case #%d: %s" % (x, y)

if __name__ == '__main__':
    main()

