import sys

def get_ans(grid, N, idx, rows, cols):

    count = dict()
    for r in grid:
        for c in r:
            count[c] = count.get(c, 0) + 1

    ans = []

    for k, v in count.iteritems():
        if (v % 2) == 1:
            ans.append(k)
    return sorted(ans)


T = int(sys.stdin.readline())

for tc in xrange(1, T + 1):
    N = int(sys.stdin.readline())

    grid = []

    for i in xrange(2 * N - 1):
        grid.append([int(w) for w in sys.stdin.readline().split()])

    ans = get_ans(grid, N, 0, [], [])

    if ans is not None:
        ans = " ".join(map(str, ans))
    else:
        ans = "NONE"
    print "Case #%d: %s" % (tc, ans)
