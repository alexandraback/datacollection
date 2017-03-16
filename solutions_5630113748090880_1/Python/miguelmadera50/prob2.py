def prob2(n, rows):
    final = set()
    for r in rows:
        if (rows.count(r) % 2) == 1:
            final.add(r)
    final = list(final)
    final.sort()
    return ' '.join(map(str, final))


t = int(raw_input())
for i in xrange(1, t + 1):
    n = int(raw_input()) * 2 - 1
    rows = list()
    for k in xrange(n):
        rows += (map(int, raw_input().split()))

    print "Case #{}: {}".format(i, prob2(n, rows))
