#!/usr/bin/python3.4
import os
import sys


class Grid:

    def __init__(self, r, c, m):
        self.r = r
        self.c = c
        self.m = m
        self.left_to_place = m
        self.grid = [['.' for i in range(c)] for j in range(r)]
        self.verification_grid = [['.' for i in range(c)] for j in range(r)]
        self.lost = False
        self.solve()

    def __repr__(self):
        return '\n'.join(''.join(row) for row in self.grid)

    def is_lost(self):
        """Returns true if this state of the Grid represents a loss."""
        return self.lost or self.left_to_place > 0

    def place(self, i, j):
        if i >= self.r or j >= self.c:
            print("Cannot place mine at %d, %d" % (i, j))
            exit(1)
        if self.left_to_place > 0 and self.grid[i][j] == '.' and not (self.c > 2 and self.left_to_place == 1 and (j == 1 or (j == 0 and self.c > 1 and self.grid[i][1] == '.')) and i > 1):
            self.grid[i][j] = '*'
            self.left_to_place -= 1

    def unplace(self, i, j):
        if i >= self.r or j >= self.c:
            print("Cannot unplace mine at %d, %d" % (i, j))
            exit(1)
        if self.grid[i][j] == '*':
            self.grid[i][j] = '.'
            self.left_to_place += 1

    def fill_with_mines(self):
        for i in range(self.r):
            for j in range(self.c):
                self.place(i, j)

    def solve(self):
        self.grid[0][0] = 'c'
        if self.m > self.r * self.c - 1:
            self.lost = True
            return
        elif self.m == self.r * self.c - 1:
            self.fill_with_mines()
            return
        if self.r == 1 or self.c == 1:
            self.solve_single_dimensional()
            return
        if self.r == 2 or self.c == 2:
            self.solve_width_two()
            return
        # Now we know we have at least 3*3 grid.
        for i in range(self.r - 1, 1, -1):
            for j in range(self.c - 1, -1, -1):
                self.place(i, j)
        if self.r * self.c - self.m == 7:
            self.lost = True
            return
        if self.left_to_place % 2 == 1:
            self.unplace(2, 0)
            self.unplace(2, 1)
            self.unplace(2, 2)
        for i in range(self.c - 1, 1, -1):
            self.place(0, i)
            self.place(1, i)

    def solve_single_dimensional(self):
        if self.c == 1:
            for i in range(self.r - self.m, self.r):
                self.place(i, 0)
        elif self.r == 1:
            for i in range(self.c - self.m, self.c):
                self.place(0, i)

    def solve_width_two(self):
        if self.m == self.r * self.c - 2 or self.left_to_place % 2 == 1:
            self.lost = True
            return
        elif self.c == 2:
            for i in range(self.r - self.m // 2, self.r):
                self.place(i, 0)
                self.place(i, 1)
        elif self.r == 2:
            for i in range(self.c - self.m // 2, self.c):
                self.place(0, i)
                self.place(1, i)

    def to_s(self):
        if self.is_lost():
            #return 'Impossible: %d, %d, %d\n%s' % (self.r, self.c, self.m, self.__repr__())
            return 'Impossible'
        else:
            return self.__repr__()

    def v_to_s(self):
        return '\n'.join(''.join(x.__str__() for x in row) for row in self.verification_grid)

    def verify(self):
        # Copy over mines.
        for i in range(self.r):
            for j in range(self.c):
                if self.grid[i][j] == '*':
                    self.verification_grid[i][j] = '*'
        if self.is_lost():
            return True
        frontier = [[0, 0]]
        seen = []
        while len(frontier) > 0:
            i, j = frontier.pop()
            seen.append([i, j])
            nadj = self.adjacent_mines(i, j)
            self.verification_grid[i][j] = nadj
            if nadj == 0:
                frontier.extend([x for x in self.adjacent_to(i, j) if x not in seen])
        for i in range(self.r):
            for j in range(self.c):
                if self.verification_grid[i][j] == '.' and self.grid[i][j] != '*':
                    return False
        return True

    def adjacent_mines(self, i, j):
        result = 0
        for i, j in self.adjacent_to(i, j):
            if self.grid[i][j] == '*':
                result += 1
        return result

    def adjacent_to(self, i, j):
        result = []
        if i > 0 and j > 0:
            result.append([i - 1, j - 1])
        if i > 0:
            result.append([i - 1, j])
        if i > 0 and j < self.c - 1:
            result.append([i - 1, j + 1])
        if j > 0:
            result.append([i, j - 1])
        if j < self.c - 1:
            result.append([i, j + 1])
        if i < self.r - 1 and j > 0:
            result.append([i + 1, j - 1])
        if i < self.r - 1:
            result.append([i + 1, j])
        if i < self.r - 1 and j < self.c - 1:
            result.append([i + 1, j + 1])
        return result

g = Grid(4, 2, 4)
g.to_s()

if not os.environ.get('USE_STDIN'):
    exit(0)

Z = int(sys.stdin.readline().strip())

for test in range(Z):
    r, c, m = [int(X) for X in sys.stdin.readline().strip().split()]
    print("Case #%d:" % (test + 1))
    g = Grid(r, c, m)

    print(g.to_s())
    if not g.verify():
        print("INVALID:")
        print(g.v_to_s())
