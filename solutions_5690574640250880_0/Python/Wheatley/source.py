from math import *


START_CELL = (0, 0)


def possible_configuration(r, c, m):
    board = [['*' for _ in range(c)] for _ in range(r)]
    conf = find_configuration(r, c, r * c - m, {START_CELL}, [START_CELL])
    if conf is None:
        return None
    for x, y in conf:
        board[y][x] = '.'
    board[START_CELL[1]][START_CELL[0]] = 'c'
    return board


def find_configuration(rows, columns, num_free_cells,
                       selected_cells, frontier):
    if len(selected_cells) == num_free_cells:
        return selected_cells
    elif len(selected_cells) > num_free_cells or frontier == []:
        return None
    else:
        unselected_neighbors = neighbors(rows, columns,
            frontier[0]) - selected_cells
        conf = find_configuration(rows, columns, num_free_cells,
            selected_cells.union(unselected_neighbors),
            frontier[1:] + list(unselected_neighbors))
        if not conf is None:
            return conf
        else:
            return find_configuration(rows, columns, num_free_cells,
                selected_cells, frontier[1:])


def neighbors(rows, columns, cell):
    result = set()
    for x in range(cell[0] - 1, cell[0] + 2):
        for y in range(cell[1] - 1, cell[1] + 2):
            if is_on_board(rows, columns, (x, y)):
                result.add((x, y))
    return result


def is_on_board(rows, columns, cell):
    x, y = cell
    return x >= 0 and x < columns and y >= 0 and y < rows


with open('input') as in_file:
    with open('output', 'w') as out_file:
        num_cases = int(in_file.readline())
        for case in range(num_cases):
            r, c, m = map(int, in_file.readline().split())
            out_file.write('Case #{}:\n'.format(case + 1))
            configuration = possible_configuration(r, c, m)
            if configuration is None:
                out_file.write('Impossible\n')
            else:
                for row in configuration:
                    out_file.write(''.join(row) + '\n')