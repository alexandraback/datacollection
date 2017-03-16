from itertools import product
T = int(raw_input())

for t in xrange(T):
    r, c, w = [int(x) for x in raw_input().split(' ')]
    shots = (r - 1) * (c / w)
    best = c
    for pattern in product([0, 1], repeat=c):
        maxGap = 0
        lastShot = -1
        numGaps = 0
        for j, hit in enumerate(pattern):
            if hit:
                maxGap = max(maxGap, j - lastShot - 1)
                if j - lastShot - 1 < w:
                    numGaps += 1
                lastShot = j
        maxGap = max(maxGap, len(pattern) - lastShot - 1)
        if len(pattern) - lastShot - 1 < w:
            numGaps += 1
        shotsUsed = sum(1 for x in pattern if x)
        if maxGap < w and numGaps == 1:
            maxHits = 0
            for i in xrange(c - w + 1):
                maxHits = max(maxHits, w - sum(1 for x in pattern[i : i + w] if x))
            print shotsUsed, maxHits
            best = min(best, shotsUsed + maxHits)

    print 'Case #' + str(t + 1) + ': ' + str(shots + best)

