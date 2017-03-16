data = iter(open('D-small-attempt0.in').read().splitlines())
cases = int(next(data))

for case in range(1, cases + 1):
    K, C, S = map(int, next(data).split())
    pows = []
    for p in range(C):
        pows.append(K ** p)
    coefficients = range(K)
    positions = []
    height = 0
    pos = 0
    for co in coefficients:
        if height == len(pows):
            height = 0
            positions.append(pos+1)
            pos = 0
        pos += co * pows[height]
        height += 1
    if pos:
        positions.append(pos+1)
    if not positions:
        positions = ['1']
    positions = map(str, positions)
    ans = "IMPOSSIBLE" if len(positions) > S else " ".join(positions)
    print "Case #%d: %s" % (case, ans)
