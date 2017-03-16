import sys
from math import ceil

def sol(seq):
    t = max(seq)
    min_t = t

    while t > 1:
        t -= 1
        cost = sum(map(lambda x: ceil(x / t) - 1, seq)) + t
        if cost < min_t:
            min_t = cost

    return min_t

for i, line in enumerate(sys.stdin.read().splitlines()[2::2]):
    tc = list(map(int, line.split()))
    print('Case #%s:' % (i+1), sol(tc))
