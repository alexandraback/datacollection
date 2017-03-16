from collections import defaultdict

T = int(raw_input())

for t in range(T):
    N = int(raw_input())
    counts = defaultdict(int)
    xs = [map(int, raw_input().split()) for _ in range(2*N-1)]
    for x in xs:
        for y in x:
            counts[y] = counts[y] + 1
    r = []
    for x, c in counts.iteritems():
        if c % 2: r.append(x)
    print "Case #%d:"%(t+1), ' '.join(map(str,sorted(r)))
