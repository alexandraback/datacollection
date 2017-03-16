__author__ = 'arthurnum'

input = open('C-small-attempt2.in', 'r')
output = open('output.out', 'w')


def get_value(field, r, c, rows, cols):
    value = 0
    if (r - 1 >= 0):
        if (c - 1 >= 0) and (field[r - 1][c - 1] == '*'):
            value += 1
        if (field[r - 1][c] == '*'):
            value += 1
        if (c + 1 < cols) and (field[r - 1][c + 1] == '*'):
            value += 1
    if (c - 1 >= 0) and (field[r][c - 1] == '*'):
            value += 1
    if (c + 1 < cols) and (field[r][c + 1] == '*'):
            value += 1
    if (r + 1 < rows):
        if (c - 1 >= 0) and (field[r + 1][c - 1] == '*'):
            value += 1
        if (field[r + 1][c] == '*'):
            value += 1
        if (c + 1 < cols) and (field[r + 1][c + 1] == '*'):
            value += 1
    return value


def reveal(field, r, c, rows, cols):
    if field[r][c] == '.':
        field[r][c] = 'o'
        if get_value(field, r, c, rows, cols) == 0:
            if (r - 1 >= 0):
                if (c - 1 >= 0):
                    reveal(field, r - 1, c - 1, rows, cols)
                reveal(field, r - 1, c, rows, cols)
                if (c + 1 < cols):
                    reveal(field, r - 1, c + 1, rows, cols)
            if (c - 1 >= 0):
                reveal(field, r, c - 1, rows, cols)
            if (c + 1 < cols):
                reveal(field, r, c + 1, rows, cols)
            if (r + 1 < rows):
                if (c - 1 >= 0):
                    reveal(field, r + 1, c - 1, rows, cols)
                reveal(field, r + 1, c, rows, cols)
                if (c + 1 < cols):
                    reveal(field, r + 1, c + 1, rows, cols)


def out_field(field):
    for row in field:
        output.write("%s\n" % (''.join(row)))


cases = int(input.readline())

for case in range(cases):
    initial_values = [int(x) for x in input.readline().split()]
    rows = initial_values[0]
    cols = initial_values[1]
    filled_rows = filled_cols = 0
    mines = initial_values[2]
    free_space = counter = rows * cols - mines
    field = []


    for r in range(rows):
        field.append(['.' for c in range(cols)])

    while mines > 0:
        if rows - filled_rows > cols - filled_cols:
            if mines >= cols - filled_cols:
                for x in range(cols - filled_cols):
                    field[filled_rows][filled_cols + x] = '*'
                    mines -= 1
            else:
                if cols - filled_cols - mines == 1:
                    for x in range(mines - 1):
                        field[filled_rows][filled_cols + x] = '*'
                        mines -= 1
                else:
                    for x in range(mines):
                        field[filled_rows][filled_cols + x] = '*'
                        mines -= 1
            filled_rows += 1
        else:
            if mines >= rows - filled_rows:
                for x in range(rows - filled_rows):
                    field[filled_rows + x][filled_cols] = '*'
                    mines -= 1
            else:
                if rows - filled_rows - mines == 1:
                    for x in range(mines - 1):
                        field[filled_rows + x][filled_cols] = '*'
                        mines -= 1
                else:
                    for x in range(mines):
                        field[filled_rows + x][filled_cols] = '*'
                        mines -= 1
            filled_cols += 1

    is_possible = False

    for r in reversed(range(rows)):
        for c in reversed(range(cols)):
            work_field = []
            for row in field:
                work_field.append(row[:])
            reveal(work_field, r, c, rows, cols)
            revealed = 0
            for row in work_field:
                for char in row:
                    if char == 'o':
                        revealed += 1
            if revealed == counter:
                is_possible = True
                field[r][c] = 'c'
            if is_possible:
                break
        if is_possible:
            break

    output.write("Case #%d:\n" % (case + 1))
    if is_possible:
        out_field(field)
    else:
        output.write("Impossible\n")


input.close()
output.close()



