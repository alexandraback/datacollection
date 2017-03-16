__author__ = 'horban'

import unittest
import cProfile

import sys

sys.setrecursionlimit(50 * 50 + 100)


def gen_c(inp):
    els = [int(p) for p in inp.split()]
    for t in range(1, els.pop(0) + 1):
        a, b, c = els[:3]
        els = els[3:]
        yield t, a, b, c


def mkbrd(r, c):
    return [[0] * c for _ in range(r)]


def dims(b):
    r = len(b)
    c = len(b[0])
    return r, c


def in_brd(r, c, brd):
    return


def gen_sor(row, col, brd):
    rows, cols = dims(brd)
    for orow in [-1, 0, 1]:
        for ocol in [-1, 0, 1]:
            if (orow or ocol):
                y = orow + row
                x = ocol + col
                if 0 <= y and y < rows and 0 <= x and x < cols:
                    yield y, x


def neigh_map(brd, f):
    r, c = dims(brd)
    b = mkbrd(r, c)
    for y in range(r):
        for x in range(c):
            b[y][x] = f(brd[y][x], [brd[cr][cc] for cr, cc in gen_sor(y, x, b)])
    return b


def near_mines(brd):
    def f(cell, near_cells):
        if cell == 1:
            return 9
        else:
            return sum(near_cells)

    return neigh_map(brd, f)


def most_connected(brd):
    def f(cell, near_cells):
        zero_cnt = near_cells.count(0)
        if cell == 9:
            return 9
        elif cell == 0:
            return 1 + zero_cnt
        else:
            return zero_cnt

    return neigh_map(brd, f)


def pick_lowest(brd):
    r, c = dims(brd)
    return min((brd[y][x], y, x)
               for y in range(r)
               for x in range(c))


def fill_k(rs, cs, k):
    b = mkbrd(rs, cs)
    for _ in range(k):
        v, r, c = pick_lowest(most_connected(near_mines(b)))
        b[r][c] = 1
    return b


def can_win(r, c, k):
    if k == r * c - 1:
        return True

    b = fill_k(r, c, k)
    v, _, _ = pick_lowest(most_connected(near_mines(b)))
    if v == 0:
        return False
    return True


def draw(mines, simple=False):
    R, C = dims(mines)
    if not simple:
        b = near_mines(mines)
        _, cr, cc = min((b[r][c], r, c)
                        for r in range(R)
                        for c in range(C))
    else:
        cr, cc = -1, -1
    ans = ''
    for r in range(R):
        for c in range(C):
            if mines[r][c]:
                ans += '*'
            elif r == cr and cc == c:
                ans += 'c'
            else:
                ans += '.'
        ans += '\n'
    return ans


def search_order(r, c):
    options = [(-(x * x + y * y), y, x)
               for y in range(r)
               for x in range(c)]
    options.sort()
    return [(y, x) for _, y, x in options]


def reg_search_order(r, c):
    for y in range(r):
        for x in range(c):
            yield y, x


class SolutionFound(BaseException):
    def __init__(self, result):
        self.result = result


class Timeout(BaseException):
    pass

class NoSolution(BaseException):
    pass


def apply_move(brd, move):
    r, c = move
    if brd[r][c] == 0:
        brd[r][c] = 1
        return True
    else:
        return False


def retract_move(brd, move):
    r, c = move
    brd[r][c] = 0


STEPS_LIMIT = 100000


def can_unfold(brd):
    nm = near_mines(brd)
    rs, cs = dims(brd)

    _, r0, c0 = min((nm[r][c], r, c)
                    for r in range(rs)
                    for c in range(cs))

    mark = mkbrd(*dims(brd))
    q = []
    q.append((r0, c0))
    mark[r0][c0] = 1
    while q:
        r, c = q.pop()
        if nm[r][c] == 0:
            for nr, nc in gen_sor(r, c, nm):
                if mark[nr][nc] == 0:
                    mark[nr][nc] = 1
                    q.append((nr, nc))

    return [(r, c)
            for r in range(rs)
            for c in range(cs)
            if brd[r][c] == 0 and mark[r][c] == 0]


