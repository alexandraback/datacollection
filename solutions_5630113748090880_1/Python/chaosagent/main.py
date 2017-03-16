from collections import Counter

t = int(raw_input().strip())

for case in xrange(1, t + 1):
    n = int(raw_input().strip())
    appearances = Counter(sum((map(int, raw_input().strip().split(' ')) for _ in xrange(n * 2 - 1)), []))

    missing = set([])
    for key in appearances.elements():
        if appearances[key] % 2:
            missing.add(key)
    print 'Case #%d: %s' % (case, ' '.join(map(str, sorted(missing))))
