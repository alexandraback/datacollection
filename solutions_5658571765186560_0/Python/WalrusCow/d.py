import sys
import math

def test():
    # If size is >= 7 then Richard can pick one with a hole in it
    # if rows and cols >= 3, so richard automatically wins
    size, rows, cols = map(int, sys.stdin.readline().strip().split())

    # Ensure cols >= rows
    if rows > cols: rows, cols = cols, rows

    if (rows * cols) % size != 0:
        # Not a multiple: Cannot fill grid, ever
        #print('one')
        return 'RICHARD'
    if size >= 7:
        # Richard can make a hole or an L that is too large
        #print('seven')
        return 'RICHARD'

    m = ((size - 1) / 2) + 1
    side1 = math.ceil(m)
    side2 = math.floor(m)
    #print(side1, side2, cols, rows)
    # If >= 5, rows and cols must be >= 3
    if (side1 > cols or side2 > rows):
        # Richard can make an L that is too large
        #print('two')
        return 'RICHARD'
    if size > rows and size > cols:
        # No way to fit the longest line inside
        #print('three')
        return 'RICHARD'
    if size <= 3:
        # 1 fills any. 2 and 3 fill any multiple.
        return 'GABRIEL'

    if size == 4:
        if cols >= 4 and rows >= 3:
            return 'GABRIEL'
        return 'RICHARD'

    # Remaining cases: 4, 5, 6

    # With 5 and 6 can make a hole against a wall in 2 wide
    # x.x.
    # xxx.
    #
    # Remaining cases:
    # (1) Size <= 6
    # (2) Size >= 7, rows or cols <= 2
    # TODO: Can Richard block off a corner?
    # .x..
    # xxx.
    # ....

def main(n):
    ''' Read and perform n test cases. '''

    for i in range(n):
        answer = test()
        print('Case #{}: {}'.format(i+1, answer))

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    main(n)