def rec_serach_good_brd(brd, mines, trg_mines, steps, tabu_set, move_order):
    h = hash(tuple(v
                   for row in brd
                   for v in row))

    if h in tabu_set:
        return steps
    else:
        tabu_set.add(h)
        revb = [list(row) for row in brd]
        revb.reverse()
        tabu_set.add(hash(tuple(v
                                for row in revb
                                for v in row)))
        for row in revb:
            row.reverse()
        tabu_set.add(hash(tuple(v
                                for row in revb
                                for v in row)))
        revb.reverse()
        tabu_set.add(hash(tuple(v
                                for row in revb
                                for v in row)))
    #print draw(brd, simple=True)


    bad_pos = []

    if mines == trg_mines and not can_unfold(brd):
        raise SolutionFound(draw(brd))

    if bad_pos:
        choices = bad_pos
    else:
        choices = move_order

    for move in choices:
        if apply_move(brd, move):
            steps = rec_serach_good_brd(brd, mines + 1, trg_mines, steps, tabu_set, move_order) + 1
            if steps > STEPS_LIMIT:
                raise Timeout()
            retract_move(brd, move)

    return steps

def topfill(rs, cs, m):

    if m == 0:
        return mkbrd(rs, cs)

    transpose = False
    if(cs < rs):
        transpose = True
        cs, rs = rs, cs
    
    b = mkbrd(rs, cs)


    if rs >= 4 and cs*rs-m in [2,3,5,7]:
        raise NoSolution()


    if rs * cs == m + 1:
        for c in range(cs):
            for r in range(rs):
                b[r][c] = 1
        b[0][0] = 0

    elif rs == 1:
        for c in range(m):
            b[0][c] = 1
    elif rs == 2:
        if m % 2 == 0:
            for c in range(m/2):
                for r in range(rs):
                    b[r][c] = 1
        else:
            raise NoSolution()
    else:
        for r in range(rs):
            for c in range(cs):
                if m == 1 and c == cs-2:
                    m = 0
                    b[r+1][0]=1
                    break
                b[r][c] = 1
                m -= 1

                if m == 0:
                    break
            if m == 0:
                break

    if transpose:
        bt = mkbrd(cs, rs)
        for c in range(cs):
            for r in range(rs):
                bt[c][r] = b[r][c]
        b = bt
    return b

def rect_does_the_job(rs, cs, mines):
    m = rs*cs - mines
    for k in range(2, m):
        if m % k == 0:
            d = m / k
            if k <= cs - 2 and d <= rs - 2:
                b = mkbrd(rs, cs)
                for r in range(rs):
                    for c in range(cs):
                        b[r][c] = 1
                for r in range(d):
                    for c in range(k):
                        b[r][c] = 0
                return b
    return None

def search_good_brd(rs, cs, mines):
    try:
        pos_sol = topfill(rs, cs, mines)
        if not can_unfold(pos_sol):
            print 'easy case'
            return draw(pos_sol)

        sec_pos = rect_does_the_job(rs, cs, mines)
        if sec_pos and not can_unfold(sec_pos):
            print 'new easy'
            return draw(sec_pos)

        rec_serach_good_brd(mkbrd(rs, cs), 0, mines, 0, set(), search_order(rs, cs))
    except Timeout:
        print 'tle on', rs, cs, mines
        from pprint import pprint
        pprint(pos_sol, width=30)
        return 'Impossible\n'
    except SolutionFound, s:
        from pprint import pprint
       # pprint(pos_sol, width=120)
        print s.result
        print 'found sol'
        return s.result
    except NoSolution:
        print 'nosol'
        return 'Impossible\n'
    else:
        print 'done all'

    return 'Impossible\n'


def solvec(inp):
    res = ''
    for t, r, c, m in gen_c(inp):
        ans = search_good_brd(r, c, m)
        res += 'Case #{}:\n{}'.format(t, ans)
    return res


def solvec_file(name):
    with open(name) as fin:
        with open(name.replace('in', 'out'), 'w') as fout:
            fout.write(solvec(fin.read()))


