# -*- coding: utf-8 -*-

from itertools import product


def solve():
    c, j = raw_input().split()
    n = len(c)
    n_empty = c.count('?') + j.count('?')

    best_diff = float('inf')
    best_c_score = float('inf')
    best_j_score = float('inf')

    best_c = ''
    best_j = ''

    for e in product(map(str, range(10)), repeat=n_empty):
        h_c = list(c)
        h_j = list(j)
        idx = 0
        for i in xrange(len(h_c)):
            if h_c[i] == '?':
                h_c[i] = e[idx]
                idx += 1
        for i in xrange(len(h_j)):
            if h_j[i] == '?':
                h_j[i] = e[idx]
                idx += 1

        d = abs(int(''.join(h_c)) - int(''.join(h_j)))
        sc = int(''.join(h_c))
        sj = int(''.join(h_j))
        if d < best_diff or (d == best_diff and sc < best_c_score) or (d == best_diff and sc == best_c_score and sj < best_j_score):
            best_diff = d
            best_c_score = sc
            best_j_score = sj
            best_c = ''.join(h_c)
            best_j = ''.join(h_j)

    print best_c, best_j


def main():
    t = int(raw_input())
    for i in xrange(1, t + 1):
        print 'Case #%d:' % i,
        solve()


if __name__ == '__main__':
    main()
