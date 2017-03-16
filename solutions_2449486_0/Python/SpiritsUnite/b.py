t = int(raw_input())

for C in xrange(t):
    ans = "YES"
    h, w = map(int, raw_input().split())
    grid = [map(int, raw_input().split()) for i in xrange(h)]
    for r in xrange(h):
        if ans == "NO": break
        for c in xrange(w):
            if ans == "NO": break
            row = grid[r]
            col = [l[c] for l in grid]
            if not all(x <= grid[r][c] for x in row) and not all(x <= grid[r][c] for x in col):
                ans = "NO"
    print "Case #{0}: {1}".format(C + 1, ans)

