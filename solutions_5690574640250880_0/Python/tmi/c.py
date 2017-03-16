import unittest
import sys
from collections import deque


def getProblemAnswer(S):
    # print '\n\n'

    lines, cols, mines = [int(x) for x in S.split()]

    # case all mines but one
    if mines == lines * cols - 1:
        table = [['*' for _ in range(cols)] for _ in range(lines)]
        table[0][0] = 'c'
        return output(table)

    table = [['.' for _ in range(cols)] for _ in range(lines)]
    table[0][0] = 'c'

    # case no mine
    if mines == 0:
        return output(table)

    # case one line or one column
    if lines == 1 or cols == 1:
        for i in range(lines - 1, -1, -1):
            for j in range(cols - 1, -1, -1):
                table[i][j] = '*'
                mines -= 1
                if mines == 0:
                    return output(table)

    # fill non danger zone
    for i in range(lines - 1, 1, -1):
        for j in range(cols - 1, 1, -1):
            table[i][j] = '*'
            mines -= 1
            if mines == 0:
                return output(table)

    limit = 1
    # remove one from non danger to fill lines or columns if needed
    if mines % 2 == 1:
        if lines > 2 and cols > 2:
            table[2][2] = '.'
            mines += 1
            limit = 2

    # fill the columns and the lines
    for i in range(lines - 1, limit, -1):
        table[i][0] = '*'
        table[i][1] = '*'
        mines -= 2
        if mines == 0:
            return output(table)
    for j in range(cols - 1, limit, -1):
        table[0][j] = '*'
        table[1][j] = '*'
        mines -= 2
        if mines == 0:
            return output(table)
    return 'Impossible'

        # print 'non_mines left: %s' % non_mines
        # print 'current_lvl: %s' % current_lvl
        # print table
    #     current_lvl += 1
    #     if current_lvl < lines:
    #         for i in range(min(current_lvl + 1, cols)):
    #             if non_mines > 0:
    #                 table[current_lvl][i] = '.'
    #                 non_mines -= 1
    #     if current_lvl < cols:
    #         for i in range(min(current_lvl, lines) - 1, -1, -1):
    #             if non_mines > 0:
    #                 table[i][current_lvl] = '.'
    #                 non_mines -= 1
    # table[0][0] = 'c'
    # print '\ndone'
    # print table

    # check if it's one click
    # next_line_is_bomb = lines > 1 and table[1][0] == '*'
    # next_col_is_bomb = cols > 1 and table[0][1] == '*'
    # next_diag_is_bomb = cols > 1 and lines > 1 and table[1][1] == '*'
    # is_only_non_bomb = lines * cols - mines == 1

    # if is_only_non_bomb or (
    #     not next_line_is_bomb and
    #     not next_col_is_bomb and
    #     not next_diag_is_bomb
    # ):
    #     return '\n'.join([''.join(x) for x in table])
    # else:
    #     return '\nImpossible'


def output(table):
    return '\n'.join([''.join(x) for x in table])


class Tests(unittest.TestCase):
    # def test_unit(self):
    #     print getProblemAnswer('3 5 4')
    #     print '\nc...*\n....*\n...**'

    def test_sample(self):
        path = 'c'
        f = open(path + '.out')
        lines = f.readlines()
        f.close()
        f = open(path + '.expected.out')
        expected_lines = f.readlines()
        f.close()
        self.assertEqual(lines, expected_lines)


def main(arg1):
    print 'opening ' + arg1
    f = open(arg1 + '.in')
    lines = f.readlines()
    f.close()
    lines = deque([case[:-1] for case in lines])
    # print [case for case in lines]
    number_test_cases = int(lines.popleft())
    print 'a total of ' + str(number_test_cases) + ' cases'

    output = []

    for case_number in range(number_test_cases):
        input = lines.popleft()
        result = getProblemAnswer(input)
        output.append('Case #' + str(case_number + 1) + ':\n' + result)
    output = '\n'.join(output)

    should_write = False
    should_write = True
    if should_write:
        write_answer(arg1 + '.out', output)
    else:
        print output
        print 'NOT WRITING ANYTHING \n'


def write_answer(name, output):
    f = open(name, 'w+')
    f.write(output)
    f.close()
    print 'ANSWERS WRITTEN\n'


if __name__ == '__main__':
    if len(sys.argv) == 2:
        sys.exit(main(sys.argv[1]))
    else:
        unittest.main()
