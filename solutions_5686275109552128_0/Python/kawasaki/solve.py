from itertools import takewhile

CACHE = {}

T = int(raw_input())
for t in xrange(T):
    D = int(raw_input())
    P = map(int, raw_input().split())

    P.sort(reverse=True)

    def solve(P):
        # P to be sorted desc
        maximum = P[0]
        if maximum <= 3:
            return maximum

        if tuple(P) in CACHE:
            return CACHE[tuple(P)]

        candidates = []
        candidates.append(1 + solve([x - 1 for x in P]))
        for d in xrange(1, (maximum + 1) / 2 + 1):
            candidates.append(1 + solve(sorted(P[1:] + [d, maximum - d], reverse=True)))

        ret = min(candidates)
        CACHE[tuple(P)] = ret
        return ret

    print 'Case #{}: {}'.format(t + 1, solve(P))
