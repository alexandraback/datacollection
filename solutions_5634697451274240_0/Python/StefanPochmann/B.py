import itertools

for x in range(1, input() + 1):
    S = raw_input().strip()
    flips = len(list(itertools.groupby(S.rstrip('+'))))
    print 'Case #%d:' % x, flips
