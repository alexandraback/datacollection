import sys
import math

'''
Yeah I pretty much figured it out all manually. Not 100% sure for 5 and 6
cases though.
'''

def test():
    # If size is >= 7 then Richard can pick one with a hole in it
    # if rows and cols >= 3, so richard automatically wins
    size, rows, cols = map(int, sys.stdin.readline().strip().split())

    # Ensure cols >= rows
    if rows > cols: rows, cols = cols, rows

    if (rows * cols) % size != 0:
        # Not a multiple: Cannot fill grid, ever
        return 'RICHARD'
    if size >= 7:
        # Richard can make a hole or an L that is too large
        return 'RICHARD'

    m = ((size - 1) / 2) + 1
    side1 = math.ceil(m)
    side2 = math.floor(m)
    # If >= 5, rows and cols must be >= 3
    if (side1 > cols or side2 > rows):
        # Richard can make an L that is too large
        return 'RICHARD'
    if size > rows and size > cols:
        # No way to fit the longest line inside
        return 'RICHARD'
    if size <= 3:
        # 1 fills any. 2 and 3 fill any multiple.
        return 'GABRIEL'

    if size == 4:
        if cols >= 4 and rows >= 3:
            return 'GABRIEL'
        return 'RICHARD'

    if size == 5:
        # 5-ominoes can tile 3x5 without W. W can tile in 5x4
        # BUT.. W can ALSO tile in 3x10
        if cols >= 5 and rows >= 4:
            return 'GABRIEL'
        if rows == 3 and cols >= 10:
            return 'GABRIEL'
        return 'RICHARD'

    if size == 6:
        if cols >= 6 and rows >= 5:
            return 'GABRIEL'
        # 6x4 not possible because 4 and 6 not coprime
        # 6x3 not possible because 6 and 3 not coprime
        return 'RICHARD'


def main(n):
    ''' Read and perform n test cases. '''

    for i in range(n):
        answer = test()
        print('Case #{}: {}'.format(i+1, answer))

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    main(n)
