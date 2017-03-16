import re
from sys import stdin
import numpy


BOMB = -1


class Board(object):

    def __init__(self, R, C, _bombs=None, _nrb=None):
        self.R = R
        self.C = C
        if _bombs:
            self._bombs = _bombs
            self._nrb = _nrb or [
                self.compute_n(i % C, i / C)
                for i in xrange(R*C)
            ]
        else:
            self._bombs = [1] * (R*C)
            self._nrb = [None] * (R*C)

    def copy(self):
        return Board(self.R, self.C, self._bombs[:], self._nrb[:])

    def rotate(self):

        def rarr(arr):
            narr = [None] * len(arr)
            for i in xrange(self.R * self.C):
                x, y = i % self.C, i / self.C
                narr[y + x * self.R] = arr[x + y * self.C]
            return narr

        return Board(self.C, self.R, rarr(self._bombs), rarr(self._nrb))

    def putzero(self, c, r):
        self = self.copy()

        for y in xrange(r-1,r+2):
            for x in xrange(c-1,c+2):
                if y < 0 or x < 0 or y >= self.R or x >= self.C:
                    continue
                self._bombs[x + y * self.C] = 0

        for y in xrange(r-1,r+2):
            for x in xrange(c-1,c+2):
                if y < 0 or x < 0 or y >= self.R or x >= self.C:
                    continue
                self._nrb[x + y * self.C] = self.compute_n(x, y)

        self.freeze()
        return self

    def freeze(self):
        self._numbers = list(self._gen_numbers())
        self._repr = self._gen_repr()
        return self

    def numbers(self):
        return self._numbers

    def _gen_numbers(self):
        for y in xrange(0, self.R):
            for x in xrange(0, self.C):
                if 0 < self._nrb[x + y * self.C] <= 8:
                    yield (x, y)

    def _gen_repr(self):
        return "\n".join(
            "".join(
                str(self._nrb[x + y * self.C]) if self._bombs[x + y * self.C] == 0 else "*"
                for x in xrange(self.C)
            )
            for y in xrange(self.R)
        )

    def __repr__(self):
        return self._repr

    def __hash__(self):
        return hash(self._repr)

    def __eq__(self, other):
        return self._repr == other._repr

    def compute_n(self, c, r):
        s = 0

        for y in xrange(r-1,r+2):
            for x in xrange(c-1,c+2):
                if y < 0 or x < 0 or y >= self.R or x >= self.C:
                    continue
                if self._bombs[x + y * self.C] == 1:
                    s += 1

        return s

    @property
    def M(self):
        return sum(self._bombs)

    def iniconf(self):
        base = repr(self)
        base = re.sub(r"[1-8]", ".", base)
        base = re.sub(r"0", "c", base, count=1)
        base = re.sub(r"0", ".", base)
        if "c" not in base:
            base = base.replace(".", "c")
        return base


def explore(R, C):
    visited = set()
    solutions = {}

    def visit(board):
        if board in visited:
            return False

        visited.add(board)
        solutions.setdefault(board.M, board)
        return True

    def dfs(board):
        for number in board.numbers():
            nboard = board.putzero(*number)
            if visit(nboard):
                dfs(nboard)

    for r in xrange(0, R + 1 // 2):
        for c in xrange(0, C + 1 // 2):
            board = Board(R, C).putzero(c, r)
            visit(board)
            dfs(board)

    return solutions


class Unknown(Exception):
    pass


def pragmatic(x, y, n):
    if n == 0:
        return None
    elif n == 1:
        return Board(y, x, [0] + [1] * (x*y - 1)).freeze()

    if n > x * y:
        return None

    if x < y:
        ans = pragmatic(y, x, n)
        return ans and ans.rotate().freeze()

    if y == 1:
        return Board(y, x, [0] * n + [1] * (x - n)).freeze()

    if y == 2:
        if (n % 2) != 0 or n < 4:
            return None

        return Board(y, x, [0] * (n / 2) + [1] * (x - n / 2) +
                           [0] * (n / 2) + [1] * (x - n / 2)).freeze()

    if n in {2,3,5,7}:
        return None
    if n >= 2 * x and n % x != 1:
        return Board(y, x, [0] * n + [1] * (y*x - n)).freeze()
    if n > 3 * x and n % x == 1:
        base = [0] * n + [1] * (y*x - n)
        base[n] = 0
        base[n-2] = 1
        return Board(y, x, base).freeze()
    if n >= 2 * y and n % y != 1:
        return Board(x, y, [0] * n + [1] * (y*x - n)).rotate().freeze()

    ans = pragmatic(x, y - 1, n)
    if ans:
        return Board(y, x, ans._bombs + [1] * x).freeze()

    ans = pragmatic(x - 1, y, n)
    if ans:
        bombs = ans._bombs
        for row in xrange(y):
            n = row * x
            bombs[n:n] = [1]
        return Board(y, x, bombs).freeze()

    raise Unknown((x,y,n))


def pexplore(n):
    for x in xrange(1,n+1):
        for y in xrange(1,x+1):
            for n in xrange(0,x*y+1):
                pragmatic(x,y,n)


T = int(next(stdin))
for t in xrange(1,T+1):
    print "Case #{}:".format(t)
    R,C,M = map(int,next(stdin).split(" "))
    sol = pragmatic(C,R,R*C-M)
    if not sol:
        print "Impossible"
    else:
        print sol.iniconf()
