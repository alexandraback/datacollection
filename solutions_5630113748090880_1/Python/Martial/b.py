import sys
from collections import defaultdict

def f(n, a):
    h = defaultdict(int)
    for x in a:
        for u in x:
            h[u] += 1
    res = []
    keys = list(h.keys())
    keys.sort()
    for k in keys:
        if h[k] % 2 == 1:
            res.append(k)
    return res

n_cases = int(input())
for test_case in range(1, n_cases + 1):
    N = int(input())
    t = [list(map(int,input().split())) for i in range(2*N-1)]
    print(test_case, file=sys.stderr, end=' ')
    res = ' '.join(map(str, f(N, t)))
    print('Case #' + str(test_case) + ':', res)

print(file=sys.stderr)
    
