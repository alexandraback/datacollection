import argparse

def main():
    args = parse_arguments()
    parse_and_solve(args.input, args.output)

def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument('input', type=argparse.FileType('r'),
                        nargs='?', default='input.txt', help='input file')
    parser.add_argument('output', type=argparse.FileType('w'),
                        nargs='?', default='output.txt', help='output file')

    return parser.parse_args()

def parse_and_solve(input, output):
    content = input.read()

    cases = parse_input(content)

    solutions = [solve(case) for case in cases]

    formatted_solutions = [format_solution(solution, i) for i, solution in enumerate(solutions)]
    joined_solutions = '\n'.join(formatted_solutions)

    output.write(joined_solutions)
    print joined_solutions

def parse_input(input):
    numbers = [int(x) for x in input.split()]
    numbers.reverse()

    cases_count = numbers.pop()

    cases =[]
    for i in xrange(cases_count):
        rows_count = numbers.pop()
        cols_count = numbers.pop()
        mines = numbers.pop()
        cases.append((rows_count, cols_count, mines))

    assert(len(numbers) == 0)

    return cases

class Stack2D:
    def __init__(self, max_rows, max_cols):
        self.max_rows = max_rows
        self.max_cols = max_cols
        self.rows = [0] * max_rows
        self.cols = [0] * max_cols

    def push_left(self, row_index):
        if self.is_row_full(row_index):
            return False

        self.cols[self.rows[row_index]] += 1
        self.rows[row_index] += 1
        return True

    def push_up(self, col_index):
        if self.is_col_full(col_index):
            return False

        self.rows[self.cols[col_index]] += 1
        self.cols[col_index] += 1

    def push_pair_left(self, row_index):
        if self.is_row_full(row_index) or \
           self.is_row_full(row_index + 1):
            return False

        self.push_left(row_index)
        self.push_left(row_index + 1)
        return True

    def push_pair_up(self, col_index):
        if self.is_col_full(col_index) or \
           self.is_col_full(col_index + 1):
            return False

        self.push_up(col_index)
        self.push_up(col_index + 1)
        return True

    def is_row_full(self, row_index):
        return self.rows[row_index] == self.max_cols

    def is_col_full(self, col_index):
        return self.cols[col_index] == self.max_rows

def stack2d_to_grid(stack):
    grid = []
    for row in stack.rows:
        grid_row = ['.'] * row + ['*'] * (stack.max_cols - row)
        grid.append(grid_row)

    return grid

def show_grid(grid):
    return '\n'.join(''.join(row) for row in grid)

def stack_to_solution(stack):
    grid = stack2d_to_grid(stack)
    grid[0][0] = 'c'
    return show_grid(grid)

#note: could refactor code to remove symmetry code duplication, but meh..
def solve(case):
    rows_count, cols_count, mines = case
    empties = rows_count * cols_count - mines

    stack = Stack2D(rows_count, cols_count)

    if cols_count == 1:
        for _ in xrange(empties):
            stack.push_up(0)
        return stack_to_solution(stack)

    if rows_count == 1:
        for _ in xrange(empties):
            stack.push_left(0)
        return stack_to_solution(stack)

    if empties == 1:
        stack.push_up(0)
        return stack_to_solution(stack)

    if empties < 4:
        return 'Impossible'

    stack.push_pair_left(0)
    stack.push_pair_left(0)
    empties -= 4

    if empties == 1 or empties == 3:
        return 'Impossible'
    if empties == 0:
        return stack_to_solution(stack)

    odd = empties % 2 != 0
    if odd:
        empties -= 1
        if rows_count == 2 or cols_count == 2:
            return 'Impossible'

    filling_rows = True
    coord = 0
    while empties > 0:
        if filling_rows:
            ok = stack.push_pair_left(coord)
            if ok:
                empties -= 2
                filling_rows = False
            else:
                while empties > 0:
                    ok = stack.push_pair_up(coord)
                    if ok:
                        empties -= 2
                    else:
                        break
                break

        else:
            ok = stack.push_pair_up(coord)
            if ok:
                empties -= 2
                filling_rows = True
            else:
                while empties > 0:
                    ok = stack.push_pair_left(coord)
                    if ok:
                        empties -= 2
                    else:
                        break
                break

    if odd:
         empties += 1
    i = 2
    while empties > 0:
        ok = stack.push_left(i)
        if ok:
            empties -= 1
        else:
            i += 1

    return stack_to_solution(stack)


def format_solution(solution, index):
    format = 'Case #%d:\n%s'
    return format % (index + 1, solution)

if __name__ == '__main__':
    main()
