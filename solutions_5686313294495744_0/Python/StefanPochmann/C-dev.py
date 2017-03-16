#with open('C.in') as f:
#    input = list(f)[::-1].pop

import itertools

def naive(topics):
    firsts, seconds = map(set, zip(*topics))
    def suffice(real):
        f, s = map(set, zip(*real))
        return f >= firsts and s >= seconds
    for fake in range(len(topics)-1, -1, -1):
        if any(suffice(real)
               for real in itertools.combinations(topics, N - fake)):
            return fake

for x in range(1, int(input()) + 1):
    N = int(input())
    topics = [input().split() for _ in range(N)]
    print('Case #%d:' % x, naive(topics))
