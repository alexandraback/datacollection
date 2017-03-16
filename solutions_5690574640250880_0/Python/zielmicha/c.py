import sys
sys.setrecursionlimit(10000)

def test(tab):
    tab = map(list, tab)
    def dump():
        for row in tab:
            print ''.join(row)

    w = len(tab[0])
    h = len(tab)
    mine_count = sum( sum( 1 if ch == '*' else 0 for ch in row ) for row in tab )

    def get(x, y):
        if x < 0 or y < 0 or x >= w or y >= h:
            return '0'
        else:
            return tab[y][x]

    def boom(x, y):
        if x < 0 or y < 0 or x >= w or y >= h:
            return
        if tab[y][x] in ('.', 'c'):
            tab[y][x] = '_'
            ne = [(x + 1, y),
                  (x + 1, y + 1),
                  (x + 1, y - 1),
                  (x - 1, y),
                  (x - 1, y + 1),
                  (x - 1, y - 1),
                  (x, y),
                  (x, y + 1),
                  (x, y - 1)]
            mines = sum([ get(*n) == '*'  for n in ne ])
            if mines == 0:
                for n in ne:
                    boom(*n)

    boom(0, 0)
    for row in tab:
        assert '.' not in row

    return mine_count

def solve(m, r, c):
    if c == 1 or r == 1:
        other = r if c == 1 else c
        chars = []
        for i in xrange(m):
            chars.append('*')
        for i in xrange(other - m - 1):
            chars.append('.')
        chars.append('c')
        if c == 1:
            for ch in chars: print ch
        else:
            print ''.join(chars)
        return

    left = r*c - m
    tab = [ ['*'] * c for i in xrange(r) ]

    def fill(x0, y0, x1, y1):
        for x in xrange(x0, x1):
            for y in xrange(y0, y1):
                tab[y][x] = '.'

    if left in (2, 3, 5):
        print 'Impossible'
        return

    def dump():
        for row in tab:
            print ''.join(row)

    if left == 1:
        tab[0][0] = 'c'
    elif (c == 2 or r == 2) and left % 2 == 1:
        print 'Impossible'
        return
    elif left in (7, ):
        print 'Impossible'
        return
    else:
        cases = [ (x,y) for x in xrange(c-1) for y in xrange(r-1) ]
        cases.sort(key=lambda (a, b): a + b)
        #print c, r, m
        for x, y in cases:
            mmin = 2*x + 2*y + 4
            mmax = (x+2)*(y+2)
            if left >= mmin and left <= mmax:
                break
        else:
            print 'fail', c, r, m
            assert False

        fill(0, 0, 2, 2)
        fill(2, 0, 2 + x, 2)
        fill(0, 2, 2, 2 + y)

        left -= 4 + 2*x + 2*y
        posx = 2

        while left > 0:
            minus = min(left, y)
            fill(posx, 2, posx + 1, 2 + minus)
            left -= minus
            posx += 1

        tab[0][0] = 'c'

    dump()
    assert test(tab) == m

n = int(raw_input())
for i in xrange(n):
    r, c, m = map(int, raw_input().split())
    print 'Case #%d:' % (i+1)
    solve(m, r, c)
