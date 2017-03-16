import itertools

def solve():
    N = int(raw_input())
    v = map(int, raw_input().split())
    s = range(1, N + 1)
    max_ = 0
    for i in range(1, N + 1)[::-1]:
        for x in itertools.combinations(s, i):
            for y in itertools.permutations(x):
                ok = True
                for j in xrange(i):
                    if y[(j + 1) % i] == v[y[j] - 1] or y[(j - 1 + i) % i] == v[y[j] - 1]:
                        pass
                    else:
                        ok = False
                        break
                if ok:
                    max_ = max(max_, i)
    return max_

T = int(raw_input())
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()
