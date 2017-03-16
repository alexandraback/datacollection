#with open('B.in') as f:
#    input = list(f)[::-1].pop

import re

def form(x):
    return '{:0{}}'.format(x, n)

def naive(C, J):
    def nums(X):
        X = X.replace('?', '.')
        return [x for x in range(10**n)
                if re.match(X, form(x))]
    C = nums(C)
    J = nums(J)
    def key(cj):
        c, j = cj
        return abs(c - j), c, j
    return min(((c, j) for c in C for j in J), key=key)

for x in range(1, int(input()) + 1):
    C, J = input().split()
    n = len(C)
    c, j = naive(C, J)
    print('Case #%d:' % x, form(c), form(j))
