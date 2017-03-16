#!/usr/bin/env python
import fileinput
import sys
from collections import Counter

sys.setrecursionlimit(100000)

lines_per_case = 1


def solve_case(case):
    all_classes = dict((i, map(int,x.strip().split()[1:])) for i,x in enumerate(case[1:], 1))

    def find_pairs(classes, memo = None, child=None):
        if not memo:
            memo = set()
        result = False
        for cls in classes:
            for parent in all_classes[cls]:
                f = (child or cls, parent)
                if f in memo:
                    return True
                else:
                    memo.add(f)
            if len(all_classes[cls]) > 0:
                result = find_pairs(all_classes[cls], memo, child or cls)
                if result:
                    return result
        return result

    return 'Yes' if find_pairs(all_classes.iterkeys()) else 'No'

def produce_output(index, solution):
    print 'Case #{0}: {1}'.format(index, solution)


def get_test_cases(lines, n_of_lines_per_case=1):
    x = 0
    while x < len(lines):
        n_of_lines_per_case = int(lines[x].strip())
        y = x + n_of_lines_per_case + 1
        yield lines[x:y]
        x = y

if __name__ == "__main__":
    lines = []
    if(len(sys.argv) > 1):
        fn = sys.argv[1]
        with open(fn) as f:
            lines = f.readlines()
    else:
        for line in fileinput.input():
            lines.append(line)

    if len(lines) > 0:
        #nt = int(lines[0])
        for index, case in enumerate(get_test_cases(lines[1:], lines_per_case), 1):
            produce_output(index, str(solve_case(case)))
