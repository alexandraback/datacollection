import sys
from itertools import combinations_with_replacement, product
from operator import mul
from collections import Counter
import pprint

def rl():
    return sys.stdin.readline().strip()

def ways_to_get(N, M):
    d = {}
    rng = range(2, M+1)
    for i in range(1, N+1):
        for c in combinations_with_replacement(rng, i):
            c = list(c)
            d.setdefault(reduce(mul, c), []).append(Counter(c))
    return d

def pick(options, N, M):
    best = []
    for comb in product(*options):
        tc = Counter(dict((n, max(c[n] for c in comb)) for n in range(2, M+1)))
        sm = sum(tc.values())
        if sm > N:
            continue
        elif sm == N:
            return ''.join(map(str, tc.elements()))
        elif sm > len(best):
            best = list(tc.elements())
    return ''.join(map(str, best+[2]*(N-len(best))))

def main():
    T = int(rl())
    for i in range(1, T+1):
        R, N, M, K = map(int, rl().split())
        d = ways_to_get(N, M)
        print 'Case #%d:' % i
        for j in range(R):
            options = []
            for prod in map(int, rl().split()):
                if prod in d:
                    options.append(d[prod])
            if not options:
                print '2'*N
            else:
                print pick(options, N, M)

if __name__ == '__main__':
    main()
