import sys


class Configuration(object):

    def __init__(self, r, c, m):
        self.r = r
        self.c = c
        self.m = m
        self.free_cells = r * c - m

    def __str__(self):
        return self.to_string()

    def to_string(self):
        raise NotImplementedError


def layout_configuration(raw_configuration, r, c):
    output = []
    for i in range(r):
        output.append(raw_configuration[i * c:(i + 1) * c])
        output.append('\n')

    return ''.join(output)


def transpose_layout(layout):
    matrix = layout.strip().split('\n')
    r = len(matrix)
    c = len(matrix[0])

    result = ['X'] * r * c

    for i, row in enumerate(matrix):
        for j, column in enumerate(row):
            result[j*r + i] = column
    return layout_configuration(''.join(result), c, r)


class SingleFreeCellConfiguration(Configuration):

    def to_string(self):
        assert self.free_cells == 1
        output_data = 'c' + '*'*self.m
        return layout_configuration(output_data, self.r, self.c)


class AllFreeCellConfiguration(Configuration):

    def to_string(self):
        assert self.m == 0
        output_data = 'c' + '.'*(self.r * self.c - 1)
        return layout_configuration(output_data, self.r, self.c)


class StripConfiguration(Configuration):

    def to_string(self):
        assert self.r == 1 or self.c == 1
        output_data = ['c']
        for i in range(self.free_cells - 1):
            output_data.append('.')

        for i in range(self.m):
            output_data.append('*')

        return layout_configuration(''.join(output_data), self.r, self.c)


class DoubleStripConfiguration(Configuration):

    def to_string(self):
        assert self.r == 2 or self.c == 2
        assert self.free_cells % 2 == 0 and self.free_cells >= 4

        output_data = ['c']

        if self.r == 2:
            half_of_free_cells = self.free_cells // 2
            half_of_mines = self.m // 2
            output_data.append('.' * (half_of_free_cells - 1))
            output_data.append('*' * half_of_mines)
            output_data.append('.' * half_of_free_cells)
            output_data.append('*' * half_of_mines)
        else:
            assert self.c == 2
            output_data.append('.' * (self.free_cells - 1))
            output_data.append('*' * self.m)

        return layout_configuration(''.join(output_data), self.r, self.c)


class GenericConfiguration(Configuration):

    def to_string(self):
        r, c = self.r, self.c

        assert self.free_cells >= 4 and self.free_cells not in (5, 7)
        assert self.r >= 3 and self.c >= 3
        cells_left = r * c

        output_data = ['c']

        if self.free_cells < 2*c:
            free_per_row = self.free_cells // 2
            if self.free_cells % 2 == 1:
                free_per_row -= 1

            output_data.append('.' * (free_per_row - 1))
            output_data.append('*' * (c - free_per_row))
            output_data.append('.' * (free_per_row))
            output_data.append('*' * (c - free_per_row))
            cells_left -= 2 * c

            if self.free_cells % 2 == 1:
                output_data.append('...')
                cells_left -= 3

        elif self.free_cells == 2*c + 1:
            free_per_row = c - 1

            output_data.append('.' * (free_per_row - 1))
            output_data.append('*' * (c - free_per_row))
            output_data.append('.' * (free_per_row))
            output_data.append('*' * (c - free_per_row))
            cells_left -= 2 * c

            output_data.append('...')
            cells_left -= 3
        else:
            full_rows, free_cells_left = divmod(self.free_cells, c)

            if free_cells_left == 1:
                output_data.append('.' * (full_rows * c - 2))
                output_data.append('*..')
                cells_left -= full_rows * c + 2
            else:
                output_data.append('.' * (full_rows * c - 1))
                cells_left -= full_rows * c
                output_data.append('.' * free_cells_left)
                cells_left -= free_cells_left

        output_data.append('*' * cells_left)

        layout = layout_configuration(''.join(output_data), r, c)
        return layout


def get_perfect_configuration(r, c, m):
    free_cells = r * c - m

    if m == 0:
        return AllFreeCellConfiguration(r, c, m)

    if free_cells <= 0:
        return None

    if free_cells == 1:
        return SingleFreeCellConfiguration(r, c, m)

    if r == 1 or c == 1:
        return StripConfiguration(r, c, m)

    if free_cells < 4:
        return None

    # free_cells >= 4 AND r > 1 AND c > 1

    if r == 2 or c == 2:
        if free_cells % 2 == 0:
            return DoubleStripConfiguration(r, c, m)
        else:
            return None

    if free_cells in (5, 7):
        return None

    return GenericConfiguration(r, c, m)


def print_case_result(n, configuration, out_fp):
    out_fp.write('Case #%d:\n' % n)
    if configuration is not None:
        out_fp.write(str(configuration))
    else:
        out_fp.write('Impossible\n')


def read_input(path):
    with open(path) as fp:
        # skip T, trust Google's input data
        fp.readline()
        for line in fp:
            # R, C, M
            yield map(int, line.split(' '))



if __name__ == '__main__':
    input_path = sys.argv[1]
    if len(sys.argv) == 3:
        output_path = sys.argv[2]
        out_fp = open(output_path, 'w')
    else:
        out_fp = sys.stdout
    for i, test_case in enumerate(read_input(input_path)):
        r, c, m = test_case
        configuration = get_perfect_configuration(r, c, m)
        print_case_result(i + 1, configuration, out_fp)
