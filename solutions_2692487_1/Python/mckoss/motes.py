#!/usr/bin/env python
import fileinput

DEBUG = False

test_input = """\
4
2 2
2 1
2 4
2 1 1 6
10 4
25 20 9 100
1 4
1 1 1 1""".split('\n')


def parse(lines):
    """
    >>> tests = parse(iter(test_input))
    >>> len(tests)
    4
    >>> tests[0]
    (2, [2, 1])
    """
    num_tests = int(lines.next())
    tests = []
    for _i in range(num_tests):
        start, _num_motes = [int(x) for x in lines.next().split(' ')]
        motes = [int(x) for x in lines.next().split(' ')]
        tests.append((start, motes))
    return tests


def main(lines):
    """
    >>> main(iter(test_input))
    Case #1: 0
    Case #2: 1
    Case #3: 2
    Case #4: 4
    """
    tests = parse(lines)
    for i, test in enumerate(tests):
        print "Case #%d: %d" % (i + 1, min_solve(test[0], test[1]))


def min_solve(start, motes):
    motes.sort()
    remaining = len(motes)
    if start <= 1:
        return remaining
    best = remaining
    added = 0
    for i in range(len(motes)):
        while start <= motes[i]:
            added += 1
            start += start - 1
        remaining -= 1
        start += motes[i]
        if added + remaining < best:
            best = added + remaining
    return best


if __name__ == '__main__':
    main(fileinput.input())
