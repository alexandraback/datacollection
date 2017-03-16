from itertools import permutations
import unittest

should_test = False
problem_name = 'C'


class TestFallAsleep(unittest.TestCase):

    def test(self):
        self.assertEqual(3, solve_it([2, 2, 3, 2]))
        self.assertEqual(3, solve_it([2, 2, 3, 0]))
        self.assertEqual(4, solve_it([1, 2, 3, 0]))
        self.assertEqual(6, solve_it([i - 1 for i in [7, 8, 10, 10, 9, 2, 9, 6, 3, 3]]))
        # self.assertEqual(3, solve_it([3, 3, 4, 3]))
        # self.assertEqual(3, solve_it([3, 3, 4, 1]))
        # self.assertEqual(4, solve_it([2, 3, 4, 1]))
        # self.assertEqual(6, solve_it([7, 8, 10, 10, 9, 2, 9, 6, 3, 3]))


def is_valid(length, bffs, to_test):
    for idx, s_id in enumerate(to_test):
        current_bff = bffs[s_id]
        if not (current_bff == to_test[(idx - 1) % length] or current_bff == to_test[(idx + 1) % length]):
            return False
    return True


def solve_it(bffs):
    N = len(bffs)
    for length in xrange(N, 0, -1):
        for to_test in permutations(range(N), length):
            if is_valid(length, bffs, to_test):
                return length


#         while True:
#             next_possible = bffs[current]
#             if next_possible == current:
#                 # we found a loop
#                 import ipdb; ipdb.set_trace()
#                 new_bffs = []
#                 count += solve_it(new_bffs)
#                 max_count = max(max_count, count)
#                 break

#             if next_possible == start:
#                 max_count = max(max_count, count)
#                 break

#             if next_possible in left_students_ids:
#                 count += 1
#                 left_students_ids = left_students_ids - set([next_possible])
#                 current = next_possible
#             else:
#                 break
#     return max_count

if __name__ == '__main__':
    if should_test:
        unittest.main()
    else:
        # file_name = '%s-large' % problem_name
        file_name = '%s-small-attempt2' % problem_name
        with open('%s.in' % file_name, 'r') as cases_in:
            with open('%s.out' % file_name, 'w') as cases_out:
                total_cases = int(cases_in.next()[:-1])
                for case_number in xrange(total_cases):
                    N = int(cases_in.next()[:-1])
                    BFFs = [(int(i) - 1) for i in cases_in.next()[:-1].split(' ')]
                    if case_number < 48:
                        continue
                    out = solve_it(BFFs)
                    case_output = 'Case #%s: %s' % (case_number + 1, out)
                    print case_output
                    # cases_out.write('%s\n' % case_output)
