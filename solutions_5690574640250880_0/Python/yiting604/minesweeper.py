import sys


def get_line():
    return sys.stdin.readline().strip()

def get_case_prefix(idx):
    return "Case #" + str(idx+1) + ":"

class Cell:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.mark = '*'

    def __repr__(self):
        return str(self)

    def __str__(self):
        return "(" + str(self.x) + "," + str(self.y) + ")"

class Grid:
    def __init__(self, r, c, m):
        self.r = r
        self.c = c
        self.m = m
        self.n = r * c - m
        self.cells = set()
        self.rows = []
        for x in range(r):
            new_row = []
            for y in range(c):
                new_cell = Cell(x, y)
                self.cells.add(new_cell)
                new_row.append(new_cell)
            self.rows.append(new_row)

    def get_neighbors(self, cell):
        neighbors = set()
        for c in self.cells:
            distance = (c.x - cell.x) * (c.x - cell.x) + (c.y - cell.y) * (c.y - cell.y)
            if distance <= 2:
                neighbors.add(c)
        return neighbors

    def walk(self, click_set, neighbor_set):
        opened_set = click_set | neighbor_set
        n_opened = len(opened_set)
#        print click_set, opened_set, n_opened
        if self.n == n_opened:
            return opened_set
        elif self.n < n_opened:
            return None
        for c in neighbor_set:
            neighbors = self.get_neighbors(c)
#            print neighbors
            new_neighbors = neighbors - opened_set
            if new_neighbors:
                new_click_set = set(click_set)
                new_click_set.add(c)
                result =  self.walk(new_click_set, neighbor_set | new_neighbors)
                if result:
                    return result
        return None
            

def process_testcase(idx):
    params = map(int, get_line().split())
    r = params[0]
    c = params[1]
    m = params[2]

    print get_case_prefix(idx)

    grid = Grid(r, c, m)
    result = grid.walk(set(), set([grid.rows[0][0]]))
    if result:
        for x in grid.cells:
            if x in result:
                x.mark = '.'
            else:
                x.mark = '*'
        grid.rows[0][0].mark = 'c'
        for row in grid.rows:
            print "".join([x.mark for x in row])
    else:
        print "Impossible"


def main():
    num_testcases = int(get_line())
    for idx in range(num_testcases):
        process_testcase(idx)

if __name__ == "__main__":
    main()
