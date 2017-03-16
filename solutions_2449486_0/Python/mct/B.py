# -*- coding:utf-8 -*-

import sys

def solve(N, M ,a):
    # in all square, the grass should be greater/equal than the row or the column
    for i in range(N):
        for j in range(M):
            r = all(a[i][j] >= x for x in a[i])
            c = all(a[i][j] >= x for x in [a[n][j] for n in range(N)])
            if not r and not c:
                return "NO"
    return "YES"

def main():
    T = int(sys.stdin.readline())
    for t in range(T):
        N, M = [int(k) for k in sys.stdin.readline().split()]
        a = []
        for n in range(N):
            a.append([int(k) for k in sys.stdin.readline().split()])
        res = solve(N, M, a)
        print 'Case #%d: %s' % (t + 1, res)

if __name__ == '__main__':
    main()
    