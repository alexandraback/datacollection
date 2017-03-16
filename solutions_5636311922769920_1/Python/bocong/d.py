from math import log

def start_index(k, c):
    c = min(k, c)
    if c == 1 or c == 2:
        return c
    else:
        return start_index(k, c - 1) * k - (k - c)

def f(k, c, s):
    req = max(1, int(log(2**(k - c), 2) + 1))
    ind = start_index(k, c)
    if s < req:
        return 'IMPOSSIBLE'
    return ' '.join([str(ind + i) for i in xrange(req)])

T = int(raw_input())
for t in xrange(1, T + 1):
    K, C, S = map(int, raw_input().split(' '))
    print('Case #{}: {}'.format(t, f(K, C, S)))


