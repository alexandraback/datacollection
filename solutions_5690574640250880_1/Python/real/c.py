import sys, itertools, collections
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input

def verify(ans, m):
    """ :( """

    ans = [row[:] for row in ans]
    r, c = len(ans), len(ans[0])

    n = [item for row in ans for item in row].count('*')
    assert n == m, '%s != %s' % (n, m)  # :(

    def recurse(i, j):
        if ans[i][j] == 'c':
            return

        ans[i][j] = 'c'
        zero = True
        for dx in xrange(-1, 2):
            for dy in xrange(-1, 2):
                x, y = i + dx, j + dy
                if 0 <= x < r and 0 <= y < c and ans[x][y] == '*':
                    zero = False

        if zero:
            for dx in xrange(-1, 2):
                for dy in xrange(-1, 2):
                    x, y = i + dx, j + dy
                    if 0 <= x < r and 0 <= y < c:
                        recurse(x, y)

    for i in xrange(r):
        for j in xrange(c):
            if ans[i][j] == 'c':
                x, y = i, j

    ans[x][y] = '.'
    recurse(x, y)

    if any(['.' in row for row in ans]):
        return False

    return True


def _get_empty(r, c):
    return [ ['.'] * c for _ in xrange(r) ]


def solve(r, c, m):
    ans = None

    if m == r * c - 1:
        ans = [ ['*'] * c for _ in xrange(r) ]
    elif m == 0:
        ans = _get_empty(r, c)
    elif r == 1:
        if c - m >= 2:
            ans = [['*' if i < m else '.' for i in xrange(c)]]
    elif c == 1:
        if r - m >= 2:
            ans = [['*'] if i < m else ['.'] for i in xrange(r)]
    elif c >= 4 and r >= 4 and c - 2 <= m <= r + c - 5:
        # (5, 5, 4), (4, 4, 3) ...
        ans = _get_empty(r, c)
        for y in xrange(c - 2):
            ans[r - 1][c - y - 1] = '*'
        for x in xrange(m - (c - 2) + 1):
            ans[r - x - 1][c - 1] = '*'
    else:
        mm = m
        if m <= r * c - 4:
            ans = _get_empty(r, c)
            for i in xrange(r - 1, 1, -1):
                for j in xrange(c - 1, -1, -1):
                    if m:
                        ans[i][j] = '*'
                        m -= 1

            for j in xrange(c - 1, 0, -1):
                for i in xrange(1, -1, -1):
                    if m:
                        ans[i][j] = '*'
                        m -= 1

            assert m == 0
        m = mm

    if ans:
        ans[0][0] = 'c'

        if verify(ans, m):
            return ans


for no_t in xrange(1, read_int() + 1):
    r, c, m = read_ints()

    ans = None

    for r2 in xrange(1, r + 1):
        for c2 in xrange(1, c + 1):
            if not ans:
                if r2 == 1 and r != 1:
                    continue
                if c2 == 1 and c != 1:
                    continue

                diff = r * c - r2 * c2
                if diff <= m:
                    tmp = solve(r2, c2, m - diff)
                    if tmp:
                        ans = [ ['*'] * c for _ in xrange(r) ]
                        for i, row in enumerate(tmp):
                            ans[i][:c2] = row
                    elif r2 != c2:
                        tmp = solve(c2, r2, m - diff)
                        if tmp:
                            ans = [ ['*'] * c for _ in xrange(r) ]
                            for i in xrange(r2):
                                for j in xrange(c2):
                                    ans[i][j] = tmp[j][i]

    if ans and verify(ans, m):
        ans = '\n'.join([''.join(row) for row in ans])
    else:
        ans = 'Impossible'

    print 'Case #%d:\n%s' % (no_t, ans)
