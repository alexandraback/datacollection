import numpy as np
from collections import Counter

def soluce(N, S):
    s = Counter()
    for i in S:
        for j in i:
            s[j] += 1
    l = [e for e, i in s.items() if i % 2 == 1]
    return ' '.join(list(map(str, sorted(l))))

T = int(input())
for i in range(T):
    N = int(input())
    L = [list(map(int, input().split())) for _ in range(2 * N - 1)]
    print('Case #{}: {}'.format(i + 1, soluce(N, L)))
