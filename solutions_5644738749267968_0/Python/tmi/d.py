import unittest
import sys
from collections import deque


def getProblemAnswer(S):
    noemi = [[float(x), True] for x in S[0].split(' ')]
    noemi.sort()
    ken = [[float(x), False] for x in S[1].split(' ')]
    ken.sort()
    both = ken + noemi
    both.sort()

    # war
    n = 0
    war = 0
    for elt in both:
        if elt[1]:
            n += 1
        if not elt[1]:
            if n > 0:
                war += 1
                n -= 1
    war = len(noemi) - war

    k = 0
    deceitful = 0
    for elt in both:
        if not elt[1]:
            k += 1
        if elt[1]:
            if k > 0:
                deceitful += 1
                k -= 1

    return "%s %s" % (deceitful, war)


class Tests(unittest.TestCase):

    def test_unit(self):
        self.assertEqual(getProblemAnswer(['0.5', '0.6']), '0 0')
        self.assertEqual(getProblemAnswer(['0.7', '0.6']), '1 1')
        self.assertEqual(getProblemAnswer(['0.7 0.2', '0.8 0.3']), '1 0')
        self.assertEqual(getProblemAnswer(['0.7 0.4', '0.8 0.3']), '1 1')
        self.assertEqual(getProblemAnswer(['0.9 0.2', '0.8 0.3']), '1 1')
        self.assertEqual(getProblemAnswer(['0.9 0.4', '0.8 0.3']), '2 1')
        self.assertEqual(
            getProblemAnswer(['0.1 0.2 0.3', '0.4 0.5 0.6']), '0 0'
        )
        self.assertEqual(
            getProblemAnswer(['0.1 0.2 0.45', '0.6 0.4 0.3']), '1 0'
        )
        self.assertEqual(
            getProblemAnswer(['0.5 0.1 0.9', '0.6 0.4 0.3']), '2 1'
        )
        self.assertEqual(
            getProblemAnswer(
                ['0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899',
                 '0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458']),
            '8 4'
        )

    def test_sample(self):
        path = 'd'
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
    #print [case for case in lines]
    number_test_cases = int(lines.popleft())
    print 'a total of ' + str(number_test_cases) + ' cases'

    output = []

    for case_number in range(number_test_cases):
        lines.popleft()
        input = [lines.popleft(), lines.popleft()]
        result = getProblemAnswer(input)
        output.append('Case #' + str(case_number + 1) + ': ' + result)
    output = '\n'.join(output)

    should_write = False
    should_write = True
    if should_write:
        write_answer(arg1 + '.out', output)
    else:
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
