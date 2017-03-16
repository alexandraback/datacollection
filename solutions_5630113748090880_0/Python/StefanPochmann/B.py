import collections

def naive(P):
    ctr = collections.Counter(h for p in P for h in p)
    return [h for h in sorted(ctr) if ctr[h] % 2]

for x in range(1, int(input()) + 1):
    N = int(input())
    P = sorted(list(map(int, input().split())) for _ in range(2*N-1))
    print('Case #%d:' % x, *naive(P))
