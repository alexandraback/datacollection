'''
Created on Apr 11, 2014

@author: sergey

Problem C. Minesweeper Master
'''

import os

def get_data(fullpath):
    if(not os.path.exists(fullpath)):
        print 'file does not exist'
        return []

    result = []
    is_first_line = True
    number_of_test_cases = 0
    is_in_test_case = False
    line_in_test = 0
    with open(fullpath, 'r') as input_file:
        for line in input_file:

            if(is_first_line):
                is_first_line = False
                t = int(line)
                if(t >= 1 and t <= 230):
                    print 'number of test cases', t
                    continue

                print 'invalid number of test cases', t
                return []



            r, c, m = [int(i) for i in line.split(' ')]
#             print 'r', r
#             print 'c', c
#             print 'm', m

            if(not (m >= 0 and m < (r * c) and r >= 1 and c <= 50)):
                print 'invalid r or c or m'
                return []

            result += [{
                        'r': r,
                        'c': c,
                        'm': m
                        }]

    if(t != len(result)):
        print 'expected', t, 'tests, instead got', len(result)
        return []

    return result

def fill_area(r, c, empty_cells, m):
    """
    m > 0
    r >= 3 and c >= 3
    empty_cells >= 4 and empty_cells != 7 and empty_cells != 5 
    """

    result = []

    # special case 4 empty cells
    if(empty_cells == 4):
        print 'special case 4 empty cells'
        for i in xrange(r):
            result += [['*'] * c]
        result[0][0] = 'c'
        result[0][1] = '.'
        result[1][0] = '.'
        result[1][1] = '.'
        return result

    # special case 6 empty cells
    if(empty_cells == 6):
        print 'special case 6 empty cells'
        for i in xrange(r):
            result += [['*'] * c]
        result[0][0] = 'c'
        result[0][1] = '.'
        result[0][2] = '.'
        result[1][0] = '.'
        result[1][1] = '.'
        result[1][2] = '.'
        return result

    # start with empty area and a click in bottom-right corner
    # . . . . . . . . . . . . . .
    # . . . . . . . . . . . . . .
    # . . . . . . . . . . . . . .
    # . . . . . . . . . . . . . .
    # . . . . . . . . . . . . . .
    # . . . . . . . . . . . . . .
    # . . . . . . . . . . . . . c
    for i in xrange(r):
        result += [['.'] * c]
    result[-1][-1] = 'c'
    filled_cells = 0

    # now fill the rectangle, starting from top-left
    # and going from top row to bottom and for each row
    # filling from left to right
    # keep bottom 2 rows and right 2 columns empty
    # and also keep the bottom right corner of the rectangle empty (e)
    # * * * * * * * * * * . .
    # * * * * * * * * * * . .
    # * * * * * * * * * * . .
    # * * * * * * * * * * . .
    # * * * * * * * * * e . .
    # . . . . . . . . . . . .
    # . . . . . . . . . . . c
    #
    # or
    #
    # * * * * * . .
    # * * * * * . .
    # * * * * * . .
    # * * * * * . .
    # * * * * * . .
    # * * * * * . .
    # * * * * * . .
    # * * * * * . .
    # * * * * * . .
    # * * * * e . .
    # . . . . . . .
    # . . . . . . c
    #
    # or
    #
    # same if r == c, leave cell (-3, -3) empty
    # * * * * * * . .
    # * * * * * * . .
    # * * * * * * . .
    # * * * * * * . .
    # * * * * * e . .
    # . . . . . . . .
    # . . . . . . . c
    for row in xrange(r - 2):
        for col in xrange(c - 2):
            if(col == (c - 3) and row == (r - 3)):
                break
            result[row][col] = '*'
            filled_cells += 1
            if(filled_cells == m):
                return result

    # now fill the 2 right columns:
    # in case we need to stop here, use cell (e) to control odd/even number of filled cells
    for row in xrange(r - 3):
        if(m - filled_cells == 1):
            # fill the "e" cell
            result[-3][-3] = '*'
            filled_cells += 1
        elif(m - filled_cells >= 2):
            # fill 2 cells
            result[row][-1] = '*'
            result[row][-2] = '*'
            filled_cells += 2

        if(filled_cells == m):
            return result

    # now fill the 2 bottom rows:
    # in case we need to stop here, use cell (e) to control odd/even number of filled cells
    for col in xrange(c - 3):
        if(m - filled_cells == 1):
            # fill the "e" cell
            result[-3][-3] = '*'
            filled_cells += 1
        elif(m - filled_cells >= 2):
            # fill 2 cells
            result[-1][col] = '*'
            result[-2][col] = '*'
            filled_cells += 2

        if(filled_cells == m):
            return result


    # fill in the "e" cell if needed
    if(m - filled_cells == 1):
        result[-3][-3] = '*'
        filled_cells += 1
        return result

    # at this point all cells should be filled except the 8 or 9 in the bottom right corner
    # * * * * * * * *
    # * * * * * * * *
    # * * * * * * * *
    # * * * * * * . .
    # * * * * * . . .
    # * * * * * . . c
    #
    # or
    #
    # * * * * * * * *
    # * * * * * * * *
    # * * * * * * * *
    # * * * * * . . .
    # * * * * * . . .
    # * * * * * . . c

    return result

