from itertools import product


class Solution(object):
    def __init__(self):
        self._test_cases = self._read_int()

    def solve(self):
        for case_index in xrange(1, self._test_cases + 1):
            test_input = self._read_input_for_single_test_case()
            result = self._solve_single_test_case(test_input)
            self._process_single_test_case_output(case_index, result)

    def _read_input_for_single_test_case(self):
        test_input = self._read_int_array()
        return test_input

    def _check(self, dictionary, first_element, second_element, limit):
        return (first_element, second_element) not in dictionary or dictionary[(first_element, second_element)] < limit

    def _upd(self, dictionary, first_element, second_element):
        v = dictionary.get((first_element, second_element), 0)
        dictionary[(first_element, second_element)] = v + 1
        return dictionary

    def _solve_single_test_case(self, test_input):
        j, p, s, k = test_input


        jp = {}
        ps = {}
        js = {}

        result = []
        for comb in product(*[range(1, j + 1), range(1, p + 1), range(s, 0, -1)]):
            j_el, p_el, s_el = comb
            conditions = [self._check(jp, j_el, p_el, k), self._check(ps, p_el, s_el, k), self._check(js, j_el, s_el, k)]
            # print comb, conditions
            if all(conditions):
                result.append('{} {} {}'.format(j_el, p_el, s_el))
                jp = self._upd(jp, j_el, p_el)
                ps = self._upd(ps, p_el, s_el)
                js = self._upd(js, j_el, s_el)

        return str(len(result)) + '\n' + '\n'.join(result)

    @staticmethod
    def _process_single_test_case_output(case_index, result):
        print 'Case #{}: {}'.format(case_index, result)

    @staticmethod
    def _read_int():
        return int(raw_input().strip())

    @staticmethod
    def _read_int_array():
        return map(int, raw_input().strip().split())

    @staticmethod
    def _read_string():
        return raw_input().strip()

    @staticmethod
    def _read_string_array():
        return raw_input().strip().split()


solution = Solution()
solution.solve()
