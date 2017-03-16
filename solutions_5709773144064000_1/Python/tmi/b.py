from __future__ import division
import math

import unittest
import sys
from collections import deque


def getProblemAnswer(S):
    cost, inc, goal = [float(x) for x in S.split()]
    time = float(0)
    gen = float(2)

    if cost > goal:
        return "{0:.7f}".format(goal / gen)

    k = goal / cost - 1 - 2 / inc
    k = int(math.ceil(k))
    for i in range(k):
        time += cost / gen
        gen += inc
    return "{0:.7f}".format(time + goal / gen)

class Tests(unittest.TestCase):

    def test_unit(self):
        self.assertEqual(getProblemAnswer('30.0 1.0 2.0'), '1.0000000')
        self.assertEqual(getProblemAnswer('30.0 2.0 100.0'), '39.1666667')
        self.assertEqual(getProblemAnswer(
            '30.50000 3.14159 1999.19990'), '63.9680013'
        )
        self.assertEqual(getProblemAnswer('500.0 4.0 2000.0'), '526.1904762')

    def test_sample(self):
        path = 'b'
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
        output.append('Case #' + str(case_number + 1) + ': ' + result)
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
