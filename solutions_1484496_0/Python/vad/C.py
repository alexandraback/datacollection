import sys
from datetime import datetime

f = None
START = datetime.now()

def read_int():
    return int(f.readline())

def read_ints():
    return map(int, f.readline().split())

def read_word():
    return f.readline().strip()

def char_range(start, end):
    return [chr(i) for i in range(ord(start), ord(end) + 1)]

############################################################################

def solve(ints):
    from collections import defaultdict
    from itertools import combinations, chain

    def my_combinations(ints):
        return chain.from_iterable(combinations(ints, l) for l in xrange(1, len(ints)))

    sums = defaultdict(set)
    for t in my_combinations(ints):
        sum_t = sum(t)
        sums_t = sums[sum_t]
        sums_t.add(t)
        if len(sums_t) == 2:
            return tuple(sums_t)


def main():
    global f

    with open(sys.argv[1]) as f:
        t = read_int()

        for index in range(t):
            print >>sys.stderr, 'Working on case #', index + 1, datetime.now() - START

            ints = read_ints()
            n, ints = ints[0], ints[1:]

            result = solve(ints)

            print 'Case #{0}:'.format(index + 1)
            if result:
                print ' '.join(map(str, result[0]))
                print ' '.join(map(str, result[1]))
            else:
                print 'Impossible'


if __name__ == '__main__':
    main()
