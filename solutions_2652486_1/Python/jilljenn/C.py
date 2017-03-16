import random # This is beautiful.
from itertools import combinations_with_replacement
from operator import mul

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

def re(rev, k):
    p = reduce(lcm, k)
    return rev[p] if p in rev else random.choice(list(combinations_with_replacement(range(2, 9), 12)))

if __name__ == '__main__':
    T = int(raw_input())
    R, N, M, K = map(int, raw_input().split())
    rev = {}
    for l in combinations_with_replacement(range(2, M + 1), N):
        rev[reduce(mul, l)] = l
    a = []
    print 'Case #1:'
    for r in range(R):
        k = map(int, raw_input().split())
        print ''.join(map(str, re(rev, k)))
