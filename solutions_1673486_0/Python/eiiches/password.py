# coding: utf-8

import sys

def solve_keeptyping(A, B, P):
    p_correct = 1.0
    for i in range(A):
        p_correct *= P[i]
    return p_correct * (B - A + 1) + (1 - p_correct) * (2 * B + 2 - A)

def solve_enterrightaway(A, B, P):
    return 2 + B

def solve_backspaces(A, B, P):
    min_expected = 10000000
    p_allcorrect = 1.0
    for j in reversed(range(1, A+1)):
        expected = p_allcorrect * (j + j + B - A + 1) \
                + (1 - p_allcorrect) * (j + j + B - A + 1 + B + 1)
        if min_expected > expected:
            min_expected = expected
        p_allcorrect *= P[A-j]
    return min_expected

def solve(A, B, P):
    current_min = min(solve_keeptyping(A, B, P),
            solve_enterrightaway(A, B, P),
            solve_backspaces(A, B, P))
    return current_min

with open(sys.argv[1]) as f:
    lines = filter(None, f.read().split('\n'))
    T = int(lines[0])
    for i in range(T):
        A, B = map(int, lines[i*2+1].split())
        P = map(float, lines[i*2+2].split())
        result = solve(A, B, P)
        print 'Case #{0}: {1}'.format(i + 1, result)
