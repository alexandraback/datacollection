import math


def main():
    fin = open('B-large.in')
    fout = open('B-output.txt', 'w')
    num_cases = int(fin.readline().strip())

    for i in range(num_cases):
        output_string = 'Case #'+str(i+1)+": "
        range_of_values = []

        board = read_board(fin, range_of_values)
        range_of_values.sort()
        valid_rows = range(0, len(board))
        valid_cols = range(0, len(board[0]))

        for current_lowest_value in range_of_values:
            valid = analyze(board, valid_rows, valid_cols, current_lowest_value)

            if not valid:
                output_string += "NO"
                break
        else:  # called if loop terminates without a break
            output_string += "YES"
        fout.write(output_string + '\n')

    fout.close()
    fin.close()


def read_board(file, array_of_values):
    lawnsize = file.readline().strip().split()
    board = []
    for i in range(0, int(lawnsize[0])):
        line_string = file.readline().strip().split()
        line_int = []
        for char in line_string:
            intval = int(char)
            if intval not in array_of_values:
                array_of_values.append(intval)

            line_int.append(intval)

        board.append(line_int)
    return board


def analyze(board, rows, cols, lowest_value):
    modified = False
    # look at each row
    for r in rows[:]:
        is_all_lowest_value = True
        for c in cols:
            if board[r][c] != lowest_value:
                is_all_lowest_value = False
                break
        if is_all_lowest_value:  # this row is a constant value, and can be removed
            rows.remove(r)
            modified = True

    # if the rows are all clear, no need to check cols
    if rows == []:
        return True

    # look at each col
    for c in cols[:]:  # make a copy here so it iterates correctly
        is_all_lowest_value = True
        for r in rows:
            if board[r][c] != lowest_value:
                is_all_lowest_value = False
                break
        if is_all_lowest_value:  # this col is a constant value, and can be removed
            cols.remove(c)
            modified = True

    if not modified:
        return False

    # look in modified board to find any remaining instances of lowest_value

    for r in rows:
        for c in cols:
            if board[r][c] == lowest_value:
                return False
    return True

if __name__ == '__main__':
    main()
