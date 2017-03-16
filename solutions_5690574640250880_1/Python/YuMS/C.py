from sys import stdout
def solve():
    RCM = raw_input()
    R, C, M = map(int, RCM.split())
    blank = R * C - M
    if blank == 1:
        # print 0
        # print like this
        # c***
        # ****
        # ****
        for i in range(R):
            for j in range(C):
                stdout.write('c' if i == 0 and j == 0 \
                    else '*')
            print
        return True
    for row in range(1, R + 1):
        # row of blank block
        max_column = blank / row
        column = max_column
        left = blank - column * row
        while left < row + column - 1 and column > 0:
            if (row == 1 and row < R) or \
                    (column == 1 and column < C):
                column -= 1
                left = blank - column * row
                continue
            if column > C:
                column -= 1
                left = blank - column * row
                continue
            #print row, column, left
            if left == 0:
                if R >= row and C >= column:
                    # print 1
                    # print like this
                    # c.....**
                    # ......**
                    # ......**
                    # ********
                    # ********
                    first = True
                    for i in range(R):
                        for j in range(C):
                            if first:
                                stdout.write('c')
                                first = False
                                continue
                            stdout.write('.' if i < row and j < column \
                                else '*')
                        print
                    return True
            elif left > 1:
                if left < column and row < R:
                    # print 2
                    # print like this
                    # c.....**
                    # ......**
                    # ......**
                    # ....****
                    # ********
                    first = True
                    for i in range(R):
                        for j in range(C):
                            if first:
                                stdout.write('c')
                                first = False
                                continue
                            stdout.write('.' if (i < row and j < column) \
                                or (i == row and j < left) else '*')
                        print
                    return True
                if left < row and column < C:
                    # print 3
                    # print like this
                    # c......*
                    # .......*
                    # ......**
                    # ********
                    # ********
                    first = True
                    for i in range(R):
                        for j in range(C):
                            if first:
                                stdout.write('c')
                                first = False
                                continue
                            stdout.write('.' if (i < row and j < column) \
                                or (i < left and j == column) else '*')
                        print
                    return True
                if 3 < left < row + column - 1 and 2 < column < C and \
                        2 < row < R:
                    # print 4
                    # print like this
                    # c...
                    # ....
                    # ...*
                    # ..**
                    first = True
                    left_right = min(row - 1, left - 2)
                    for i in range(R):
                        for j in range(C):
                            if first:
                                stdout.write('c')
                                first = False
                                continue
                            stdout.write('.' if (i < row and j < column) \
                                or (i < left_right and j == column) or \
                                (i == row and j < left - left_right) else '*')
                        print
                    return True
            column -= 1
            left = blank - column * row
    return False

def main():
    T = input()
    for i in range(1, T + 1):
        print 'Case #%d:' % i
        if not solve():
            print 'Impossible'

if __name__ == '__main__':
    main()
