#!/usr/bin/env python
import sys
def read_int(): return int(sys.stdin.readline())
def read_ints(): return [int(x) for x in sys.stdin.readline().split()]
def debug(a): sys.stderr.write(str(a) + '\n')

class Table:
    def __init__(self, cols, rows):
        self.buf = [['*'] * cols for _ in range(rows)]

    def display(self):
        self.buf[0][0] = 'c'
        for arr in self.buf:
            print(''.join(arr))

    def reveal(self, x, y):
        self.buf[y][x] = '.'

    def reveal_range(self, width, height):
        for x in range(width):
            for y in range(height):
                self.buf[y][x] = '.'

def check(width, height, rest, table):
    # Mines in this area
    diff = width * height - rest

    if diff == 0:
        table.reveal_range(width, height)
        table.display()
        return True

    # Two rows.
    if height == 2:
        if rest >= 4 and rest % 2 == 0:
            table.reveal_range(rest // 2, 2)
            table.display()
            return True
        else:
            return False

    # Two columns.
    if width == 2:
        if rest >= 4 and rest % 2 == 0:
            table.reveal_range(2, rest // 2)
            table.display()
            return True
        else:
            return False

    if height == 3:
        if width - diff >= 2 or width == diff:
            table.reveal_range(width, 2)
            for x in range(width - diff):
                table.reveal(x, height - 1)
            table.display()
            return True
        else:
            return False

    if diff == width - 1:
        # One extra mine on the second line from the bottom,
        # and the others are on the bottom line.
        table.reveal_range(width, height - 2)
        for x in range(width - 1):
            table.reveal(x, height - 2)
        for x in range(width - diff + 1):
            table.reveal(x, height - 1)
        table.display()
        return True

    if diff > width:
        return False

    # Mines are only on the bottom line
    table.reveal_range(width, height - 1)
    for x in range(width - diff):
        table.reveal(x, height - 1)
    table.display()
    return True

def solve(R, C, M):
    # debug('R={}, C={}, M={}'.format(R, C, M))
    table = Table(C, R)

    # There is no Mine.
    if M == 0:
        table.reveal_range(C, R)
        table.display()
        return

    # Just one space.
    rest = R * C - M
    if rest == 1:
        table.display()
        return

    # One row.
    if R == 1:
        table.reveal_range(C - M, 1)
        table.display()
        return

    # One column.
    if C == 1:
        table.reveal_range(1, R - M)
        table.display()
        return

    # Two or more rows and columns.
    for width in range(2, C+1):
        for height in range(2, R+1):
            if width * height >= rest:
                if check(width, height, rest, table):
                    return

    print('Impossible')

if __name__ == '__main__':
    T = read_int()
    for i in range(T):
        print('Case #{}:'.format(i+1))
        solve(*read_ints())
