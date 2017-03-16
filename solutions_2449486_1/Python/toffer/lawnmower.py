#!/usr/bin/env python

# Given a list of grass patterns, determine if the lawnmower can
# complete each pattern.

import sys

def read(filename):
    """Yield a "test" chunk of lines from filename."""
    first_line = None
    with open(filename, 'r') as f:
        num_tests = int(f.readline())
        for t in range(num_tests):
            num_lines = int(f.readline().split()[0])
            test = []
            for l in range(num_lines):
                test.append(f.readline())
            yield test

def munge(test_chunks):
    """
    Yield a grass pattern from raw test_chunks.

    Grass pattern data structure:
        * List of lines
        * Each line is a tuple of ints.

    """
    for chunk in test_chunks:
        yield [tuple(int(x) for x in c.split()) for c in chunk]

def fresh_grass(test):
    n = len(test)
    m = len(test[0])
    t = tuple([100 for x in range(m)])
    return [t for x in range(n)]

def mow_line(start, goal):
    """Mow start line to maximum height of goal line."""
    result = []
    max_height = max(goal)
    for elem in start:
        if elem <= max_height:
            result.append(elem) 
        else:
            result.append(max_height)
    return tuple(result)

def mow_horizontal(start, goal):
    """Mow each horizontal line in start pattern."""
    end_pattern = []
    for s, g in zip(start, goal):
        end_pattern.append(mow_line(s, g))
    return end_pattern

def mow_vertical(start, goal):
    """Mow each vertical line in start pattern."""
    # transpose 2d arrays
    t_start = zip(*start)
    t_goal = zip(*goal)
    end_pattern = mow_horizontal(t_start, t_goal)
    return zip(*end_pattern)

def format(index, result):
    """Format output properly."""
    output = "Case #%s: %s" % (index, result)
    return output


def main(argv=None):
    if argv == None:
        argv = sys.argv

    if len(argv) != 2:
        sys.stderr.write("Usage: %s <input_file>" % argv[0])
        return 2

    infile = argv[1]
    raw = read(infile)
    patterns = munge(raw)

    for index, goal in enumerate(patterns):
        result = ''
        start = fresh_grass(goal)
        while True:
            h_result = mow_horizontal(start, goal)
            if h_result == goal:
                result = 'YES'
                break
            v_result = mow_vertical(h_result, goal)
            if v_result == goal:
                result = 'YES'
                break
            if v_result == start:
                result = 'NO'
                break
            start = v_result
        print format(index + 1, result)


if __name__ == '__main__':
    sys.exit(main())
