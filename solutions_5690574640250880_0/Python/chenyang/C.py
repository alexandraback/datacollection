class mbuf:
    def __init__(self, n):
        self.n = n
    def get(self, n):
        return "".join([self.next() for _ in range(n)])
    def next(self):
        if self.n == 0:
            return "."
        self.n -= 1
        return "*"

def main1():
    for t in range(input()):
        r, c, m = map(int, raw_input().split())
        res = ""
        if c == 1:
            if m > r - 2:
                res = "Impossible "
            else:
                res = "c\n.\n" + m * "*\n" + (r - m - 2) * ".\n"
        elif r == 1 :
            if m > c - 2:
                res = "Impossible "
            else:
                res = "c." + m * "*" + (c - m - 2) * "."
        elif m > r * c - 4:
            res = "Impossible "
        else:
            mb = mbuf(m)
            rest = ""
            for _ in range(r-2):
                rest = mb.get(c)[::-1] + "\n" + rest
            a = mb.get(c-2)[::-1]
            b = mb.get(c-2)[::-1]
            res = "c." + b + "\n.." + a + "\n" + rest
        print "Case #{}:".format(t+1)
        print res[:-1]

ND =((-1, -1), (-1, 0), (-1, 1),
     ( 0, -1),          ( 0, 1),
     ( 1, -1), ( 1, 0), ( 1, 1))

N = ((-1, 0), (0, -1), (0, 1), (1, 0))

def neighbors(grid, r, c, char, n):
    l = []
    tr, tc = len(grid), len(grid[0])
    for dr, dc in n:
        rr, cc = r + dr, c + dc
        if 0 <= rr < tr and 0 <= cc < tc and grid[rr][cc] == char:
            l.append((rr, cc))
    return l

def print_grid(g):
    for i in g:
        print "".join(i)

import pdb

def main1():
    for t in range(input()):
        r, c, m = map(int, raw_input().split())
        problem(r, c, m, t)


def problem(r, c, m, t):
    resend = None
    def solve(grid, en, end, pos):

        #print_grid(grid)
        covered = len(pos) + len(end)
        if r*c - m < covered:
            return False, False
        if r*c - m == covered:
            return grid, end
        for e in en:
            newen = en.copy()
            newen.update(neighbors(grid, e[0], e[1], "*", N))
            newen.remove(e)
            newend = end.copy()
            newend.update(neighbors(grid, e[0], e[1], "*", ND))
            newend.remove(e)
            newpos = pos.copy()
            newpos.add(e)
            grid[e[0]][e[1]] = "."
            resgrid, resend = solve(grid, newen, newend, newpos)
            if resgrid:
                return resgrid, resend
            grid[e[0]][e[1]] = "*"
        return False, False

    grid = [["*" for _ in range(c)] for _ in range(r)]

    if r * c - m == 1:
        grid[0][0] = 'c'
        print "Case #{}:".format(t+1)
        print_grid(grid)
        return
    pos = {(0, 0)}
    grid[0][0] = '.'
    en = set(neighbors(grid, 0, 0, "*", N))
    end = set(neighbors(grid, 0, 0, "*", ND))
    #print_grid(grid)
    #print en, end, pos
    resgrid, resend = solve(grid, en, end, pos)
    print "Case #{}:".format(t+1)
    if resgrid:
        resgrid[0][0] = 'c'
        for r, c in resend:
            resgrid[r][c] = "."
        print_grid(resgrid)
    else:
        print "Impossible"


main1()

#print neighbors([".**.",
#                 "*..."], 1 , 1, '*', N)
