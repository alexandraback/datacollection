def solve(r, c, m):
    if r == 1:
        return (1, c - m, 0)
    if c == 1:
        return (r - m, 1, 0)
    if r * c - 1 == m:
        return (1, 1, 0)
    cache = {}
    def dfs(r, c, m):        
        if r <= 1 or c <= 1:
            return None
        if (r, c, m) in cache:
            return cache[(r, c, m)]
        if m == 0:
            cache[(r, c, m)] = (r, c, m)
            return (r, c, m)
        res = []
        if m >= c:
            res.append(dfs(r - 1, c, m - c))
        if m >= r:
            res.append(dfs(r, c - 1, m - r))
        if (r > 2 and c > 2) and (r - 2) + (c - 2) - 1 >= m:
            res.append((r, c, m))
        if any(r is not None for r in res):
            cache[(r, c, m)] = min((r for r in res if r is not None),
                                   key = lambda x: x[2])
            return cache[(r, c, m)]
        else:
            cache[(r, c, m)] = None
            return None
    return dfs(r, c, m)

def make_field(r, c, m):
    field = [list("*"*C) for _ in xrange(R)]
    for y in xrange(r):
        for x in xrange(c):
            field[y][x] = "."
    field[0][0] = "c"
    q = [(max(0, r - 1), max(0, c - 1))]
    while m > 0:
        y, x = q.pop(0)
        field[y][x] = "*"
        m -= 1
        if y > 2:
            q.append((y - 1, x))
        if x > 2:
            q.append((y, x - 1))
    return "\n".join("".join(f) for f in field)

for T in xrange(1, input() + 1):
    R, C , M = map(int, raw_input().split())
    ans = solve(R, C, M)
    print "Case #{}:".format(T)
    if ans is None:
        print "Impossible"
    else:
        print make_field(*ans)

