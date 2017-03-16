

def all_possible_scores(pattern):
    if len(pattern) == 1:
        if pattern == '?':
            for i in xrange(10):
                yield i
        else:
            yield int(pattern)
    else:
        if pattern[-1] == '?':
            for x in all_possible_scores(pattern[:-1]):
                for i in xrange(10):
                    yield x * 10 + i
        else:
            for x in all_possible_scores(pattern[:-1]):
                yield x * 10 + int(pattern[-1])


def find_min_diff_small(p1, p2):
    big = 1000000
    diff = big
    s1 = big
    s2 = big
    for x1 in all_possible_scores(p1):
        for x2 in all_possible_scores(p2):
            if abs(x1 - x2) < diff:
                diff = abs(x1 - x2)
                s1 = x1
                s2 = x2
            elif abs(x1 - x2) == diff:
                if (x1 < s1) or ((s1 == x1) and (x2 < s2)):
                    diff = abs(x1 - x2)
                    s1 = x1
                    s2 = x2
    p_len = len(p1)
    return ('{0:0=%dd} {1:0=%dd}' % (p_len, p_len)).format(s1, s2)

INPUT = 'B-small-attempt0.in'
OUTPUT = 'B-small-attempt0.out'

# INPUT = 'B-test.in'
# OUTPUT = 'B-test.out'


with open(INPUT, 'r') as fin:
    T = int(fin.readline())
    with open(OUTPUT, 'w') as fout:
        for i in xrange(1, T + 1):
            # get input
            p1, p2 = fin.readline().strip().split(' ')
            fout.write('Case #{}: {}\n'.format(i, find_min_diff_small(p1, p2)))
