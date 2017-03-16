import sys
import itertools

i = 0
for line in sys.stdin:
    bests = []
    best = 999999999999
    qs = line.count('?')
    if qs == 0: continue
    i += 1
    ls = line.replace('?', '%d')
    for x in itertools.product(*[[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]]*qs):
        bl = ls % x
        a, b = bl.split()
        d = abs(int(a) - int(b))
        if d <= best:
            if d < best:
                bests.clear();
            best = d
            bests.append((a, b))
    ba, bb = min(bests)
    print("Case #%d: %s %s" % (i, ba, bb))
