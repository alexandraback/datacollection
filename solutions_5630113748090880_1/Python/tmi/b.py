import unittest
from collections import Counter

should_test = False
problem_name = 'B'


class TestFallAsleep(unittest.TestCase):

    def test(self):
        self.assertEqual([3, 4, 6], solve_it(3,
            [
                [1, 2, 3],
                [2, 3, 5],
                [3, 5, 6],
                [2, 3, 4],
                [1, 2, 3]
            ]
        ))


def solve_it(N, lists):
    heights = Counter()
    for l in lists:
        for s in l:
            heights[s] += 1
    missing_heights = []
    for h, c in heights.iteritems():
        if c % 2:
            missing_heights.append(h)
    return sorted(missing_heights)

if __name__ == '__main__':
    if should_test:
        unittest.main()
    else:
        file_name = '%s-large' % problem_name
        # file_name = '%s-small-attempt1' % problem_name
        with open('%s.in' % file_name, 'r') as cases_in:
            with open('%s.out' % file_name, 'w') as cases_out:
                total_cases = int(cases_in.next()[:-1])
                for case_number in xrange(total_cases):
                    N = int(cases_in.next()[:-1])
                    lists = []
                    for i in xrange(2 * N - 1):
                        case_input = cases_in.next()[:-1]
                        lists.append([int(j) for j in case_input.split(' ')])
                    out = solve_it(N, lists)
                    case_output = 'Case #%s: %s' % (case_number + 1, ' '.join([str(o) for o in out]))
                    print case_output
                    cases_out.write('%s\n' % case_output)
