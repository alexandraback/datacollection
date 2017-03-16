from optparse import OptionParser
import math


def output_line(field, none_mines, c):
    line_result = []
    for column in range(c):
        line_result.append('.' if column < none_mines else '*')
    field.append(line_result)


def solve_case_parse(input_file):
    (r, c, m) = [int(i) for i in input_file.readline().split()]
    field = solve_case(r, c, m)
    if field:
        field[0][0] = 'c'
        return '\n'.join(map(lambda x: ''.join(x), field))
    else:
        return 'Impossible'


def complex_stopping_condition(r, c, m):
    return m < r and m < c and ((max(1, r - 2) * max(1, c - 2) < m) \
                                or ((c == 2 or r == 2) and m % 2 == 1))


def solve_case(r, c, m):
    fields = r * c
    neg_fields = 1
    if r > 1:
        neg_fields += 1
    if c > 1:
        neg_fields += 1
    if r > 1 and c > 1:
        neg_fields += 1
    if (fields - neg_fields < m or complex_stopping_condition(r, c, m)) and fields - m > 1:
        return None
    else:
        if m == 0:
            return [['.' for _ in range(c)] for _ in range(r)]
        if r >= c:
            if m >= c:
                field = solve_case(r - 1, c, m - c)
                if field:
                    field.append(['*' for _ in range(c)])
                    return field
                else:
                    return None
            elif m >= r:
                field = solve_case(r, c - 1, m - r)
                if field:
                    for x in field:
                        x.append('*')
                    return field
                else:
                    return None
        else:
            if m >= r:
                field = solve_case(r, c - 1, m - r)
                if field:
                    for x in field:
                        x.append('*')
                    return field
                else:
                    return None
            elif m >= c:
                field = solve_case(r - 1, c, m - c)
                if field:
                    field.append(['*' for _ in range(c)])
                    return field
                else:
                    return None

        field = [['.' for _ in range(c)] for _ in range(r)]
        mines = math.ceil(math.sqrt(m))
        set_mines = 0
        for ma in range(mines):
            for mb in range(mines):
                field[r - (ma if r <= c else mb) - 1][c - (mb if r <= c else ma) - 1] = '*'
                set_mines += 1
                if set_mines == m:
                    return field

        # field = []
        # empty_fields = fields - m
        # h = w = math.floor(math.sqrt(empty_fields))
        # if h > r or w > c or c == 1 or r == 1:
        #     if r < c:
        #         w = math.floor(empty_fields / r)
        #         h = r
        #     else:
        #         h = math.floor(empty_fields / c)
        #         w = c
        # rest = empty_fields - w * h
        # for line in range(h):
        #     output_line(field, w + (1 if rest > 0 else 0), c)
        #     if c > w:
        #         rest -= 1
        # lines_to_go = r - h
        # if rest > 0:
        #     lines_to_go -= 1
        #     output_line(field, rest, c)
        # for line in range(lines_to_go):
        #     output_line(field, 0, c)


def process_files(input_file, output_file):
    number_of_cases = int(input_file.readline())
    for case in range(number_of_cases):
        result = solve_case_parse(input_file)
        output_file.write('Case #%i:\n%s\n' % (case + 1, result))


if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option('-i', '--input', dest='inputFile',
                      help='test case file', metavar='FILE')
    parser.add_option('-o', '--output', dest='outputFile',
                      help='result file', metavar='FILE')
    (options, args) = parser.parse_args()

    if not options.inputFile or not options.outputFile:
        parser.error("options -i and -o are not optional")
    else:
        process_files(open(options.inputFile, 'r'), open(options.outputFile, 'w'))