class TestC(unittest.TestCase):
    def setUp(self):
        self.inp = '''5
5 5 23
3 1 1
2 2 1
4 7 3
10 10 82'''

    def test_search_order(self):
        self.assertEqual([(1, 1), (0, 1), (1, 0), (0, 0)],
                         search_order(2, 2))

    def test_cread(self):
        self.assertEqual((1, 5, 5, 23), next(gen_c(self.inp)))

    def test_mkbrd(self):
        self.assertEqual([[0, 0, 0], [0, 0, 0]], mkbrd(2, 3))

    def test_gensor(self):
        self.assertEqual([(0, 1), (1, 0), (1, 1)], list(gen_sor(0, 0, mkbrd(3, 3))))

    def test_search_good_brd(self):
        print search_good_brd(50, 50, 50*50-12)

    def test_can_unfold(self):
        self.assertEqual([], can_unfold([[0]]))
        self.assertEqual([], can_unfold([[0, 0]]))
        self.assertEqual([], can_unfold([[0, 1]]))
        self.assertEqual([], can_unfold([[0, 0, 1]]))
        self.assertEqual([(1, 2)], can_unfold([[0, 0, 1],
                                               [0, 0, 0]]))
        self.assertEqual([], can_unfold([[0, 0, 1],
                                         [0, 0, 1]]))
        self.assertEqual([(2, 2)], can_unfold([[0, 0, 1],
                                               [0, 0, 1],
                                               [0, 0, 0]]))
        self.assertEqual([(1, 0)], can_unfold([[0, 1, 1],
                                               [0, 1, 1],
                                               [1, 1, 1]]))

    def test_neigh_map(self):
        self.assertEqual([[2, 2, 1],
                          [2, 2, 1]],
                         neigh_map([[1, 1, 0],
                                    [0, 0, 0]],
                                   lambda x, els: x + sum(els)))

    def test_near_mines(self):
        self.assertEqual([[9, 9, 1],
                          [2, 2, 1]],
                         near_mines([[1, 1, 0],
                                     [0, 0, 0]]))

    def test_most_connected(self):
        self.assertEqual([[9, 2, 2],
                          [0, 2, 2]],
                         most_connected([[9, 1, 0],
                                         [1, 1, 0]]))

    def test_pick_lowest(self):
        self.assertEqual((0, 1, 0), pick_lowest([[9, 2, 2],
                                                 [0, 2, 2]]))

    def test_filling(self):
        self.assertEqual([[1, 1], [1, 0], [0, 0]], fill_k(3, 2, 3))

    def test_can_win(self):
        self.assertEqual(True, can_win(3, 4, 8))
        self.assertEqual(False, can_win(3, 2, 6 - 3))
        self.assertEqual(True, can_win(3, 2, 6 - 1))
        self.assertEqual(False, can_win(3, 2, 6 - 2))
        self.assertEqual(True, can_win(3, 2, 6 - 4))
        self.assertEqual(False, can_win(3, 2, 6 - 5))
        self.assertEqual(True, can_win(3, 2, 6 - 6))
        self.assertEqual(True, can_win(3, 1, 1))
        self.assertEqual(True, can_win(12, 1, 1))
        self.assertEqual(True, can_win(12, 1, 5))
        self.assertEqual(True, can_win(12, 1, 10))
        self.assertEqual(True, can_win(12, 1, 11))
        self.assertEqual(True, can_win(2, 1, 0))
        self.assertEqual(True, can_win(2, 1, 1))
        self.assertEqual(True, can_win(2, 2, 0))
        self.assertEqual(False, can_win(2, 2, 1))
        self.assertEqual(False, can_win(2, 2, 2))
        self.assertEqual(True, can_win(2, 2, 3))

    def test_draw(self):
        self.assertEqual('*.c\n' +
                         '*..\n',
                         draw([[1, 0, 0],
                               [1, 0, 0]]))

    def test_solvec(self):
        pass


solvec_file('/tmp/C-large.in')

#####
####.
##...
##...