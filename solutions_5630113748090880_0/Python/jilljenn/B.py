from collections import Counter

T = int(input())
for t in range(T):
    N = int(input())
    c = Counter()
    for _ in range(2 * N - 1):
        c.update(map(int, input().split()))
    r = []
    for k in c:
        if c[k] % 2 == 1:
            r.append(k)
    print('Case #%d:' % (t + 1), ' '.join(map(str, sorted(r))))
