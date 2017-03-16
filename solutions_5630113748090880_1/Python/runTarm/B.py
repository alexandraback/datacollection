from collections import defaultdict
def solve(A):
    C = defaultdict(int)
    for row in A:
        for h in row:
            C[h] += 1

    L = sorted([k for k, v in C.iteritems() if v % 2 != 0])
    return ' '.join(map(str, L))

import sys
sys.stdin = open('B-large.in', 'rt')
sys.stdout = open('B-large.out', 'wt')

T = int(raw_input().strip())
for t in range(1, T+1):
    N = int(raw_input().strip())
    A = []
    for _ in range(0, 2*N-1):
        A.append(map(int, raw_input().strip().split(' ')))

    print 'Case #{}:'.format(t), solve(A)
