from collections import defaultdict

for t in xrange(1, int(raw_input()) + 1):
    print 'Case #%s:' % t,
    s = raw_input().lower()
    d = defaultdict(int)
    for i in s:
        d[i] += 1

    dcx = [(8, 'g', 'eight'), (4, 'u', 'four'), (2, 'w', 'two'),
           (6, 'x', 'six'), (0, 'z', 'zero'), (5, 'f', 'five'),
           (3, 'h', 'three'), (1, 'o', 'one'), (7, 's', 'seven')]

    out = defaultdict(int)
    for dg, ch, ex in dcx:
        out[dg] += d[ch]
        for _ in xrange(d[ch]):
            for i in ex:
                d[i] -= 1

    out[9] += sum(d.values())/4
    print ''.join(str(i)*v for i, v in sorted(out.items()))
