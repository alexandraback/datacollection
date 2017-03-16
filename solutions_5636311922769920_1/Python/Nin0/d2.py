#!/usr/bin/python3
import sys

T = int(sys.stdin.readline())

def to_range(l, M):
    d = M - l[-1]
    if d >= 0:
        return l
    return [x + d for x in l]

def determine_col(rows, K, C):
    """
    Determine the column number where all rows are 'G's.
    """
    rows = [x - 1 for x in rows]  # Change to 0-based indices.
    # We look for a base K number with C digits such that all
    # elements of rows appear as digits this number.
    num = 0
    for d in rows:
        num *= K
        num += d
    assert 0 <= num < K**C 
    return num + 1  # Back to 1-based counting.

def sol(K, C, S):
    if C > K:
        C = K  # Complexity K is sufficient to solve for length K in 1 query.
    # Number of queries needed
    q = K // C + (0 if K % C == 0 else 1)
    if S < q:
        return 'IMPOSSIBLE'
    # Consider only tilings with exactly one 'G'. So there are K options
    # to consider. Imagine a table where the i-th row is a tiling of
    # complexity C made from the "basis" tiling with 'G' in i-th place.
    # In a tiling of complexity C, there will exist a column with C 'G's.
    # Moreover, there will exist a column with C 'G's that are placed in any
    # chosen C rows (among the K rows in consideration).
    pos = [to_range([j + C*i for j in range(1, C+1)], K) for i in range(0, q)]
    sol = [determine_col(p, K, C) for p in pos]
    return ' '.join(str(n) for n in sol)

for i in range(1, T+1):
    K, C, S = [int(x) for x in sys.stdin.readline().split()]
    print('Case #{0}: {1}'.format(i, sol(K, C, S)))


"""
GLL: GGGGLLGLL
LGL: LGLGGGLGL
LLG: LLGLLGGGG
"""