def process_case(r, c, m):
    result = []

    empty_cells = (r * c) - m

    # special case: only one empty cell
    if(empty_cells == 1):
        for i in xrange(r):
            result += [['*'] * c]
        result[0][0] = 'c'

    # special cases: smallest side is 1 row or 1 column
    elif(r == 1):
        result = [['c']]
        result[0] += (['.'] * (c - m - 1))
        result[0] += (['*'] * m)
    elif(c == 1):
        result = [['c']]
        for i in xrange(r - m - 1):
            result += [['.']]
        for i in xrange(m):
            result += [['*']]

    # no mines
    elif(m == 0):
        for i in xrange(r):
            result += [['.'] * c]
        result[0][0] = 'c'

    # check if there are any 0-type cells possible
    elif(empty_cells < 4):
        # no 0-type cells means we can't open any other cell
        result = ['Impossible']

    elif(empty_cells == 7):
        result = ['Impossible']

    elif(empty_cells == 5):
        result = ['Impossible']

    # special cases: smallest side is 2 rows or 2 columns
    elif(r == 2):
        if(m % 2 == 0):
            fill_per_row = m / 2
            empty_per_row = empty_cells / 2
            for i in xrange(r):
                result += [['.'] * empty_per_row + ['*'] * fill_per_row]
            result[0][0] = 'c'
        else:
            result = ['Impossible']

    elif(c == 2):
        if(m % 2 == 0):
            filled_rows = m / 2
            empty_rows = empty_cells / 2
            for i in xrange(empty_rows):
                result += [['.'] * c]
            for i in xrange(filled_rows):
                result += [['*'] * c]
            result[0][0] = 'c'

        else:
            result = ['Impossible']

    # special case: only one filled cell
    elif(m == 1):
        for i in xrange(r):
            result += [['.'] * c]
        result[0][0] = 'c'
        result[-1][-1] = '*'

    elif(r == 3 and (m % 3 == 0)):
        fill_per_row = m / 3
        empty_per_row = empty_cells / 3
        for i in xrange(r):
            result += [['.'] * empty_per_row + ['*'] * fill_per_row]
        result[0][0] = 'c'

    elif(c == 3 and (m % 3 == 0)):
        filled_rows = m / 3
        empty_rows = empty_cells / 3
        for i in xrange(empty_rows):
            result += [['.'] * c]
        for i in xrange(filled_rows):
            result += [['*'] * c]
        result[0][0] = 'c'

    elif(r >= 3 and c >= 3):
        result = fill_area(r, c, empty_cells, m)
    else:
        result = ['Impossible']

    return result

def check_rcm(result, r, c, m):
    is_ok = True

    if(result[0] == 'Impossible'):
        return

    if(r != len(result)):
        print '-' * 75
        print 'number of rows expected', r, 'actual', len(result)
        is_ok = False
    if(c != len(result[0])):
        print '-' * 75
        print 'number of cols expected', c, 'actual', len(result[0])
        is_ok = False
    total_m = sum([i.count('*') for i in result])
    if(m != total_m):
        print '-' * 75
        print 'number of mines expected', m, 'actual', total_m
        is_ok = False

    if(not is_ok):
        print result

