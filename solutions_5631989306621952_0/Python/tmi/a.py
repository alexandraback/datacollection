import unittest

should_test = False
problem_name = 'A'


class TestFallAsleep(unittest.TestCase):

    def test(self):
        self.assertEqual('CAB', solve_it('CAB'))
        self.assertEqual('MJA', solve_it('JAM'))
        self.assertEqual('OCDE', solve_it('CODE'))
        self.assertEqual('BBAAA', solve_it('ABAAB'))
        self.assertEqual('CCCABBBAB', solve_it('CABCBBABC'))
        self.assertEqual('CCCBAABAB', solve_it('ABCABCABC'))
        self.assertEqual('ZXCASDQWE', solve_it('ZXCASDQWE'))


def solve_it(S):
    current = S[0]
    for char in S[1:]:
        if char < current[0]:
            current = current + char
        else:
            current = char + current
    return current


if __name__ == '__main__':
    if should_test:
        unittest.main()
    else:
        # file_name = '%s-large' % problem_name
        file_name = '%s-small-attempt0' % problem_name
        with open('%s.in' % file_name, 'r') as cases_in:
            with open('%s.out' % file_name, 'w') as cases_out:
                total_cases = int(cases_in.next()[:-1])
                case_number = 0
                for case_str in cases_in:
                    case_number += 1
                    case_input = case_str[:-1]
                    case_output = 'Case #%s: %s' % (case_number, solve_it(case_input))
                    print case_output
                    cases_out.write('%s\n' % case_output)