def print_area(area):
    for row in area:
        print ''.join([str(i) for i in row])

def get_value(area, r, c, row, col):
    value = 0
    if(area[row][col] == '*'):
        return '*'

    # need to check cells around the current cell
    # start with the one to the right and go counter clock-wise
    if((col + 1) < c and area[row][col + 1] == '*'):
        value += 1

    if(row > 0 and (col + 1) < c and area[row - 1][col + 1] == '*'):
        value += 1

    if(row > 0 and area[row - 1][col] == '*'):
        value += 1

    if(row > 0 and col > 0 and area[row - 1][col - 1] == '*'):
        value += 1

    if(col > 0 and area[row][col - 1] == '*'):
        value += 1

    if((row + 1) < r and col > 0 and area[row + 1][col - 1] == '*'):
        value += 1

    if((row + 1) < r and area[row + 1][col] == '*'):
        value += 1

    if((row + 1) < r and (col + 1) < c and area[row + 1][col + 1] == '*'):
        value += 1
    return value

def copy_area(area, r, c):
    result = []
    for row in xrange(r):
        result += [['X'] * c]

    for row in xrange(r):
        for col in xrange(c):
            result[row][col] = area[row][col]
    return result

def check_click(area, r, c, m, check_r, check_c):

    if(area[0] == 'Impossible'):
        return

    new_area = check_cell(area, r, c, check_r, check_c)

    opened_cells = 0
    for row in xrange(r):
        for col in xrange(c):
            if(new_area[row][col] >= 0 and new_area[row][col] <= 8):
                opened_cells += 1

    if((opened_cells + m) != (r * c)):
        print '=' * 75
        print 'opened cells', opened_cells, 'mines', m, 'unknown cells', (r * c) - opened_cells - m

        print_area(area)

        print '-' * 75

        print_area(new_area)

        print '=' * 75


def check_cell(area, r, c, row, col):

    new_area = copy_area(area, r, c)

    if(area[row][col] <= 8):
        return new_area

    cell_value = get_value(area, r, c, row, col)
    if(cell_value > 8):
        return area
    elif(cell_value > 0):
        new_area[row][col] = cell_value
    elif(cell_value == 0):
        new_area[row][col] = 0

        # open all neighbouring cells
        if((col + 1) < c):
            new_area = check_cell(new_area, r, c, row, col + 1)

        if(row > 0 and (col + 1) < c):
            new_area = check_cell(new_area, r, c, row - 1, col + 1)

        if(row > 0):
            new_area = check_cell(new_area, r, c, row - 1, col)

        if(row > 0 and col > 0):
            new_area = check_cell(new_area, r, c, row - 1, col - 1)

        if(col > 0):
            new_area = check_cell(new_area, r, c, row, col - 1)

        if((row + 1) < r and col > 0):
            new_area = check_cell(new_area, r, c, row + 1, col - 1)

        if((row + 1) < r):
            new_area = check_cell(new_area, r, c, row + 1, col)

        if((row + 1) < r and (col + 1) < c):
            new_area = check_cell(new_area, r, c, row + 1, col + 1)

    return new_area

def main():

    input_filename = 'C-small-attempt5.in'
    output_filename = 'C-small-attempt5.out'

    data = get_data(input_filename)
#     for item in data:
#         print item
#     print '-' * 75

    with open(output_filename, 'wb') as output_file:

        case_number = 0
        for item in data:
            case_number += 1

            if(case_number == 193):
                pass

            result = process_case(item['r'], item['c'], item['m'])

            print 'Case #%d:' % case_number
            print item['r'], item['c'], item['m']
            for line in result:
                print ''.join(line)

            check_rcm(result, item['r'], item['c'], item['m'])
            check_click(result,
                         item['r'],
                         item['c'],
                         item['m'],
                         0 if result[0][0] == 'c' else item['r'] - 1,
                         0 if result[0][0] == 'c' else item['c'] - 1)
            output_file.write('Case #%d:\n' % case_number)
            for line in result:
                output_file.write('%s\n' % ''.join(line))

if __name__ == "__main__":
    main()
